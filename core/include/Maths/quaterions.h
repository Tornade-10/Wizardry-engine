#ifndef CORE_QUATERIONS_H
#define CORE_QUATERIONS_H

#include "vec4.h"

namespace core
{
	template<typename T>
	struct Quaternion : public Vec4<T>
	{
		Quaternion(T w, T x, T y, T z) : Vec4<T>(w, x, y, z) {}

		Quaternion Conjugate() const
		{
			return Quaternion(w, -x, -y, -z); // Conjugate of the quaternion
		}

		constexpr Quaternion operator*(const Quaternion& q) const
		{
			return {
				w * q.w - x * q.x - y * q.y - z * q.z, // Real part
				w * q.x + x * q.w + y * q.z - z * q.y, // x component
				w * q.y - x * q.z + y * q.w + z * q.x, // y component
				w * q.z + x * q.y - y * q.x + z * q.w  // z component
			};
		}



	};
}

#endif