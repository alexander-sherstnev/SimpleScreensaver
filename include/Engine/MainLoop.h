//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include <chrono>

/** Forward declarations. */
class BaseApplication;

/**
 * Abstraction over main loop.
 */
class MainLoop
{
public:
    /**
     * Default constructor.
     * @param application - Application reference.
     */
    MainLoop(BaseApplication* application);

    /**
     * Tick one frame.
     */
    virtual void TickOneFrame();

protected:
    /** Reference to the application. */
    BaseApplication* _application;

    /** Previous tick call time point. */
    std::chrono::high_resolution_clock::time_point _prevTimePoint;
};
