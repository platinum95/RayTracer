#include "vec3.h"



vec3::vec3() {
}

vec3::vec3(double _x, double _y, double _z){
	this->x = &data[0];
	data[0] = _x;
	this->y = &data[1];
	data[1] = _y;
	this->z = &data[2];
	data[2] = _z;

}


vec3::~vec3() {
}


inline vec3 & vec3::operator*(const vec3 & v2) {
	return vec3(this->data[0] * v2.data[0], this->data[1] * v2.data[1], this->data[2] * v2.data[2]);
}



inline vec3 & vec3::operator*=(const float t) {
	data[0] *= t;
	data[1] *= t;
	data[2] *= t;
	return *this;
}




