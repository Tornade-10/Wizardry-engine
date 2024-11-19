#include <SDL2/SDL.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>

#include "Engine.h"

int main(int argc, char* argv[])
{
	Engine engine;

	engine.Init();

	engine.Loop();

	return EXIT_SUCCESS;
}