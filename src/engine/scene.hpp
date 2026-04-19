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

	class Node {
		public:
			typedef void (*scene_fn_t)(Node &node, Scene &scene, float dt);

		private:
			std::string _id;
			scene_fn_t _update, _draw;

		public:
			Node(void);	// do not use
			Node(std::string id, scene_fn_t update_fn, scene_fn_t draw_fn);
			~Node(void);

			ThingProperties properties;

			std::string get_id(void);

			void update(Scene &scene, float dt);
			void draw(Scene &scene, float dt);
	};

	class Scene {
		private:
			std::string _id;
			std::unordered_map<std::string, Node &, HashString> _nodes;
			Raylib::Camera2D _camera;

		public:
			ThingProperties properties;
			
			Scene(void);	// do not use
			Scene(std::string id);
			~Scene(void);

			std::string get_id(void);

			void add_node(Node &node);
			void remove_node(std::string id);

			void set_camera(Raylib::Camera2D camera);
			Raylib::Camera2D get_camera(void);

			void update(float dt);
			void draw(float dt);
	};
};
