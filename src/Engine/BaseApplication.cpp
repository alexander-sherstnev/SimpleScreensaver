//
// Created by Alexander Sherstnev on 5/19/18.
//

#include "BaseApplication.h"
#include "Render/SoftwareRenderer.h"

bool BaseApplication::OnInitialize()
{
    _renderer = std::make_shared<SoftwareRenderer>();
    _mainLoop = std::make_shared<MainLoop>(MainLoop(this));

    return true;
}

void BaseApplication::OnTick(RenderContext& context)
{
    _renderer->SetContext(context);
    _mainLoop->TickOneFrame();
}

void BaseApplication::OnSize(const Size& size)
{
    _renderer->SetViewportSize(size);
}
