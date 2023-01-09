#pragma once

#include <string>

class Vector3 {
public:
    float x, y, z;

    ///////////////////////////////
    //////////// CTORs ////////////

    Vector3() = default;
    Vector3(float all);
    Vector3(float x, float y, float z);
    Vector3(float xyz[3]);
    Vector3(const float xyz[3]);



    ///////////////////////////////////
    //////////// Operators ////////////

    Vector3 operator+(const Vector3& other);
    Vector3 operator-(const Vector3& other);
    Vector3 operator*(float scalar) const;
    Vector3 operator/(float scalar);
    Vector3& operator+=(const Vector3& other);
    Vector3& operator-=(const Vector3& other);
    Vector3& operator*=(float scalar);
    Vector3& operator/=(float scalar);

    // Index accessors
    float& operator[](short index);
    const float& operator[](short index) const;



    /////////////////////////////////
    //////////// Utility ////////////

    float magnitude() const;
    float dot(const Vector3& other) const;
    Vector3 cross(const Vector3& other) const;
    Vector3 normalized() const;
    float scalarTriple(const Vector3& b, const Vector3& c) const;
    Vector3 project(const Vector3& onto) const;
    std::string toString() const;
};