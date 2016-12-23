#pragma once
#include <math.h>
#include <stdlib.h>

class vec3 {
public:
	vec3();
	vec3(double x, double y, double z);
	~vec3();
	float *x, *y, *z;
	float data[3];

	inline const vec3& operator+() const { return *this; }

	inline vec3& operator*(const vec3 &v2);
	inline vec3& operator*=(const float t);

	inline float dot(const vec3 &v2);

	inline float length() const { return sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]); }
	inline vec3 normalise(const vec3 &v);


	
	
};

inline vec3 operator*(float t, const vec3 & v) {
	return vec3(t * v.data[0], t * v.data[1], t * v.data[2]);
}
inline vec3 operator*(const vec3 & v, float t) {
	return vec3(t * v.data[0], t * v.data[1], t * v.data[2]);
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.data[0] + v2.data[0], v1.data[1] + v2.data[1], v1.data[2] + v2.data[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.data[0] - v2.data[0], v1.data[1] - v2.data[1], v1.data[2] - v2.data[2]);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.data[0] / v2.data[0], v1.data[1] / v2.data[1], v1.data[2] / v2.data[2]);
}

inline vec3 operator/(vec3 v, float t) {
	return vec3(v.data[0] / t, v.data[1] / t, v.data[2] / t);
}

inline float dot(const vec3 & v1, const vec3 & v2) {
	return v1.data[0] * v2.data[0] + v1.data[1] * v2.data[1] + v1.data[2] * v2.data[2];
}