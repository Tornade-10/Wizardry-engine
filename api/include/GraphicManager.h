#ifndef API_GRAPHIC_MANAGER_H
#define API_GRAPHIC_MANAGER_H

#include <SDL_render.h>
#include <vector>

#include "Maths/Vec2.h"

class GraphicManager
{
	std::vector<SDL_Vertex> vertices_;
	std::vector<int> idx_vertices_;
	int num_segments = 32;

public:
	GraphicManager() = default;

	void CreateCircle(core::Vec2<float> pos, float radius, SDL_Color color);

	void AddVertex(core::Vec2<float> pos, SDL_Color color);

	void Clear()
	{
		vertices_.clear();
		idx_vertices_.clear();
	}

	std::vector<SDL_Vertex>& vertices()
	{
		return vertices_;
	}
	std::vector<int>& idx_vertices()
	{
		return idx_vertices_;
	}
};

#endif