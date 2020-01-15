//
// Created by Alexander Sherstnev on 5/19/18.
//

#include "BoxEntity.h"

BoxEntity::BoxEntity()
{
    mesh = std::make_shared<Mesh>();
    mesh->vertices = {
            // front
            -1.0f, -1.0f, 1.0f,
            1.0f, -1.0f, 1.0f,
            1.0f,  1.0f, 1.0f,
            -1.0f,  1.0f, 1.0f,
            // back
            -1.0f, -1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,
            1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f
    };
    mesh->indicies = {
            // front
            0, 1, 2,
            2, 3, 0,
            // right
            1, 5, 6,
            6, 2, 1,
            // back
            7, 6, 5,
            5, 4, 7,
            // left
            4, 0, 3,
            3, 7, 4,
            // bottom
            4, 5, 1,
            1, 0, 4,
            // top
            3, 2, 6,
            6, 7, 3
    };
    mesh->color = Color(0.0f, 0.0f, 0.0f, 0.0f);
    mesh->outline = Color(0.0f, 1.0f, 0.0f, 1.0f);

    transform.Scale(2.0f, 1.0f, 1.0f);
}

void BoxEntity::Update(float deltaTime)
{
    transform.Rotate(85.0f * deltaTime, Vector(1.0f, 0.0f, 0.0f));
    transform.Rotate(35.0f * deltaTime, Vector(0.0f, 1.0f, 0.0f));
    transform.Rotate(55.0f * deltaTime, Vector(0.0f, 0.0f, 1.0f));
}