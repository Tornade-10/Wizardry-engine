#ifndef API_ENGINE_H
#define API_ENGINE_H

#include <array>
#include <SDL2/SDL.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>

#include "Maths/Vec2.h"
#include "Body.h"
#include "collision.h"
#include "const.h"
#include "GraphicManager.h"
#include "solar_system.h"

class Engine
{
private:
	SDL_Window* my_window_;
	SDL_Renderer* renderer_;
	GraphicManager* graphic_manager_;
	SDL_Event event_;
	SolarSystem solar_system_;
	Collision collision_;

	bool quit_ = false;
	Uint32 last_frame_time_ = SDL_GetTicks();

public:

	int Init();
	int Loop();

	float delta_time;
};

#endif // API_ENGINE_H