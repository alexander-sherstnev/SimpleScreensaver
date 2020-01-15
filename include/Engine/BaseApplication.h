//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include "Core.h"
#include "Render/RenderContext.h"
#include "Render/Renderer.h"
#include "MainLoop.h"
#include "Scene/BaseScene.h"

/**
 * Base Application.
 */
class BaseApplication
{
public:
    /**
     * Set application title.
     * @param title - Application title.
     */
    virtual void SetTitle(const String& title) = 0;

    /**
     * Set application position.
     * @param title - Application position.
     */
    virtual void SetPosition(const Point& position) = 0;

    /**
     * Set application size.
     * @param title - Application size.
     */
    virtual void SetSize(const Size& size) = 0;

    /**
     * @return Current active renderer.
     */
    virtual Renderer* GetActiveRenderer() const { return _renderer.get(); }

    /**
     * Set new current active scene.
     * @param scene - New scene.
     */
    virtual void SetActiveScene(std::shared_ptr<BaseScene> scene) { _scene = scene; }

    /**
     * @return Current active scene.
     */
    virtual BaseScene* GetActiveScene() const { return _scene.get(); }

protected:
    /**
     * Initialize application.
     * This is method which should be override in child classes for custom initialization.
     * @returns True if initialized correctly
     */
    virtual bool OnInitialize();

    /**
     * Deinitialize application.
     * @return Exit code.
     */
    virtual int OnDeinitialize() { return 0; }

    /**
     * One tick event.
     * @param context - Render context.
     */
    virtual void OnTick(RenderContext& context);

    /**
     * Resize event handler.
     * @param size - New size.
     */
    virtual void OnSize(const Size& size);

private:
    /** Reference to renderer. */
    std::shared_ptr<Renderer> _renderer;

    /** Reference to main loop. */
    std::shared_ptr<MainLoop> _mainLoop;

    /** Reference to scene. */
    std::shared_ptr<BaseScene> _scene;
};
