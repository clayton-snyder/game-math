#include "Plane.h"

Plane::Plane(float normalX, float normalY, float normalZ, float d) {
    this->normalX = normalX;
    this->normalY = normalY;
    this->normalZ = normalZ;
    this->d = d;
}

Plane::Plane(const Vector3& normal, float d) {
    this->normalX = normal.x;
    this->normalY = normal.y;
    this->normalZ = normal.z;
    this->d = d;
}

Vector3 Plane::getNormal() const {
    return Vector3(this->normalX, this->normalY, this->normalZ);
}