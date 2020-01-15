//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include <cmath>

/**
 * Vector 3D.
 */
struct Vector
{
public:
    /**
     * Initialize zero vector.
     */
    Vector() : x(0), y(0), z(0) {};

    /**
     * Initialize vector with specified values
     * @param x - X component value.
     * @param y - Y component value.
     * @param z - Z component value.
     */
    Vector(float x, float y, float z) : x(x), y(y), z(z) {};

    /**
     * @return Vector length.
     */
    float Length() const
    {
        return sqrtf(x * x + y * y + z * z);
    };

    /**
     * Normalize vector.
     */
    Vector& Normalize()
    {
        float xxyyzz = x*x + y*y + z*z;
        float invLength = 1.0f / (xxyyzz == 0.0f ? 1.0f : sqrtf(xxyyzz));
        x *= invLength;
        y *= invLength;
        z *= invLength;

        return *this;
    };

    /**
     * Cross product of vectors.
     */
    Vector Cross(const Vector& rhs) const
    {
        return Vector(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
    };

    /**
     * @return Dot product
     */
    float Dot(const Vector& v) const
    {
        return (x * v.x + y * v.y + z * v.z);
    };

    /**
     * @return Unary operator (negate)
     */
    Vector operator-() const
    {
        return Vector(-x, -y, -z);
    };

    /**
     * @return Substract vector
     */
    Vector operator-(const Vector& rhs) const
    {
        return Vector(x - rhs.x, y - rhs.y, z - rhs.z);
    };

    /** Vector's components. */
    float x;
    float y;
    float z;
};
