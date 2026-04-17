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
#include "rl.hpp"
#include "properties.hpp"
#include <unordered_map>

namespace vessel {
	class Scene;

	class BaseNode {
		public:
			ThingProperties properties;

			virtual std::string get_id(void) = 0;

			virtual void update(Scene &scene, float dt) = 0;
			virtual void draw(Scene &scene, float dt) = 0;
	};

	class Scene {
		private:
			std::string _id;
			std::unordered_map<std::string, BaseNode &, HashString> _nodes;
			Raylib::Camera2D _camera;

		public:
			ThingProperties properties;
			
			Scene(void);	// do not use
			Scene(std::string id);
			~Scene(void);

			std::string get_id(void);

			void add_node(BaseNode &node);
			void remove_node(std::string id);

			void set_camera(Raylib::Camera2D camera);
			Raylib::Camera2D get_camera(void);

			void update(float dt);
			void draw(float dt);
	};
};
