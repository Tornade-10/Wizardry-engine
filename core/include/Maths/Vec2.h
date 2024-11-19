#ifndef CORE_VEC2_H_
#define CORE_VEC2_H_

#include <valarray>

namespace core
{
    template<typename T>
	struct Vec2
    {
        T x{}, y{};

        //Test for additions
        constexpr Vec2 operator+(Vec2 other) const
        {
            return {x + other.x, y + other.y};
        }

        //Test for subtractions
        constexpr Vec2 operator-(Vec2 other) const
        {
            return {x - other.x, y - other.y};
        }

        //Test for reverse operator
        constexpr Vec2 operator-() const
        {
            return {-x, -y};
        }

    	/**
        * \return Get the x or y index
        */
        [[nodiscard]] T operator[](const int index) const
        {
            return (&x)[index];
        }

        constexpr Vec2 operator*(T scalar) const
        {
            return { x * scalar, y * scalar };
        }

        constexpr Vec2 operator/(T scalar) const
        {
            return { x / scalar, y / scalar };
        }

        //Test for Dot product
        static constexpr T Dot(Vec2 v1, Vec2 v2)
        {
            return v1.x * v2.x + v1.y * v2.y;
        }

        [[nodiscard]] T Magnitude() const
        {
            return x * x + y * y;
        }

        [[nodiscard]] T SqrtMagnitude() const
    	requires std::is_floating_point_v<T>
        {
            return std::sqrt(x * x + y * y);
        }

        //add a "description"
        /**
         * \return if the vector is zero-length return zero
         */
        [[nodiscard]] Vec2 Norm() const
        {
            const float magnitude = Magnitude();

            if (magnitude == 0)
            {
                return { 0, 0 };
            }
            return {x / magnitude, y / magnitude};
        }

        static T Lerp(Vec2 v1, Vec2 v2, T t)
        {
            return v1.x + t * (v2.x - v1.x);
        }

        //Test for perpendicular
        constexpr Vec2 Perpendicular() const
        {
            return { -y, x };
        }

        //Test for reversed perpendicular
        constexpr Vec2 Perpendicular2() const
        {
            return { y, -x };
        }

    }; // struct Vec2
}

#endif