//
// Created by Alexander Sherstnev on 5/19/18.
//

#include "Scene/DefaultScene.h"

void DefaultScene::Update(float deltaTime)
{
    for (auto& entity : _entities)
    {
        entity->Update(deltaTime);
    }
}

void DefaultScene::AddEntity(std::shared_ptr<Entity> entity)
{
    _entities.push_back(std::move(entity));
}

const std::vector<std::shared_ptr<Entity>>& DefaultScene::GetVisibleEntities() const
{
    return _entities;
}