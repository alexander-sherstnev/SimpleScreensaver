//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include "Core.h"

/**
 * Base color class.
 */
struct Color
{
public:
    /**
     * Default constructor.
     */
    Color() : Color(0.0f, 0.0f, 0.0f) {};

    /**
     * Initialize color with specified channels values.
     * @param red - Red channel
     * @param green - Green channel
     * @param blue - Blue channel
     * @param alpha - Alpha
     */
    Color(float red, float green, float blue, float alpha = 1.0f)
        : r(red),
          g(green),
          b(blue),
          a(alpha)
    {
    };

    /** Color components. */
    float r;
    float g;
    float b;
    float a;
};

/**
 * Render context.
 */
class RenderContext
{
public:
    /**
     * Clears the context.
     */
    virtual void Clear() = 0;

    /**
     * Set background color.
     * @param color - Background color.
     */
    virtual void SetBackgroundColor(const Color& color) = 0;

    /**
     * Set outline color.
     * @param color - Outline color.
     */
    virtual void SetOutlineColor(const Color& color) = 0;

    /**
     * Set fill color.
     * @param color - Fill color.
     */
    virtual void SetFillColor(const Color& color) = 0;

    /**
     * Draw point.
     * @param point - Point.
     */
    virtual void DrawPoint(const Point& point) = 0;

    /**
     * Draw polygon.
     * @param points - Points
     * @param size - Size
     */
    virtual void DrawPolygon(const Point points[], int size) = 0;
};
