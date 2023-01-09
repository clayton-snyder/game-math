#pragma once

#include "Vector3.h"

class Line {
public:
    Vector3 direction;
    Vector3 moment;

    Line() = default;
    Line(float dirX, float dirY, float dirZ, float momentX, float momentY, float momentZ);
    Line(const Vector3& direction, const Vector3& moment);
};
