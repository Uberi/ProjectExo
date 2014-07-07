#include <stdio.h>
#include <math.h>

float t;
unsigned int microseconds() { return (unsigned int)(t * 1000000); }

#include "limb.c"

int main(void) {
	float separation = 2;
	float length = 12;
	float p = 0, v = 0;
	float piston_pos = length - separation;
	float target = 120 * 3.141592 / 180;
	float dt = 0.01;
	float limit = 100;
	float time_limit = 3;
	float epsilon = 0.0005;

	Limb c = Limb_new(separation, length); Limb_target(&c, target);
	for (t = 0.0; t < time_limit && (p - target < -epsilon || p - target > epsilon); t += dt) {
		float a = Limb_pressure(&c); a = a < -limit ? -limit : a > limit ? limit : a;
		v += a * dt; piston_pos += v * dt;
		if (piston_pos < length - separation) piston_pos = length - separation + 0.001; else if (piston_pos > length + separation) piston_pos = length + separation - 0.001;
		p = acos((separation * separation + length * length - piston_pos * piston_pos) / (2 * separation * length));
		printf("Time: %f\tError: %f\tPiston: %f\tVelocity: %f\tAcceleration: %f\n", t, target - p, piston_pos, v, a);
		Limb_update(&c, p);
	}
	return 0;
}
