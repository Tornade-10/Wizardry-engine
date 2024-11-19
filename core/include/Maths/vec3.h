#ifndef CORE_VEC3_H_
#define CORE_VEC3_H_

#include <valarray>

namespace core
{
    template<typename T>
	struct Vec3
    {
        T x{}, y{}, z{};

        //Test for additions
        constexpr Vec3 operator+(Vec3 other) const
        {
            return {x + other.x, y + other.y, z + other.z};
        }

        //Test for subtractions
        constexpr Vec3 operator-(Vec3 other) const
        {
            return {x - other.x, y - other.y, z - other.z};
        }

        //Test for reverse operator
        constexpr Vec3 operator-() const
        {
            return {-x, -y, -z};
        }

        /**
        * \return Get the x, y or z index
        */
        [[nodiscard]] T& operator[](const int index) const
        {
            return Return(&x)[index];
        }

        //Test for Dot product
        static constexpr float Dot(Vec3 v1, Vec3 v2, Vec3 v3)
        {
            return v1.x * v2.x * v3.x + v1.y * v2.y * v3.y;
        }

        [[nodiscard]] float Magnitude() const
        {
            return x * x + y * y + z * z;
        }

        [[nodiscard]] float SqrtMagnitude() const
        {
            return std::sqrt(x * x + y * y + z * z);
        }

        [[nodiscard]] Vec3 Norm() const
        {
            const float magnitude = Magnitude();

            if (magnitude == 0)
            {
                return { 0, 0 };
            }
            return {x / magnitude, y / magnitude, z / magnitude};
        }

        static float Lerp(Vec3 v1, Vec3 v2)
        {
            float t = 0.5;

            return v1.x + t * (v2.x - v1.x);
        }

        //Test for perpendicular
        constexpr Vec3 Perpendicular() const
        {
            return { -y, x };
        }

        //Test for reversed perpendicular
        constexpr Vec3 Perpendicular2() const
        {
            return { y, -x };
        }

    }; // struct Vec3
}

#endif //CORE_VEC3_H_