#include "PID.h"

/*
Controller library using standard form PID

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

struct PIDController {
	float adjustment_factor;
	float inverse_integral_time;
	float inverse_derivative_time;
	float integral_error;
	float previous_error;
	float previous_derivatives[PID_LOWPASS_SAMPLES];
	float target;
	float output;
};

PID PID_new(float adjustment_factor, float integral_time, float derivative_time) {
	PID result = {
		.adjustment_factor = adjustment_factor,
		.inverse_integral_time = 1.0 / integral_time,
		.inverse_derivative_time = 1.0 / derivative_time,
		.integral_error = 0,
		.previous_derivatives = {0,},
		.previous_error = 0,
		.target = 0,
		.output = 0,
	};
	return result;
}

void PID_target(PID *controller, float target) {
	controller->target = target;
}

float PID_output(PID *controller) {
	return controller->output;
}

void PID_update(PID *controller, float dt, float measured_value) {
	int i;
	if (dt < 0.0001) {
		controller->previous_error = error;
		return;
	}
	float error = controller->target - measured_value;
	controller->integral_error += error * dt; // update itnegral value
	float derivative = (error - controller->previous_error) / dt; // update derivative value
	controller->previous_error = error;
	float average = derivative;
	for (i = 0; i < PID_LOWPASS_SAMPLES; i ++) // moving average as low pass filter for derivative
		average += controller->previous_derivatives[i];
	average /= PID_LOWPASS_SAMPLES + 1;
	for (i = 1; i < PID_LOWPASS_SAMPLES; i ++)
		controller->previous_derivatives[i - 1] = controller->previous_derivatives[i];
	controller->previous_derivatives[PID_LOWPASS_SAMPLES - 1] = derivative; // update moving average
	controller->output = controller->adjustment_factor * ( // standard form PID equation
		error + // reduces error proportionally
		controller->inverse_integral_time * controller->integral_error + // eliminates steady state error and the accelerates slow convergence
		controller->inverse_derivative_time * average // predicts behaviour of system based on previous behaviour
	);
}
