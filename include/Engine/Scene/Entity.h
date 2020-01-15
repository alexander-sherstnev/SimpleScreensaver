//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include "Render/Mesh.h"
#include "Math/Matrix.h"

/**
 * Main scene entity.
 */
class Entity
{
public:
    /**
     * Update entity.
     * @param deltaTime - Amount of time from previous call.
     */
    virtual void Update(float deltaTime) {};

    /** Entity mesh. */
    std::shared_ptr<Mesh> mesh;

    /** Entity transform. */
    Matrix transform;
};
