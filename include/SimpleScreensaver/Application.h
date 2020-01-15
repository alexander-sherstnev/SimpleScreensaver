//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include "Engine.h"

class Application : public BaseApp
{
protected:
    // Begin BaseApplication Interface
    bool OnInitialize() override;
    // End BaseApplication Interface
};

#ifdef USE_WX
    DECLARE_APP(Application);
#endif
