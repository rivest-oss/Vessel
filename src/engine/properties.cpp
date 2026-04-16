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

#include "properties.hpp"

namespace vessel {
	ThingProperties::ThingProperties(void) {
		// ... huh?
	};

	ThingProperties::~ThingProperties(void) {
		// ... huh?
	};

	int ThingProperties::get_type(std::string key) {
		if(_properties.find(key) == _properties.end())
			return NoneProperty;

		int type = _properties[key].type;

		switch(type) {
			case NoneProperty:
			case BoolProperty:
			case IntProperty:
			case FloatProperty:
			case StringProperty:
				return type;
			
			default:
				return NoneProperty;
		};
	};

	bool ThingProperties::get_bool(std::string key, bool fallback) {
		return get_type(key) == BoolProperty
			? _properties[key].value_b
			: fallback;
	};

	long ThingProperties::get_int(std::string key, long fallback) {
		return get_type(key) == IntProperty
			? _properties[key].value_i
			: fallback;
	};

	double ThingProperties::get_float(std::string key, double fallback) {
		return get_type(key) == FloatProperty
			? _properties[key].value_f
			: fallback;
	};

	std::string ThingProperties::get_string(std::string key, std::string fallback) {
		return get_type(key) == StringProperty
			? _properties[key].value_s
			: fallback;
	};

	void ThingProperties::set_bool(std::string key, bool value) {
		if(_properties.find(key) != _properties.end())
			_properties.erase(key);

		_properties.insert_or_assign(key, _property_keyvaluepair_t {
			BoolProperty,
			
			value,
			-1,
			-1.0,
			"",
		});
	};

	void ThingProperties::set_int(std::string key, long value) {
		if(_properties.find(key) != _properties.end())
			_properties.erase(key);

		_properties.insert_or_assign(key, _property_keyvaluepair_t {
			IntProperty,

			false,
			value,
			-1.0,
			"",
		});
	};

	void ThingProperties::set_float(std::string key, double value) {
		if(_properties.find(key) != _properties.end())
			_properties.erase(key);

		_properties.insert_or_assign(key, _property_keyvaluepair_t {
			FloatProperty,

			false,
			-1,
			value,
			"",
		});
	};

	void ThingProperties::set_string(std::string key, std::string value) {
		if(_properties.find(key) != _properties.end())
			_properties.erase(key);

		_properties.insert_or_assign(key, _property_keyvaluepair_t {
			StringProperty,

			false,
			-1,
			-1.0,
			value,
		});
	};
};
