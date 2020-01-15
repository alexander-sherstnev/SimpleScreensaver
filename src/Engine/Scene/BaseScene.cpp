//
// Created by Alexander Sherstnev on 5/19/18.
//

#include "Scene/BaseScene.h"
#include "Render/Renderer.h"

void BaseScene::Render(Renderer* renderer, float deltaTime)
{
    if (renderer != nullptr)
    {
        renderer->SetDeltaTime(deltaTime);
        renderer->Render(this);
    }
}
