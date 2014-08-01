#include "limb.h"
#include "porting.c"
#include "PID/PID.h"

/*
Limb controller library using a PID controller internally to control the rotation of a limb, but with transformation of the rotation into a linear space that is easier for the PID controller to work with

Copyright 2014 Anthony Zhang <azhang9@gmail.com> (Uberi)

This file is part of Project Exo.

Project Exo is free software: you can redistribute it and/or modify
it under the terms of the Affero GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Project Exo is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the Affero GNU General Public License
along with Project Exo.  If not, see <http://www.gnu.org/licenses/>.
*/

struct LimbController {
	float k_1, k_2; // constants used in calculating transformations
	float lower, upper; // bounds on piston extension
	PID controller;
	float pressure, previous_velocity;
};

Limb Limb_new(float separation, float length) {
	Limb result = {
		.k_1 = separation * separation + length * length,
		.k_2 = 2 * separation * length,
		.lower = length - separation, .upper = length + separation,
		.controller = PID_new(5, 20, 20),
		.pressure = 0,
		.previous_velocity = 0,
	};
	return result;
}

void Limb_target(Limb *limb, float desired_limb_angle) {
	float extension = sqrt(limb->k_1 - limb->k_2 * cos(desired_limb_angle));
	if (extension <= limb->lower) extension = limb->lower + 0.01; else if (extension >= limb->upper) extension = limb->upper - 0.01;
	PID_target(&(limb->controller), extension);
	//wip: this is the difference in pressure, not the pressures on each side of the plunger - implement controllers for that
	//wip: the stiffness of the joint is determined by the pressures on both sides, so the P_2 in P_1 - P_2
	//wip: we actually control the derivative of the pressure (valves on/off) rather than the pressure itself, account for this
}

float Limb_pressure(Limb *limb) {
	return limb->pressure; //wip: change this so that it controls the second integral of acceleration, displacement
}

void Limb_update(Limb *limb, float actual_limb_angle, float velocity) {
	static unsigned int time = 0;
	unsigned int new_time = microseconds(); float dt = (new_time - time) / 1000000.0; time = new_time;
	if (dt > 0.1) dt = 0.1; else if (dt <= 0) return; // clamp `dt` to 100 milliseconds
	float extension = sqrt(limb->k_1 - limb->k_2 * cos(actual_limb_angle));
	if (extension <= limb->lower) extension = limb->lower + 0.01; else if (extension >= limb->upper) extension = limb->upper - 0.01; // clamp extension to valid range
	PID_update(&(limb->controller), dt, extension);
	limb->pressure = (PID_output(&(limb->controller)) - limb->previous_velocity) / dt;
	limb->previous_velocity = velocity;
}
