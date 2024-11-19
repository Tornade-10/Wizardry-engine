#include "GraphicManager.h"

#include <iostream>

void GraphicManager::CreateCircle(core::Vec2<float> pos, float radius, SDL_Color color)
{
	// Get the size of the idx_vector as the starting idx
	const std::size_t starting_idx = vertices_.size();

	float angle_step = 2.0f * 3.14f / static_cast<float>(num_segments);

	AddVertex(pos, color);

	// Draw triangles for the radius of the circle
	for (std::size_t i = 0; i < num_segments; i++)
	{
		float angle = i * angle_step;
		float x = pos.x + radius * std::cos(angle);
		float y = pos.y + radius * std::sin(angle);

		AddVertex(core::Vec2<float>(x, y), color);
	}

	// Give an id to every segments
	for (int i = 0; i < num_segments - 1; i++)
	{
		idx_vertices_.push_back(starting_idx);
		idx_vertices_.push_back(starting_idx + i + 1);
		idx_vertices_.push_back(starting_idx + i + 2);
	}

	// Put back the first segment as the last one after going through the whole vector
	idx_vertices_.push_back(starting_idx);
	idx_vertices_.push_back(starting_idx + num_segments);
	idx_vertices_.push_back(starting_idx + 1);
}

void GraphicManager::AddVertex(core::Vec2<float> pos, SDL_Color color)
{
	SDL_Vertex vertex;
	
	vertex.position.x = pos.x;
	vertex.position.y = pos.y;
	vertex.color = color;

	// Add to vertices vector
	vertices_.push_back(vertex);
}
