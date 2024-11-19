#ifndef API_COLLISION_H
#define API_COLLISION_H

#include "Body.h"
#include "GraphicManager.h"
#include "CircleCollider.h"

class Collision
{
	GraphicManager graphic_manager_;
	core::Vec2<float> midle_ = core::Vec2<float>(640.0f * 2 / 2, 480.0f * 2 / 2);
	int num_circles = 32;
	int big_circle_radius_ = 250;



	// Vector of circles (Body, Collider ?)
	// Change the colors while colliding
	// Check if and when colliding
	// Constructor of collision
	// Update pos of circles
	// Create circle

public:

	std::vector<std::pair<physic::Body, physic::CircleCollider>> circles_;

	Collision()
	{
		float angle_increment = 2 * M_PI / num_circles; // Angle between each circle
		float velocity_magnitude = -0.03f;                // Magnitude of initial velocity

		for (size_t i = 0; i < num_circles; ++i)
		{
			float angle = i * angle_increment;
			float x = midle_.x + big_circle_radius_ * std::cos(angle); // Calculate x position
			float y = midle_.y + big_circle_radius_ * std::sin(angle); // Calculate y position

			// Give each circle a velocity directed towards the center
			core::Vec2<float> velocity = core::Vec2<float>(
				-velocity_magnitude * std::cos(angle),
				-velocity_magnitude * std::sin(angle)
			);

			// Create the circle
			CreateCircle(core::Vec2<float>{x, y}, velocity, 15.0f, 20.0f); // Adjust mass and radius as needed
		}
	}

	void CreateCircle(const core::Vec2<float>& position, const core::Vec2<float>& velocity, float mass, float radius);
	void MoveCircle();
	void CheckCollisions();
};

#endif