//
// Created by Alexander Sherstnev on 5/19/18.
//

#include "MainLoop.h"
#include "Scene/BaseScene.h"
#include "BaseApplication.h"

MainLoop::MainLoop(BaseApplication* application) : _application(application)
{
    _prevTimePoint = std::chrono::high_resolution_clock::now();
}

void MainLoop::TickOneFrame()
{
    if (_application == nullptr)
    {
        return;
    }

    auto nowTimePoint = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<float>>(nowTimePoint - _prevTimePoint);
    float deltaTime = duration.count();
    _prevTimePoint = nowTimePoint;

    BaseScene* scene = _application->GetActiveScene();
    if (scene != nullptr)
    {
        scene->Update(deltaTime);
        scene->Render(_application->GetActiveRenderer(), deltaTime);
    }
}