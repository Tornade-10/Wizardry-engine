#ifndef CORE_COLLISION_GRID_H
#define CORE_COLLISION_GRID_H

#include <iostream>
#include <vector>

#include "collision.h"

namespace physic
{
	struct AABBManager
	{
	public:
		// Register a collider in the system
		void AddCollider(Collider* collider)
		{
			colliders.push_back(collider);
		}

		// Update the system and check for collisions between all AABBs
		void Update()
		{
			for (size_t i = 0; i < colliders.size(); ++i) {
				for (size_t j = i + 1; j < colliders.size(); ++j) {
					if (colliders[i]->IsOverlapping(*colliders[j])) {
						std::cout << "Collision detected between AABB " << i << " and AABB " << j << std::endl;
					}
				}
			}
		}

	private:
		std::vector<Collider*> colliders; // List of AABBs (Colliders) in the system
	};
}

#endif