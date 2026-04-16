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
#include "rl.hpp"
#include <cmath>
#include <cstddef>

namespace vessel {
	std::size_t _random_id_seq = 0;

	std::string generate_random_id(void) {
		_random_id_seq++;

		std::string id = "RND-ID:";

		{
			size_t tmp = _random_id_seq;
			while(tmp > 0) {
				id.push_back('0' + (tmp % 10));
				if(tmp >= 1) tmp /= 10;
			};
			id.push_back('.');
		}
		{
			size_t tmp = Raylib::GetTime() * 1'000.0;
			while(tmp >= 1) {
				id.push_back('0' + (tmp % 10));
				tmp /= 10;
			};
		}

		return id;
	};

	bool is_valid_float(float n) {
		return	std::isnan(n) == false
				&& std::isinf(n) == false
				&& std::isfinite(n);
	};
	bool is_valid_float(double n) {
		return	std::isnan(n) == false
				&& std::isinf(n) == false
				&& std::isfinite(n);
	};

	float lerp(float a, float b, float t) {
		ox_assert(is_valid_float(a) && is_valid_float(b) && is_valid_float(t), "all numbers in lerp must be valid");
		return a + (b - a) * t;
	};

	float clampf(float x, float min, float max) {
		if(x < min) return min;
		if(x > max) return max;
		return x;
	};
};
