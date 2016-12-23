#pragma once

#include "vec3.h"

class Ray {
public:
	Ray();
	Ray(vec3 origin, vec3 direction);
	~Ray();
	vec3 PointAt(float t);

	vec3 origin, direction;
};

