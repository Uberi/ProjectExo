#include <stdio.h>
#include "PID.c"

float t;
int main(void) {
	float p = 0, v = 0;
	float target = 180;
	float dt = 0.01;
	float limit = 1000;
	float time_limit = 3;
	float epsilon = 0.3;

	PID c = PID_new(12, 200000, 180000); PID_target(&c, target);
	for (t = 0.0; t < time_limit && (p - target < -epsilon || p - target > epsilon); t += dt) {
		float a = PID_output(&c); a = a < -limit ? -limit : a > limit ? limit : a;
		v += a * dt; p += v * dt;
		printf("Time: %f\tPosition: %f\tVelocity: %f\n", t, p, v);
		PID_update(&c, dt, p);
	}
	return 0;
}
