//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include <cmath>
#include "Vector.h"

const float DEG2RAD = 3.141593f / 180.0f;

struct Matrix
{
public:
    /**
     * Initialize identity matrix.
     */
    Matrix()
    {
        Identity();
    };

    /**
     * Create matrix from source raw data array.
     * @param src - Raw matrix data.
     */
    Matrix(const float src[16])
    {
        Set(src);
    };

    Matrix(float m00, float m01, float m02, float m03, // 1st column
           float m04, float m05, float m06, float m07, // 2nd column
           float m08, float m09, float m10, float m11, // 3rd column
           float m12, float m13, float m14, float m15) // 4th column
    {
        Set(m00, m01, m02, m03,  m04, m05, m06, m07,  m08, m09, m10, m11,  m12, m13, m14, m15);
    };

    /**
     * Reset current matrix to identity matrix
     */
    inline Matrix& Identity()
    {
        m[0] = m[5] = m[10] = m[15] = 1.0f;
        m[1] = m[2] = m[3] = m[4] = m[6] = m[7] = m[8] = m[9] = m[11] = m[12] = m[13] = m[14] = 0.0f;

        return *this;
    };

    /**
     * Translation by (x, y, z)
     */
    Matrix& Translate(float x, float y, float z)
    {
        m[0] += m[3] * x;   m[4] += m[7] * x;   m[8] += m[11]* x;   m[12]+= m[15]* x;
        m[1] += m[3] * y;   m[5] += m[7] * y;   m[9] += m[11]* y;   m[13]+= m[15]* y;
        m[2] += m[3] * z;   m[6] += m[7] * z;   m[10]+= m[11]* z;   m[14]+= m[15]* z;

        return *this;
    };

    /**
     * Translation by vector
     * @param v Vector
     */
    Matrix& Translate(const Vector& v)
    {
        return Translate(v.x, v.y, v.z);
    };

    /**
     * Look at.
     */
    Matrix& LookAt(const Vector& eye, const Vector& center, const Vector& up)
    {
        Vector f = center - eye;
        f.Normalize();

        Vector s = f.Cross(up);
        s.Normalize();

        Vector u = s.Cross(f);

        this->SetColumn(0, s);
        this->SetColumn(1, u);
        this->SetColumn(2, -f);

        m[12] = -(s.Dot(eye));
        m[13] = -(u.Dot(eye));
        m[14] =  (f.Dot(eye));

        return *this;
    }

    /**
     * Perspective matrix.
     */
    Matrix& Perspective(float FOV, float aspect, float near, float far)
    {
        const float h = 1.0f / tan(FOV*DEG2RAD);
        float neg_depth = near - far;

        m[0] = h / aspect;
        m[1] = 0;
        m[2] = 0;
        m[3] = 0;

        m[4] = 0;
        m[5] = h;
        m[6] = 0;
        m[7] = 0;

        m[8] = 0;
        m[9] = 0;
        m[10] = (far + near) / neg_depth;
        m[11] = -1;

        m[12] = 0;
        m[13] = 0;
        m[14] = 2.0f*(near*far) / neg_depth;
        m[15] = 0;

        return *this;
    };

    inline float operator[](int index) const
    {
        return m[index];
    };

    inline float& operator[](int index)
    {
        return m[index];
    };

    inline Matrix operator*(const Matrix& n) const
    {
        return Matrix(m[0]*n[0]  + m[4]*n[1]  + m[8]*n[2]  + m[12]*n[3],   m[1]*n[0]  + m[5]*n[1]  + m[9]*n[2]  + m[13]*n[3],   m[2]*n[0]  + m[6]*n[1]  + m[10]*n[2]  + m[14]*n[3],   m[3]*n[0]  + m[7]*n[1]  + m[11]*n[2]  + m[15]*n[3],
                      m[0]*n[4]  + m[4]*n[5]  + m[8]*n[6]  + m[12]*n[7],   m[1]*n[4]  + m[5]*n[5]  + m[9]*n[6]  + m[13]*n[7],   m[2]*n[4]  + m[6]*n[5]  + m[10]*n[6]  + m[14]*n[7],   m[3]*n[4]  + m[7]*n[5]  + m[11]*n[6]  + m[15]*n[7],
                      m[0]*n[8]  + m[4]*n[9]  + m[8]*n[10] + m[12]*n[11],  m[1]*n[8]  + m[5]*n[9]  + m[9]*n[10] + m[13]*n[11],  m[2]*n[8]  + m[6]*n[9]  + m[10]*n[10] + m[14]*n[11],  m[3]*n[8]  + m[7]*n[9]  + m[11]*n[10] + m[15]*n[11],
                      m[0]*n[12] + m[4]*n[13] + m[8]*n[14] + m[12]*n[15],  m[1]*n[12] + m[5]*n[13] + m[9]*n[14] + m[13]*n[15],  m[2]*n[12] + m[6]*n[13] + m[10]*n[14] + m[14]*n[15],  m[3]*n[12] + m[7]*n[13] + m[11]*n[14] + m[15]*n[15]);
    };

