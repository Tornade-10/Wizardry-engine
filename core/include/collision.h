#ifndef CORE_COLLISION_H_
#define CORE_COLLISION_H_

#include "Vec2.h"

namespace physic
{
	struct Collider
	{
		int x, y, w, h;

		Collider(int xPos, int yPos, int width, int height) : x(xPos), y(yPos), w(width), h(height) {}

		bool IsOverlapping(const Collider& other) const
		{
			return !(x + w <= other.x ||   // No overlap on the left
				x >= other.x + other.w ||  // No overlap on the right
				y + h <= other.y ||        // No overlap above
				y >= other.y + other.h);   // No overlap below
		}

		core::Vec2<int> GetMin() const
		{
			return { x, y };
		}

		core::Vec2<int> GetMax() const
		{
			return { x + w, y + h };
		}

		core::Vec2<int> GetCenter() const
		{
			return { x + w / 2, y + h / 2 };
		}

		void Move(int dx, int dy)
		{
			x += dx;
			y += dy;
		}
	};
}

#endif