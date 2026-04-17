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

#include "scene.hpp"
#include "../Ox/include/nuclei.hpp"

namespace vessel {
	Scene::Scene(void) {
		_id = "$_DEFAULT_ID_";
	};

	Scene::Scene(std::string id) {
		ox_assert(id.size() >= 1, "invalid 'id' value");
		_id = id;
	};

	Scene::~Scene(void) {
		// ... huh?
	};

	std::string Scene::get_id(void) {
		return _id;
	};

	void Scene::add_node(BaseNode &node) {
		ox_assert(node.get_id().size() >= 1, "invalid value for node 'id'");
		ox_assert(_nodes.find(node.get_id()) == _nodes.end(), "'id' value hash already in nodes vector, maybe duplicated add_node or hashing error?");

		_nodes.insert_or_assign(node.get_id(), node);
	};

	void Scene::remove_node(std::string id) {
		ox_assert(_nodes.find(id) != _nodes.end(), "trying to remove node but node isn't in vector");
		_nodes.erase(id);
	};

	void Scene::set_camera(Raylib::Camera2D camera) {
		_camera = camera;
	};

	Raylib::Camera2D Scene::get_camera(void) {
		return _camera;
	};

	void Scene::update(float dt) {
		ox_assert(is_valid_float(dt), "'dt' is not a valid number");
		for(auto &npair : _nodes)
			npair.second.update(*this, dt);
	};

	void Scene::draw(float dt) {
		Raylib::BeginMode2D(_camera);

		ox_assert(is_valid_float(dt), "'dt' is not a valid number");
		for(auto &npair : _nodes)
			npair.second.draw(*this, dt);

		Raylib::EndMode2D();
	};
};
