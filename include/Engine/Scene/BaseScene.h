//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include "Render/RenderContext.h"
#include "Camera.h"
#include "Entity.h"
#include <vector>

/** Forward declarations. */
class Renderer;

/**
 * Base scene class.
 */
class BaseScene
{
public:
    /**
     * Update scene.
     * @param deltaTime - Amount of time from previous call.
     */
    virtual void Update(float deltaTime) = 0;

    /**
     * Render scene.
     * @param renderer - Current renderer.
     * @param deltaTime - Amount of time from previous call.
     */
    virtual void Render(Renderer* renderer, float deltaTime);

    /**
     * Add entity to the scene.
     * @param mesh - Entity.
     */
    virtual void AddEntity(std::shared_ptr<Entity> entity) = 0;

    /**
     * @return Visible entities.
     */
    virtual const std::vector<std::shared_ptr<Entity>>& GetVisibleEntities() const = 0;

    /**
     * Set scene background clear color.
     * @param color - New color.
     */
    void SetBackgroundColor(const Color& color) { _backgroundColor = color; }

    /**
     * @return Scene background color.
     */
    Color GetBackgroundColor() const { return _backgroundColor; }

    /**
     * Set scene active camera.
     * @param camera - New camera.
     */
    void SetActiveCamera(std::shared_ptr<Camera> camera) { _camera = camera; }

    /**
     * @return Current camera.
     */
    Camera* GetActiveCamera() const { return _camera.get(); }

private:
    /** Background clear color. */
    Color _backgroundColor;

    /** Camera. */
    std::shared_ptr<Camera> _camera;
};
