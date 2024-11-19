#ifndef CORE_MATHS_VEC4_H_
#define CORE_MATHS_VEC4_H_

#include <valarray>

namespace core
{
    template<typename T>
	struct Vec4
    {
        T x{}, y{}, z{}, w{};

        //Test for additions
        constexpr Vec4 operator+(Vec4 other) const
        {
            return {x + other.x, y + other.y, z + other.z, w + other.w};
        }

        //Test for subtractions
        constexpr Vec4 operator-(Vec4 other) const
        {
            return { x - other.x, y - other.y, z - other.z, w - other.w };
        }

        //Test for reverse operator
        constexpr Vec4 operator-() const
        {
            return {-x, -y, -z, -w};
        }

        /**
        * \return Get the x, y, z or w index
        */
        [[nodiscard]] T& operator[](const int index) const
        {
            return Return(&x)[index];
        }

        //Test for Dot product
        static constexpr float Dot(Vec4 v1, Vec4 v2)
        {
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
        }

        [[nodiscard]] float Magnitude() const
        {
            return x * x + y * y + z * z + w * w;
        }

        [[nodiscard]] float SqrtMagnitude() const
        {
            return std::sqrt(x * x + y * y + z * z + w * w);
        }

        [[nodiscard]] Vec4 Norm() const
        {
            const float magnitude = Magnitude();

            if (magnitude == 0)
            {
                return { 0, 0 };
            }
            return {x / magnitude, y / magnitude};
        }

        static float Lerp(Vec4 v1, Vec4 v2)
        {
            float t = 0.5;

            return v1.x + t * (v2.x - v1.x);
        }

        //Test for perpendicular
        constexpr Vec4 Perpendicular() const
        {
            return { -y, x };
        }

        //Test for reversed perpendicular
        constexpr Vec4 Perpendicular2() const
        {
            return { y, -x };
        }

    }; // struct Vec2f
}

#endif //CORE_MATHS_VEC2F_H_