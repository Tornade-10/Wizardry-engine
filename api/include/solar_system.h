#ifndef API_SOLAR_SYSTEM_H
#define API_SOLAR_SYSTEM_H

#include <array>

#include "Body.h"
#include "GraphicManager.h"
#include "random"

class SolarSystem
{
private:
	GraphicManager graphic_manager_;
	std::vector<physic::Body> planets_;
	physic::Body sun_;
	float gravity_ = 0.0667f;

	core::Vec2<float> midle = core::Vec2<float>(640.0f * 2 / 2, 480.0f * 2 / 2);

	// Add gravity (0.0667f) V
	// Add a vector of planet/bodys V
	// Add a point for the rotation (Body with high mass and not in the update) V
	// Add a constructor (Sun, Starting planets) V
	// Add update of physics for the planets V

public:
	SolarSystem() : sun_(core::Vec2<float>{640.0f * 2 / 2, 480.0f * 2 / 2}, core::Vec2<float>{0.0f, -2.0f}, core::Vec2<float>{0.0f, 0.0f}, 1000.0f)
	{
		CreatePlanet(core::Vec2<float>{midle.x + 100, midle.y}, core::Vec2<float>{0.0f, 1.0f}, 150.0f);
		CreatePlanet(core::Vec2<float>{midle.x + 200, midle.y}, core::Vec2<float>{0.0f, 0.5f}, 150.0f);
		CreatePlanet(core::Vec2<float>{midle.x + 300, midle.y}, core::Vec2<float>{0.0f, 0.2f}, 200.0f);
		CreatePlanet(core::Vec2<float>{midle.x, midle.y - 100}, core::Vec2<float>{1.0f, 0.0f}, 200.0f);
		CreatePlanet(core::Vec2<float>{midle.x, midle.y - 200}, core::Vec2<float>{0.5f, 0.0f}, 150.0f);
		CreatePlanet(core::Vec2<float>{midle.x, midle.y - 300}, core::Vec2<float>{0.2f, 0.0f}, 150.0f);
	}

	void CreatePlanet(const core::Vec2<float>& position, const core::Vec2<float>& velocity, float mass); // Init
	void MovePlanet(); // Loop

	std::vector<physic::Body> planets()
	{
		return planets_;
	}
};

#endif // API_SOLAR_SYSTEM_H