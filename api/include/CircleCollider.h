#ifndef API_COLLIDER_H
#define API_COLLIDER_H

#include "Maths/Vec2.h"

namespace physic
{
	struct CircleCollider
	{
	public:
		// TODO : add; collider_size, collider_pos

		core::Vec2<float> position_;
		float radius_;
		bool is_colliding = false;

		CircleCollider(core::Vec2<float> position, float radius) : position_(position), radius_(radius){}

		bool Colliding(const CircleCollider& other);
	};
}

#endif