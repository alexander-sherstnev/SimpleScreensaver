//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include "RenderContext.h"
#include <vector>


/**
 * Mesh.
 */
struct Mesh
{
public:
    /** Mesh vertices. */
    std::vector<float> vertices;

    /** Mesh indicies. */
    std::vector<int> indicies;

    /** Mesh fill color. */
    Color color;

    /** Mesh outline color. */
    Color outline;
};
