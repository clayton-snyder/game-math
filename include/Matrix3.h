#pragma once

#include "Vector3.h"

/// We store the elements in swapped order than their input to store in column-major order
/// for more efficient memory alignment.
class Matrix3 {
private:
    float elem[3][3];

public:
    ///////////////////////////////
    //////////// CTORs ////////////

    Matrix3() = default;
    Matrix3(float all);
    Matrix3(const Vector3& col0, const Vector3& col1, const Vector3& col2);
    Matrix3(float col0row0, float col0row1, float col0row2,
            float col1row0, float col1row1, float col1row2,
            float col2row0, float col2row1, float col2row2);
    
    
    
    ///////////////////////////////////
    //////////// Accessors ////////////

    float& operator()(int row, int col);
    const float& operator()(int row, int col) const;
    Vector3& operator[](int row);
    const Vector3 operator[](int row) const;



    ///////////////////////////////////
    //////////// Utility //////////////

    // Get a Matrix3 representing a rotation about the X axis by specified degrees
    static Matrix3 getRotatorX(float deg);

    // Get a Matrix3 representing a rotation about the Y axis by specified degrees
    static Matrix3 getRotatorY(float deg);

    // Get a Matrix3 representing a rotation about the Z axis by specified degrees
    static Matrix3 getRotatorZ(float deg);

    // Get a Matrix3 representing a reflection through the plane perpendicular to "a".
    static Matrix3 getReflection(const Vector3& a);
    
    // Get a Matrix3 representing a scale by a factor of "s" in each axis
    static Matrix3 getScale(float sx, float sy, float sz);

    // Get a Matrix3 representing a skew of "deg" degrees in the direction of "along" based on
    // the projected length on the direction of "projTo". "along" and "projTo" should be orthogonal
    static Matrix3 getSkew(float deg, const Vector3& along, const Vector3& projTo);
};