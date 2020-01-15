//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include "Math/Matrix.h"

class Camera
{
public:
    /** Camera transform. */
    Matrix transform;

    /** Camera FOV value. */
    float FOV;

    /** Camera z near plane. */
    float zNear;

    /** Camera z far plane. */
    float zFar;
};
