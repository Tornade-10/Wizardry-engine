#ifndef CORE_MAT2_H_
#define CORE_MAT2_H_

#include "Vec2.h"
#include <array>

namespace core
{
	template<typename T>
	struct Mat2
	{
		std::array<Vec2<T>, 2> matrix_;

		//TODO : Make everything work with the array of vectors

		constexpr Mat2 operator+(Mat2& other) const
		{
			Mat2 result;

			for (size_t x = 0; x < 2; x++)
			{
				for (size_t y = 0; y < 2; y++)
				{
					result.matrix_[x, y] = matrix_[x, y] + other.matrix_[x, y];
				}
			}

			return result;
		}

		constexpr Mat2 operator*(Mat2 other) const
		{
			Mat2 result;

			for (size_t x = 0; x < 2; x++)
			{
				for (size_t y = 0; y < 2; y++)
				{
					result.matrix_[x, y] = matrix_[x, y] + other.matrix_[x, y];
				}
			}

			return result;
		}

		[[nodiscard]] constexpr Mat2 Scalar() const
		{
			Mat2 result;

			for (int x = 0; x < 2; x++)
			{
				for (int y = 0; y < 2; y++)
				{
					result.matrix_[x, y] = matrix_[x, y] * 2;
				}
			}

			return result;
		}


	};
}

#endif