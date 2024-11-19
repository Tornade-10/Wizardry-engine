#ifndef API_AABB_SYSTEM_H
#define API_AABB_SYSTEM_H
#include <unordered_map>
#include <vector>

#include "Body.h"

namespace physic
{
	struct AABB
	{
		float minX, minY;
		float maxX, maxY;

		bool overlaps(const AABB& other) const
		{
			return !(maxX < other.minX 
				|| minX > other.maxX 
				|| maxY < other.minY 
				|| minY > other.maxY);
		}
	};

	class AABBManager
	{
		std::unordered_map<Body*, AABB> bodyToAABB;

	public:
		AABB CalculateAABB(const physic::Body& body, float size)
		{
			const auto& pos = body.position();
			return {
				pos.x - size / 2,
				pos.y - size / 2,
				pos.x + size / 2,
				pos.y + size / 2
			};
		}

		void AddBody(Body* body, float size)
		{
			bodyToAABB[body] = CalculateAABB(*body, size);
		}

		void UpdateAABBs(float size)
		{
			for (auto& [body, aabb] : bodyToAABB)
			{
				aabb = CalculateAABB(*body, size);
			}
		}
		std::vector<std::pair<Body*, Body*>> DetectCollisions()
		{
			std::vector<std::pair<Body*, Body*>> collisions;

			for (auto it1 = bodyToAABB.begin(); it1 != bodyToAABB.end(); ++it1)
			{
				for (auto it2 = std::next(it1); it2 != bodyToAABB.end(); ++it2)
				{
					if (it1->second.overlaps(it2->second))
					{
						collisions.emplace_back(it1->first, it2->first);
					}
				}
			}

			return collisions;
		}

		void ResolveCollisions()
		{
			// Detect collisions first
			auto collisions = DetectCollisions();

			// Resolve each collision
			for (const auto& [body1, body2] : collisions)
			{
				// For simplicity, apply a basic "push apart" response
				auto delta = body1->position() - body2->position();
				float distance = delta.SqrtMagnitude();
				float overlap = 10.0f - distance; // Assuming size = 10.0f, adjust as needed

				// Only resolve if there's overlap
				if (distance != 0.0f && overlap > 0.0f)
				{
					// Normalize the delta vector
					delta = delta / distance;

					// Move the bodies apart by half the overlap
					body1->set_position(body1->position() + delta * (overlap / 2));
					body2->set_position(body2->position() - delta * (overlap / 2));

					// Optionally, adjust velocities for bounce (simple elastic collision response)
					// This can be expanded based on physical laws or desired behavior
					auto relativeVelocity = body1->velocity() - body2->velocity();
					float velocityAlongNormal = relativeVelocity.x * delta.x + relativeVelocity.y * delta.y;

					if (velocityAlongNormal < 0) // Check if they are moving towards each other
					{
						// Apply a basic elastic collision response (no friction, just bouncing)
						float restitution = 0.8f; // Coefficient of restitution (bounciness)
						float impulse = -(1 + restitution) * velocityAlongNormal;
						impulse /= (1 / body1->mass() + 1 / body2->mass());

						core::Vec2<float> impulseVector = delta * impulse;
						body1->ApplyForce(impulseVector);
						body2->ApplyForce(-impulseVector);
					}
				}
			}
		}
	};
}

#endif
