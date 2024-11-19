#include "collision.h"

#include <iostream>

void Collision::CreateCircle(const core::Vec2<float>& position, const core::Vec2<float>& velocity, float mass, float radius)
{
	// I need the body of the circle + the collider, that should probably do the trick
	physic::Body body(position, velocity, core::Vec2<float>(0.0f, 0.0f), mass);
	physic::CircleCollider collider(position, radius);
	circles_.emplace_back(body, collider);
}

void Collision::MoveCircle()
{
	for (auto& circle : circles_)
	{
		circle.first.UpdatePosition();
		circle.second.position_ = circle.first.position();
	}
}

void Collision::CheckCollisions()
{
	// std::vector<bool> collision_states(circles_.size(), false);

	for (std::size_t i = 0; i < circles_.size(); i++)
	{
		for(std::size_t j = i + 1; j < circles_.size(); j++)
		{
			auto& [body1, collider1] = circles_[i];
			auto& [body2, collider2] = circles_[j];

			if (collider1.Colliding(collider2))
			{
				circles_[i].second.is_colliding = true;
				circles_[j].second.is_colliding = true;
				// collision_states[i] = true;
				// collision_states[j] = true;
				// std::cout << "Circles colliding" << std::endl;
			}
			else
			{
				circles_[i].second.is_colliding = false;
				circles_[j].second.is_colliding = false;
			}
		}
	}
}
