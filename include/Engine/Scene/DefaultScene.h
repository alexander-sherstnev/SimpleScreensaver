//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include "BaseScene.h"

/**
 * Default scene implementation.
 */
class DefaultScene : public BaseScene
{
public:
    // Begin BaseScene Interface
    void Update(float deltaTime) override;
    void AddEntity(std::shared_ptr<Entity> entity) override;
    const std::vector<std::shared_ptr<Entity>>& GetVisibleEntities() const override;
    // End BaseScene Interface

private:
    /** Scene entities. */
    std::vector<std::shared_ptr<Entity>> _entities;
};
