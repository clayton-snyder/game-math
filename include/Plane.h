#pragma once

#include "Vector3.h"

class Plane {
public:
    float normalX, normalY, normalZ, d;

    Vector3 getNormal() const;

    ///////////////////////////////
    //////////// CTORs ////////////
    
    Plane() = default;
    Plane(float normalX, float normalY, float normalZ, float d);
    Plane(const Vector3& normal, float d);
};