#include <stdio.h>
#include "PID.c"

#define PID_TARGET(p, target) ((p)=PID_target(p, target))
#define PID_UPDATE(p, dt, measured_value) ((p)=PID_update(p, dt, measured_value))

float t;

int main(void) {
	float p = 0;
	float target = 180;
	float dt = 0.05;

	PID c = PID_target(PID_new(12, 20, 18), target);
	for (t = 0.0; p - target < -0.5 || p - target > 0.5; t += dt) {
		float v = PID_output(c); v = v < -500 ? -500 : v > 500 ? 500 : v;
		p += v * dt;
		printf("Time: %f\tPosition: %f\tVelocity: %f\n", t, p, v);
		PID_UPDATE(c, dt, p);
	}
	return 0;
}
