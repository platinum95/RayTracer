

#include <iostream>
#include "lodepng.h"
#include "Ray.h"

static const unsigned int width = 1920, height = 1080;
unsigned char screen_buffer[width * height * 3];


vec3 normalise(const vec3 & v) {
	return v / v.length();
}

bool hit_sphere(const vec3& center, float radius, const Ray& r) {
	vec3 oc = r.origin - center;
	float a = dot(r.direction, r.direction);
	float b = 2.0 * dot(oc, r.direction);
	float c = dot(oc, oc) - radius * radius;
	float discr = b*b - 4 * a*c;
	return (discr > 0);

}

vec3 colour(const Ray& r) {
	if (hit_sphere(vec3(0, 0, -1), 0.5, r))
		return vec3(255, 0, 0);
	vec3 r_norm = normalise(r.direction);
	float t = 0.5 * (r_norm.data[1] + 1.0);
	return  ((1.0 - t) * vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0))  * 255.0;
}

int main() {
	vec3 low_left(-2.0, -1.0, -1.0);
	vec3 horiz(4.0, 0, 0);
	vec3 vert(0, 2.0, 0);
	vec3 origin(0, 0, 0);
	for (int y = height - 1; y >= 0; y--) {
		for (int x = 0; x < width; x++) {
			float u = float(x) / float(width);
			float v = float(y) / float(height);
			Ray r(origin, low_left + u*horiz + v*vert);
			vec3 col = colour(r);

			unsigned int index = y * (width * 3) + (x*3);
			screen_buffer[index] = col.data[0];
			screen_buffer[++index] = col.data[1];
			screen_buffer[++index] = col.data[2];


		}

	}

	lodepng_encode24_file("output.png", screen_buffer, width, height);
}




