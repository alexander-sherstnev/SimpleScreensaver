//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include "RenderContext.h"

/** Forward declarations .*/
class BaseScene;

/**
 * Base renderer class.
 */
class Renderer
{
public:
    /**
     * Set render context.
     * @param context - New render context.
     */
    void SetContext(RenderContext& context) { _context = &context; }

    /**
     * Set delta time.
     * @param deltaTime - New amount of time from previous call.
     */
    void SetDeltaTime(float deltaTime) { _deltaTime = deltaTime; }

    /**
     * Set viewport size.
     * @param size - New viewport size.
     */
    void SetViewportSize(const Size& size) { _viewportSize = size; }

    /**
     * @return Current aspect ratio
     */
    inline float GetAspectRatio() const
    {
        return (_viewportSize.GetWidth() > _viewportSize.GetHeight()) ?
                    (_viewportSize.GetWidth() / (float)_viewportSize.GetHeight()) :
                    (_viewportSize.GetHeight() / (float)_viewportSize.GetWidth());
    };

    /**
     * Render scene
     * @param scene - Scene which should be rendered.
     */
    virtual void Render(BaseScene* scene) = 0;

protected:
    /** Reference to the current render context. */
    RenderContext* _context;

    /** Amount of time from previous call. */
    float _deltaTime;

    /** Viewport size. */
    Size _viewportSize;
};