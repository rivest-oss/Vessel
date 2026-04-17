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

#include "io/log.hpp"
#include "misc/rtconfig.hpp"
#include "Ox/include/nuclei.hpp"

#include "engine/engine.hpp"

namespace Raylib {
	#include <raylib.h>
};

#if defined(PLATFORM_WEB)
	#include <emscripten/emscripten.h>
#endif

int game_init(void) {
	Raylib::SetTargetFPS(60);
	Raylib::SetExitKey(Raylib::KEY_NULL);

	Raylib::InitWindow(640, 360, "Vessel");
	while(Raylib::IsWindowReady() == false) {};
	
	Raylib::InitAudioDevice();
	while(Raylib::IsAudioDeviceReady() == false) {};

	if(vessel::engine::init() != 0)
		return 1;

	vessel::engine::create_scene("myScene");

	return 0;
};

void game_deinit(void) {
	vessel::engine::deinit();

	Raylib::CloseAudioDevice();
	Raylib::CloseWindow();
};

void game_update(double dt) {
	(void)dt;
	
	vessel::engine::update(dt);
};

void game_draw(double dt) {
	Raylib::BeginDrawing();
	Raylib::ClearBackground(Raylib::BLACK);
	
	// [TODO]
	(void)dt;

	vessel::engine::draw(dt);
	
	Raylib::EndDrawing();
	Raylib::SwapScreenBuffer();
};

void game_loop(void) {
	double dt = Raylib::GetFrameTime();
	game_update(dt);
	game_draw(dt);
};

int main(int argc, const char **argv) {
	Ox::Error err;
	
	vessel::config_t conf = vessel::read_config_from_args(argc, argv);
	
	if(game_init() != 0) {
		game_deinit();
		return 1;
	}

	#ifdef PLATFORM_WEB
		emscripten_set_main_loop(game_loop, 0, 1);
	#else
		while(Raylib::WindowShouldClose() == false) {
			game_loop();
		};
	#endif
	
	game_deinit();
	
	return 0;
};

