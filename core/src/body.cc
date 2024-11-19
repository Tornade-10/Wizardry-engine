#include <ctime>

#include "Body.h"

void physic::Body::TotalVelocity()
{
	velocity_ = velocity_ + acceleration;
}

void physic::Body::ApplyForce(core::Vec2<float> force)
{
	acceleration = force / mass_;
}

void physic::Body::UpdatePosition()
{
	TotalVelocity();

	// TODO : Add delta time
	position_.x += velocity_.x;
	position_.y += velocity_.y;
}
