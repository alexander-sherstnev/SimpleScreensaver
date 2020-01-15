//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include "Engine.h"

class BoxEntity : public Entity
{
public:
    /**
     * Initialize box entity.
     */
    BoxEntity();

    // Begin Entity Interface
    void Update(float deltaTime) override;
    // End Entity Interface
};