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

#pragma once
#include <cstddef>
#include <string>
#include "../Ox/include/nuclei.hpp"

#ifndef PI
	#define PI	3.14159265358979323846264338327950288419716939937510
#endif
#ifndef PI2
	#define PI2	6.28318530717958647692528676655900576839433879875020
#endif

namespace vessel {
	typedef struct HashString {
		std::size_t operator()(const char *s) const noexcept {
			// xorshift*-based hash
			if(s == nullptr || *s == '\0')
				return 0;

			std::size_t hash = 127;

			char c;
			while((c = *s)) {
				hash *= (std::size_t)c;
				hash ^= hash >> 12;
				hash ^= hash << 25;
				hash ^= hash >> 27;
				hash *= 0x2545f491u;
			};

			return hash;
		};

		std::size_t operator()(std::string s) const noexcept {
			// xorshift*-based hash
			if(s.size() < 1)
				return 0;

			std::size_t hash = 127;

			for(char c : s) {
				hash *= (std::size_t)c;
				hash ^= hash >> 12;
				hash ^= hash << 25;
				hash ^= hash >> 27;
				hash *= 0x2545f491u;
			};

			return hash;
		};
	} HashString;

	std::string generate_random_id(void);

	bool is_valid_float(float n);
	bool is_valid_float(double n);

	float lerp(float a, float b, float t);
	float clampf(float x, float min = 0.f, float max = 1.f);
};
