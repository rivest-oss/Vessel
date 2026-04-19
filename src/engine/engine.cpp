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

#include "engine.hpp"
#include "utils.hpp"
#include <unordered_map>

namespace vessel {
	namespace engine {
		std::unordered_map<std::string, Scene, HashString> _registered_scenes_map;
		std::string _curr_scene;

		int init(void) {
			_registered_scenes_map.clear();

			_curr_scene = create_scene("$_DefaultScreen").get_id();

			return 0;
		};

		void deinit(void) {
			_registered_scenes_map.clear();
		};

		void update(float dt) {
			get_current_scene().update(dt);
		};

		void draw(float dt) {
			get_current_scene().draw(dt);
		};

		Scene &create_scene(std::string id) {
			ox_assert(id.size() >= 1, "invalid 'id' for 'add_scene'");
			
			Scene scene(id);

			ox_assert(scene.get_id().size() >= 1, "invalid 'id' of argument 'scene'");
			ox_assert(_registered_scenes_map.find(scene.get_id()) == _registered_scenes_map.end(), "tried to add same scene?");
			_registered_scenes_map.insert_or_assign(scene.get_id(), scene);

			return _registered_scenes_map[id];
		};

		Scene &get_scene_by_id(std::string id) {
			ox_assert(id.size() >= 1, "invalid argument 'id'");
			ox_assert(_registered_scenes_map.find(id) != _registered_scenes_map.end(), "tried to get scene that is not registered");
			
			return _registered_scenes_map[id];
		};

		void remove_scene(std::string id) {
			ox_assert(id != _curr_scene, "you can't remove the current scene");
			ox_assert(id.size() >= 1, "invalid argument 'id'");
			ox_assert(_registered_scenes_map.find(id) != _registered_scenes_map.end(), "tried to remove scene that is not registered");
			_registered_scenes_map.erase(id);
		};

		Scene &get_current_scene(void) {
			ox_assert(_curr_scene.size() >= 1, "invalid current scene ID");
			ox_assert(_registered_scenes_map.find(_curr_scene) != _registered_scenes_map.end(), "current scene is not registered");
			return _registered_scenes_map[_curr_scene];
		};

		void transition_to_scene(std::string to) {
			ox_assert(to.size() >= 1, "invalid current scene ID");
			ox_assert(_registered_scenes_map.find(to) != _registered_scenes_map.end(), "specified scene is not registered");
			_curr_scene = to;
		};
	};
};