    /**
     * Multiplication: v' = M * v
     */
    Vector operator*(const Vector& rhs) const
    {
        return Vector(m[0]*rhs.x + m[4]*rhs.y + m[8]*rhs.z + m[12],
                      m[1]*rhs.x + m[5]*rhs.y + m[9]*rhs.z + m[13],
                      m[2]*rhs.x + m[6]*rhs.y + m[10]*rhs.z+ m[14]);
    };

    /**
     * Rotate.
     */
    Matrix& Rotate(float angle, const Vector& axis)
    {
        return Rotate(angle, axis.x, axis.y, axis.z);
    }

    /**
     * Rotate.
     */
    Matrix& Rotate(float angle, float x, float y, float z)
    {
        float c = cosf(angle * DEG2RAD);    // cosine
        float s = sinf(angle * DEG2RAD);    // sine
        float c1 = 1.0f - c;                // 1 - c
        float m0 = m[0],  m4 = m[4],  m8 = m[8],  m12= m[12],
              m1 = m[1],  m5 = m[5],  m9 = m[9],  m13= m[13],
              m2 = m[2],  m6 = m[6],  m10= m[10], m14= m[14];

        // build rotation matrix
        float r0 = x * x * c1 + c;
        float r1 = x * y * c1 + z * s;
        float r2 = x * z * c1 - y * s;
        float r4 = x * y * c1 - z * s;
        float r5 = y * y * c1 + c;
        float r6 = y * z * c1 + x * s;
        float r8 = x * z * c1 + y * s;
        float r9 = y * z * c1 - x * s;
        float r10= z * z * c1 + c;

        // multiply rotation matrix
        m[0] = r0 * m0 + r4 * m1 + r8 * m2;
        m[1] = r1 * m0 + r5 * m1 + r9 * m2;
        m[2] = r2 * m0 + r6 * m1 + r10* m2;
        m[4] = r0 * m4 + r4 * m5 + r8 * m6;
        m[5] = r1 * m4 + r5 * m5 + r9 * m6;
        m[6] = r2 * m4 + r6 * m5 + r10* m6;
        m[8] = r0 * m8 + r4 * m9 + r8 * m10;
        m[9] = r1 * m8 + r5 * m9 + r9 * m10;
        m[10]= r2 * m8 + r6 * m9 + r10* m10;
        m[12]= r0 * m12+ r4 * m13+ r8 * m14;
        m[13]= r1 * m12+ r5 * m13+ r9 * m14;
        m[14]= r2 * m12+ r6 * m13+ r10* m14;

        return *this;
    };

    /**
     * Scale.
     */
    Matrix& Scale(float x, float y, float z)
    {
        m[0] *= x;   m[4] *= x;   m[8] *= x;   m[12] *= x;
        m[1] *= y;   m[5] *= y;   m[9] *= y;   m[13] *= y;
        m[2] *= z;   m[6] *= z;   m[10]*= z;   m[14] *= z;

        return *this;
    }

private:
    /**
     * Set matrix values.
     * @param src - Source raw data.
     */
    inline void Set(const float src[16])
    {
        m[0] = src[0];  m[1] = src[1];  m[2] = src[2];  m[3] = src[3];
        m[4] = src[4];  m[5] = src[5];  m[6] = src[6];  m[7] = src[7];
        m[8] = src[8];  m[9] = src[9];  m[10]= src[10]; m[11]= src[11];
        m[12]= src[12]; m[13]= src[13]; m[14]= src[14]; m[15]= src[15];
    };

    /**
     * Set matrix values.
     * @param m00-m15 - Matrix values.
     */
    inline void Set(float m00, float m01, float m02, float m03,
                    float m04, float m05, float m06, float m07,
                    float m08, float m09, float m10, float m11,
                    float m12, float m13, float m14, float m15)
    {
        m[0] = m00;  m[1] = m01;  m[2] = m02;  m[3] = m03;
        m[4] = m04;  m[5] = m05;  m[6] = m06;  m[7] = m07;
        m[8] = m08;  m[9] = m09;  m[10]= m10;  m[11]= m11;
        m[12]= m12;  m[13]= m13;  m[14]= m14;  m[15]= m15;
    };

    /**
     * Set matrix column.
     * @param index
     * @param col
     */
    inline void SetColumn(int index, const float col[4])
    {
        m[index*4] = col[0];  m[index*4 + 1] = col[1];  m[index*4 + 2] = col[2];  m[index*4 + 3] = col[3];
    };

    /**
     * Set matrix column.
     * @param index
     * @param v
     */
    inline void SetColumn(int index, const Vector& v)
    {
        m[index*4] = v.x;  m[index*4 + 1] = v.y;  m[index*4 + 2] = v.z;
    };

    /** Matrix data. */
    float m[16];
};
