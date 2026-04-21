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
	Node::Node(void) {
		_id = "$_INVALID_NODE";

		_update = [](Node &node, Scene &scene, float dt) -> void {
			(void)node; (void)scene; (void)dt;
			ox_assert(false, "empty 'update' function called");
		};

		_draw = [](Node &node, Scene &scene, float dt) -> void {
			(void)node; (void)scene; (void)dt;
			ox_assert(false, "empty 'draw' function called");
		};
	};

	Node::Node(std::string id, scene_fn_t update_fn, scene_fn_t draw_fn) {
		ox_assert(id.size() >= 1, "invalid 'id' value");
		ox_assert(update_fn != nullptr, "invalid 'update_fn' value");
		ox_assert(draw_fn != nullptr, "invalid 'draw_fn' value");

		_id = id;
		_update = update_fn;
		_draw = draw_fn;
	};

	Node::~Node(void) {
		_id.clear();

		_update = [](Node &node, Scene &scene, float dt) -> void {
			(void)node; (void)scene; (void)dt;
			ox_assert(false, "this shouldn't happen");
		};

		_draw = _update;
	};

	std::string Node::get_id(void) {
		return _id;
	};

	void Node::update(Scene &scene, float dt) {
		_update(*this, scene, dt);
	};

	void Node::draw(Scene &scene, float dt) {
		_draw(*this, scene, dt);
	};

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

	Node &Scene::add_node(Node node) {
		ox_assert(node.get_id().size() >= 1, "invalid value for node 'id'");
		ox_assert(_nodes.find(node.get_id()) == _nodes.end(), "'id' value hash already in nodes vector, maybe duplicated add_node or hashing error?");

		_nodes.insert_or_assign(node.get_id(), node);

		return _nodes[node.get_id()];
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
		
		for(auto &npair : _nodes) {
			npair.second.update(*this, dt);
		};
	};

	void Scene::draw(float dt) {
		Raylib::BeginMode2D(_camera);

		ox_assert(is_valid_float(dt), "'dt' is not a valid number");
		for(auto &npair : _nodes) {
			npair.second.draw(*this, dt);
		};

		Raylib::EndMode2D();
	};
};
