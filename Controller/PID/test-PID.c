#include <stdio.h>
#include "PID.c"

float t;
int main(void) {
	float p = 0, v = 0;
	float target = 180;
	float dt = 0.01;
	float limit = 1000;

	PID c = PID_new(12, 200000, 180000); PID_target(&c, target);
	for (t = 0.0; t < 3 && (p - target < -0.5 || p - target > 0.5); t += dt) {
		float a = PID_output(&c); a = a < -limit ? -limit : a > limit ? limit : a;
		v += a * dt; p += v * dt;
		printf("Time: %f\tPosition: %f\tVelocity: %f\n", t, p, v);
		PID_update(&c, dt, p);
	}
	return 0;
}
