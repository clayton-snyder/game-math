#include "Matrix3.h"

///////////////////////////////
//////////// CTORs ////////////

Matrix3::Matrix3(float all) : elem{ {all, all, all}, {all, all, all}, {all, all, all} } {}

// We store consecutive column values in adjacent memory for quick column-major access
Matrix3::Matrix3(
    float col0row0, float col0row1, float col0row2,
    float col1row0, float col1row1, float col1row2,
    float col2row0, float col2row1, float col2row2)
{
    elem[0][0] = col0row0; elem[0][1] = col1row0; elem[0][2] = col2row0;
    elem[1][0] = col0row1; elem[1][1] = col1row1; elem[1][2] = col2row1;
    elem[2][0] = col0row2; elem[2][1] = col1row2; elem[2][2] = col2row2;
}

// We store consecutive column values in adjacent memory for quick column-major access
Matrix3::Matrix3(const Vector3& col0, const Vector3& col1, const Vector3& col2) {
    elem[0][0] = col0.x; elem[0][1] = col0.y; elem[0][2] = col0.z;
    elem[1][0] = col1.x; elem[1][1] = col1.y; elem[1][2] = col1.z;
    elem[2][0] = col2.x; elem[2][1] = col2.y; elem[2][2] = col2.z;
}



///////////////////////////////////
//////////// Accessors ////////////

float& Matrix3::operator()(int row, int col) {
    return elem[col][row];
}

const float& Matrix3::operator()(int row, int col) const {
    return elem[col][row];
}

Vector3& Matrix3::operator[](int row) {
    return static_cast<Vector3>(elem[row]);
}

const Vector3 Matrix3::operator[](int row) const {
    return static_cast<const Vector3>(elem[row]);
}



///////////////////////////////////
//////////// Utility //////////////

Matrix3 Matrix3::getRotatorX(float deg) {
    return Matrix3
    (
        1.f,    0.f,       0.f,
        0.f,    cos(deg),  -sin(deg),
        0.f,    sin(deg),  cos(deg)
    );
}

Matrix3 Matrix3::getRotatorY(float deg) {
    return Matrix3
    (
        cos(deg),   0.f,    sin(deg),
        0.f,        1.f,    0.f,
        -sin(deg),  0.f,    cos(deg)
    );
}

Matrix3 Matrix3::getRotatorZ(float deg) {
    return Matrix3
    (
        cos(deg),   -sin(deg),  0.f,
        sin(deg),   cos(deg),   0.f, 
        0.f,        0.f,        1.f
    );
}

Matrix3 Matrix3::getReflection(const Vector3& a) {
    float x = a.x * -2.f;
    float y = a.y * -2.f;
    float z = a.z * -2.f;
    float axay = x * a.y;
    float axaz = x * a.z;
    float ayaz = y * a.z;

    return Matrix3
    (
        x * a.x + 1.f,  axay,           axaz,
        axay,           y * a.y + 1.f,  ayaz,
        axaz,           ayaz,           z * a.z + 1.f
    );
}

Matrix3 Matrix3::getScale(float sx, float sy, float sz) {
    return Matrix3
    (
        sx,  0.f, 0.f,
        0.f, sy,  0.f,
        0.f, 0.f, sz
    );
}

Matrix3 Matrix3::getSkew(float deg, const Vector3& along, const Vector3& projTo) {
    float x = along.x * tan(deg);
    float y = along.y * tan(deg);
    float z = along.z * tan(deg);

    return Matrix3
    (
        x * projTo.x + 1.f,  x * projTo.y,        x * projTo.z,
        y * projTo.x,        y * projTo.y + 1.f,  y * projTo.z,
        z * projTo.x,        z * projTo.y,        z * projTo.z + 1.f
    );
}