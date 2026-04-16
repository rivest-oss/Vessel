/*
** Vessel: A cross-platform game engine.
** Copyright (C) 2026 Rivest Osz
** 
** This file is part of "Vessel".
** 
** "Vessel" is free software: you can redistribute it and/or modify it under the terms of
** the GNU General Public License as published by the Free Software Foundation, either
** version 3 of the License, or (at your option) any later version.
** 
** "Vessel" is distributed in the hope that it will be useful, but WITHOUT ANY
** WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
** A PARTICULAR PURPOSE. See the GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License along with
** "Vessel". If not, see <https://www.gnu.org/licenses/>. 
**/

#include "utils.hpp"
#include "easings.hpp"
#include "../Ox/include/nuclei.hpp"
#include <cmath>

namespace vessel {
	float ease_in_out_circ(float a, float b, float t) {
		ox_assert(is_valid_float(t), "'t' is not a valid number");

		t =	t < 0.5
			? ((1. - sqrt(1. - pow(2. * t, 2))) / 2.)
			: ((sqrt(1. - pow(-2. * t + 2., 2)) + 1) / 2.);
		
		return lerp(a, b, t);
	};

	float ease_in_out_back(float a, float b, float t) {
		ox_assert(is_valid_float(t), "'t' is not a valid number");

		const float c1 = 1.70158;
		const float c2 = c1 * 1.525;

		t =	t < 0.5
			? ((pow(2. * t, 2.) * ((c2 + 1.) * 2. * t - c2)) / 2.)
			: ((pow(2. * t - 2., 2) * ((c2 + 1.) * (t * 2. - 2.) + c2) + 2.) / 2.);
		
		return lerp(a, b, t);
	};
};
