//
// Created by Alexander Sherstnev on 5/19/18.
//

#include "Render/SoftwareRenderer.h"
#include "Core.h"
#include "Scene/Entity.h"
#include "Scene/Camera.h"
#include "Scene/BaseScene.h"

Point VectorToScreenPoint(const Vector& v, float screenWidth, float screenHeight)
{
    float x = v.x / v.z;
    float y = v.y / v.z;
    float halfSW = screenWidth * 0.5f;
    float halfSH = screenHeight * 0.5f;
    float xn = x * halfSW + halfSW;
    float yn = -y * halfSH + halfSH;

    return Point(xn, yn);
}

void SoftwareRenderer::Render(BaseScene* scene)
{
    if (_context == nullptr || scene == nullptr)
    {
        return;
    }

    _context->SetBackgroundColor(scene->GetBackgroundColor());
    _context->Clear();

    auto camera = scene->GetActiveCamera();
    const auto& visibleEntities = scene->GetVisibleEntities();

    Matrix perspective;
    perspective.Perspective(camera->FOV, GetAspectRatio(), camera->zNear, camera->zFar);

    Matrix MVP;
    MVP = perspective * camera->transform;

    _batches.clear();
    for (const auto& entity : visibleEntities)
    {
        MVP = MVP * entity->transform;
        for (int i = 0; i < entity->mesh->indicies.size(); i += 3)
        {
            Triangle t;
            int i0 = entity->mesh->indicies[i + 0] * 3;
            int i1 = entity->mesh->indicies[i + 1] * 3;
            int i2 = entity->mesh->indicies[i + 2] * 3;

            t.v0 = MVP * Vector(entity->mesh->vertices[i0 + 0],
                                 entity->mesh->vertices[i0 + 1],
                                 entity->mesh->vertices[i0 + 2]);
            t.v1 = MVP * Vector(entity->mesh->vertices[i1 + 0],
                                 entity->mesh->vertices[i1 + 1],
                                 entity->mesh->vertices[i1 + 2]);
            t.v2 = MVP * Vector(entity->mesh->vertices[i2 + 0],
                                 entity->mesh->vertices[i2 + 1],
                                 entity->mesh->vertices[i2 + 2]);

            DrawBatch batch;
            batch.triangle = t;
            batch.fillColor = entity->mesh->color;
            batch.outlineColor = entity->mesh->outline;

            _batches.push_back(batch);
        }
    }

    // Sort batches
    std::sort(_batches.begin(), _batches.end());

    // Draw triangles
    Point triangle[3];
    float screenWidth = _viewportSize.GetWidth();
    float screenHeight = _viewportSize.GetHeight();
    for (auto& batch : _batches)
    {
        triangle[0] = VectorToScreenPoint(batch.triangle.v0, screenWidth, screenHeight);
        triangle[1] = VectorToScreenPoint(batch.triangle.v1, screenWidth, screenHeight);
        triangle[2] = VectorToScreenPoint(batch.triangle.v2, screenWidth, screenHeight);

        _context->SetOutlineColor(batch.outlineColor);
        _context->SetFillColor(batch.fillColor);
        _context->DrawPolygon(triangle, 3);
    }
}