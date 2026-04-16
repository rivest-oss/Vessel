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
#include "utils.hpp"
#include <unordered_map>

namespace vessel {
	class ThingProperties {
		public:
			enum : int {
				NoneProperty = 0,
				BoolProperty,
				IntProperty,
				FloatProperty,
				StringProperty,
			};

		private:
			typedef struct _property_keyvaluepair_t {
				int type = NoneProperty;

				bool value_b = false;
				long value_i = -1;
				double value_f = -1.0;
				std::string value_s = "";
			} _property_keyvaluepair_t;

			std::unordered_map<std::string, _property_keyvaluepair_t, HashString> _properties;

		public:
			ThingProperties(void);
			~ThingProperties(void);

			int get_type(std::string key);

			bool get_bool(std::string key, bool fallback);
			long get_int(std::string key, long fallback);
			double get_float(std::string key, double fallback);
			std::string get_string(std::string key, std::string fallback);

			void set_bool(std::string key, bool value);
			void set_int(std::string key, long value);
			void set_float(std::string key, double value);
			void set_string(std::string key, std::string value);
	};
};
