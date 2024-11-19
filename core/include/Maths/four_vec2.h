#ifndef CORE_FOUR_VEC2_H_
#define CORE_FOUR_VEC2_H_

#include "Vec2.h"

namespace core
{
	template<typename T>
	struct FourVec2
	{
		std::array<T, 4> x{};
		std::array<T, 4> y{};

		FourVec2(std::array<Vec2<T>, 4>& array)
		{
			for (size_t i = 0; i < 4; i++)
			{
				x[i] = array[i].x;
				x[i] = array[i].y;
			}
		}

		constexpr FourVec2 operator+(FourVec2 other)
		{
			std::array<Vec2<T>, 4> four_vec2;
			for (size_t i = 0; i < 4; i++)
			{
				four_vec2.x = x[i] + other.x[i];
				four_vec2.y = y[i] + other.y[i];
			}
			return four_vec2;
		}

		constexpr FourVec2 operator-(FourVec2 other)
		{
			std::array<Vec2<T>, 4> four_vec2;
			for (size_t i = 0; i < 4; i++)
			{
				four_vec2.x = x[i] - other.x[i];
				four_vec2.y = y[i] - other.y[i];
			}
		}

		constexpr FourVec2 operator-(FourVec2 other)
		{
			std::array<Vec2<T>, 4> four_vec2;
			for (size_t i = 0; i < 4; i++)
			{
				four_vec2.x = -x[i];
				four_vec2.y = -y[i];
			}
		}

		constexpr FourVec2 operator*(FourVec2 other)
		{
			std::array<Vec2<T>, 4> four_vec2;
			for (size_t i = 0; i < 4; i++)
			{
				four_vec2.x = x[i] * other.x[i];
				four_vec2.y = y[i] * other.y[i];
			}
		}

		constexpr FourVec2 operator*(float scalar)
		{
			std::array<Vec2<T>, 4> four_vec2;
			for (size_t i = 0; i < 4; i++)
			{
				four_vec2.x = x[i] * scalar;
				four_vec2.y = y[i] * scalar;
			}
		}
	};
	//ForVec2f = ForVec2<float>;
}

#endif
