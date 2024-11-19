#ifndef CORE_FORCE_H_
#define CORE_FORCE_H_

#include "Maths/Vec2.h"

namespace physic
{
	struct Body
	{
	// TODO : Struct body with in it : TotalForce; Velocity; Position

	private:
		//TODO : Vec2 Pos; Vec2 Velocity; float Mass; Collisions collision
		core::Vec2<float> position_;
		core::Vec2<float> velocity_;
		core::Vec2<float> acceleration;
		float mass_;

		void TotalVelocity();

	public:

		Body(core::Vec2<float> position_, core::Vec2<float> velocity_, core::Vec2<float> accelration_, float mass_) : position_(position_), velocity_(velocity_), acceleration(accelration_), mass_(mass_) {}

		void ApplyForce(core::Vec2<float> force);
		void UpdatePosition();

		core::Vec2<float> position() const
		{
			return position_;
		}
		void set_position(core::Vec2<float> new_pos)
		{
			position_ = new_pos;
		}

		core::Vec2<float> velocity()
		{
			return velocity_;
		}
		float mass() 
		{
			return mass_;
		}
	};
}

#endif