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

struct LimbController;
typedef struct LimbController Limb;

Limb Limb_new(float separation, float length);

void Limb_target(Limb *limb, float desired_limb_angle);

float Limb_pressure(Limb *limb);

void Limb_update(Limb *limb, float actual_limb_angle);
