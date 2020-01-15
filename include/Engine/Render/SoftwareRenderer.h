//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include "Renderer.h"
#include <vector>

/**
 * Triangle.
 */
struct Triangle
{
public:
    /**
     * @return Z average
     */
    float ZAvg() const { return (v0.z + v1.z + v2.z) / 3.0f; }

    /** Triangle vertices. */
    Vector v0;
    Vector v1;
    Vector v2;
};

/**
 * One draw triangle batch
 */
struct DrawBatch
{
public:
    /**
     * Custom comparator.
     */
    inline bool operator<(const DrawBatch& r) const { return r.triangle.ZAvg() <= triangle.ZAvg(); }

    /** Triangle. */
    Triangle triangle;

    /** Fill color. */
    Color fillColor;

    /** Outline color. */
    Color outlineColor;
};

/** Forward declarations .*/
class BaseScene;

class SoftwareRenderer : public Renderer
{
public:
    // Begin Renderer Interface
    void Render(BaseScene* scene) override;
    // End Renderer Interface

private:
    /** Draw batches. */
    std::vector<DrawBatch> _batches;
};