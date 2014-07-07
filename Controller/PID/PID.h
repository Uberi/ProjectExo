/*
Controller library using standard form PID with PV-controlled derivative term

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

// number of samples to use for the derivative low-pass filter
#define PID_LOWPASS_SAMPLES 3

typedef struct {
	float adjustment_factor;
	float inverse_integral_time;
	float inverse_derivative_time;
	float integral_error;
	float previous_error;
	float previous_derivatives[PID_LOWPASS_SAMPLES];
	float target;
	float output;
} PID;

PID PID_new(float adjustment_factor, float integral_time, float derivative_time);

void PID_target(PID *controller, float target);

float PID_output(PID *controller);

void PID_update(PID *controller, float dt, float measured_value);
