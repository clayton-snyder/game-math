#pragma once

#include "Vector3.h"
#include "Matrix3.h"

class Quat {
public:
    float x, y, z, w;

    ///////////////////////////////
    //////////// CTORs ////////////

    Quat() = default;
    Quat(float x, float y, float z, float w);
    Quat(const Vector3& imaginary, float scalar);



    ///////////////////////////////////
    //////////// Operators ////////////

    Quat operator+(const Quat& other);
    Quat operator-(const Quat& other);
    Quat operator*(float scalar);
    Quat operator*(const Quat& other);



    /////////////////////////////////
    //////////// Utility ////////////

    Vector3 getImaginaryVector() const;
    Matrix3 toRotationMatrix() const;
};