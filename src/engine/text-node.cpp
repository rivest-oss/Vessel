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

#include "text-node.hpp"
#include "rl.hpp"

namespace vessel {
	void _text_node_update(Node &node, Scene &scene, float dt) {
		(void)node;
		(void)scene;
		(void)dt;
		// yup
	};

	void _text_node_draw(Node &node, Scene &scene, float dt) {
		(void)node;
		(void)scene;
		(void)dt;

		std::string text = node.properties.get_string("text", "<MISSING TEXT>");
		float font_size = node.properties.get_float("fontSize", 16.f);

		Raylib::DrawText(
			text.c_str(),
			0,
			0,
			font_size,
			Raylib::WHITE
		);
	};

	Node create_text_node(std::string id) {
		ox_assert(id.size() >= 1, "invalid 'id' value");
		Node node(
			id,
			_text_node_update,
			_text_node_draw
		);

		return node;
	};
};
