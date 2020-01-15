//
// Created by Alexander Sherstnev on 5/19/18.
//

#include "Application.h"
#include "BoxEntity.h"

bool Application::OnInitialize()
{
    BaseApplication::OnInitialize();

    SetTitle("SimpleScreensaver v1.0.0 Copyright 2018 by Alexander Sherstnev");
    SetPosition(Point(50, 50));
    SetSize(Size(800, 600));

    auto camera = std::make_shared<Camera>();
    camera->transform.LookAt(Vector(-6.0f, 0.0f, 0.0f), Vector(0.0f, 0.0f, 0.0f), Vector(0.0f, 0.0f, 1.0f));
    camera->FOV = 45.0f;
    camera->zNear = 0.001f;
    camera->zFar = 1000.0f;

    auto boxEntity = std::make_shared<BoxEntity>();
    auto boxScene = std::make_shared<Scene>();
    boxScene->SetBackgroundColor(Color(0.0f, 0.0f, 0.0f));
    boxScene->SetActiveCamera(camera);

    boxScene->AddEntity(boxEntity);

    SetActiveScene(boxScene);
    return true;
}

#ifdef USE_WX
    IMPLEMENT_APP(Application);
#endif