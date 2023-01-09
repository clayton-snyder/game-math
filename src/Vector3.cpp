#include "Vector3.h"

#include <sstream>
#include <math.h>


///////////////////////////////
//////////// CTORs ////////////

Vector3::Vector3(float all) {
    x = all;
    y = all;
    z = all;
}

Vector3::Vector3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::Vector3(float xyz[3]) {
    x = xyz[0];
    y = xyz[1];
    z = xyz[2];
}

Vector3::Vector3(const float xyz[3]) {
    x = xyz[0];
    y = xyz[1];
    z = xyz[2];
}




///////////////////////////////////
//////////// Operators ////////////

Vector3 Vector3::operator+(const Vector3& other) {
    return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) {
    return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3 Vector3::operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator/(float scalar) {
    return Vector3(x / scalar, y / scalar, z / scalar);
}

Vector3& Vector3::operator+=(const Vector3& other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return (*this);
}

Vector3& Vector3::operator-=(const Vector3& other) {
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return (*this);
}

Vector3& Vector3::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return (*this);
}

Vector3& Vector3::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return (*this);
}

// Index Accessors
float& Vector3::operator[](short index) {
    switch(index) {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    default:
        return z;
    }
}

const float& Vector3::operator[](short index) const {
    switch(index) {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    default:
        return z;
    }
}




/////////////////////////////////
//////////// Utility ////////////

float Vector3::magnitude() const {
    return sqrt((x * x) + (y * y) + (z * z));
}

float Vector3::dot(const Vector3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3& other) const {
    return Vector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

Vector3 Vector3::normalized() const {
    float length = magnitude();
    return Vector3(x / length, y / length, z / length);
}

float Vector3::scalarTriple(const Vector3& b, const Vector3& c) const {
    return cross(b).dot(c);
}

Vector3 Vector3::project(const Vector3& onto) const {
    return onto * (dot(onto) / onto.dot(onto));
}

std::string Vector3::toString() const {
    std::ostringstream ss;
    ss << "(" << x << ", " << y << ", " << z << ")";
    return ss.str();
}