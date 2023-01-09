#include "Quat.h"

///////////////////////////////
//////////// CTORs ////////////

Quat::Quat(float x, float y, float z, float w) {
    this->x = x; 
    this->y = y; 
    this->z = z; 
    this->w = w;
}

Quat::Quat(const Vector3& imaginary, float scalar) {
    this->x = imaginary.x;
    this->y = imaginary.y;
    this->z = imaginary.z;
    this->w = scalar;
}



///////////////////////////////////
//////////// Operators ////////////

Quat Quat::operator+(const Quat& other) {
    return Quat(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
}

Quat Quat::operator-(const Quat& other) {
    return Quat(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
}

Quat Quat::operator*(float scalar) {
    return Quat(x * scalar, y * scalar, z * scalar, w + scalar);
}

// Hamilton's rule
Quat Quat::operator*(const Quat& other) {
    return Quat
    (
		this->w * other.x + this->x * other.w + this->y * other.z - this->z * other.y,
		this->w * other.y - this->x * other.z + this->y * other.w + this->z * other.x,
		this->w * other.z + this->x * other.y - this->y * other.x + this->z * other.w,
		this->w * other.w - this->x * other.x - this->y * other.y - this->z * other.z
    );
}



/////////////////////////////////
//////////// Utility ////////////

// The Vector part of a quaternion excludes the real number (i.e., the scalar)
Vector3 Quat::getImaginaryVector() const {
    return Vector3(x, y, z);
}

Matrix3 Quat::toRotationMatrix() const {
    float x2 = x * x; float y2 = y * y; float z2 = z * z;
    float xy = x * y; float xz = x * z; float yz = y * z;
    float wx = w * x; float wy = w * y; float wz = w * z;

    return Matrix3
    (
		1.f - (2.f * (y2 + z2)),  2.f * (xy - wz),          2.f * (xz + wy),
		2.f * (xy + wz),          1.f - (2.f * (x2 + z2)),  2.f * (yz - wx),
		2.f * (xz - wy),          2.f * (yz + wx),          1.f - (2.f * (x2 + y2))
    );
}