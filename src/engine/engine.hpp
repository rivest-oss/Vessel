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
#include "scene.hpp"

namespace vessel {
	namespace engine {
		int init(void);
		void deinit(void);

		void update(float dt);
		void draw(float dt);

		Scene &create_scene(std::string id);
		Scene &get_scene_by_id(std::string id);
		void remove_scene(std::string id);

		Scene &get_current_scene(void);
		void transition_scene(std::string to);
	};
};
