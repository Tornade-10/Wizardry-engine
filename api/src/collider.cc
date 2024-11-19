#include <iostream>

#include "CircleCollider.h"

bool physic::CircleCollider::Colliding(const CircleCollider& other)
{
    float dx = position_.x - other.position_.x;
    float dy = position_.y - other.position_.y;
    float distance_squared = dx * dx + dy * dy;
    float radius_sum = radius_ + other.radius_;
    return distance_squared <= radius_sum * radius_sum;
}
