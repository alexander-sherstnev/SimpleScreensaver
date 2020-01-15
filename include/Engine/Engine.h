//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include "Core.h"
#include "Scene/Camera.h"
#include "Scene/Entity.h"
#include "Scene/BaseScene.h"
#include "Scene/DefaultScene.h"
#include "MainLoop.h"
#include "BaseApplication.h"

typedef DefaultScene Scene;

#ifdef USE_WX
    #include "wx/wxBaseApplication.h"
    typedef wxBaseApplication BaseApp;
#endif
