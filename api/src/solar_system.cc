#include "solar_system.h"

void SolarSystem::CreatePlanet(const core::Vec2<float>& position, const core::Vec2<float>& velocity, float mass)
{
    planets_.emplace_back(sun_);
	planets_.emplace_back(position, velocity, core::Vec2<float>{0.0f, 0.0f}, mass);
}

void SolarSystem::MovePlanet()
{
	for (auto& planet : planets_)
	{
        // Compute gravitational force between sun and planet
        core::Vec2<float> direction = sun_.position() - planet.position();
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        float force_magnitude = gravity_ * (sun_.mass() * planet.mass()) / (distance * distance);

        // Normalize direction and apply force
        core::Vec2<float> force = direction / distance * force_magnitude;
        planet.ApplyForce(force);
        planet.UpdatePosition(); // Update planet position
	}
}

