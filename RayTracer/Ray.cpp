#include "Ray.h"



Ray::Ray() {
}

Ray::Ray(vec3 _origin, vec3 _direction) {
	this->origin = _origin;
	this->direction = _direction;
}


Ray::~Ray() {
}

vec3 Ray::PointAt(float t) {
	return origin + (direction * t);
}
