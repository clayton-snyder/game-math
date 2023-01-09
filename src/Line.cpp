#include "Line.h"

Line::Line(float dirX, float dirY, float dirZ, float momentX, float momentY, float momentZ) :
        direction(dirX, dirY, dirZ), moment(momentX, momentY, momentZ) { }

Line::Line(const Vector3& dirIn, const Vector3& momIn) : direction(dirIn), moment(momIn) {}