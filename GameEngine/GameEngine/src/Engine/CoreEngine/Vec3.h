#pragma once
#include <string>
#include "Quaternion.h"

namespace core {
	class Vec3
	{
	public:
		Vec3();
		Vec3(float x, float y, float z);
		~Vec3();

		float length();
		float max();
		float dot(const Vec3& v)const;
		Vec3* cross(const Vec3& v)const;
		void normalize();
		Vec3* normalized();
		Vec3* rotate(const Vec3& axis, float angle);
		Vec3* rotate(const Quaternion& q);
		Vec3* lerp(const Vec3& dest, float lerp)const;

		Vec3* add(const Vec3& v)const;
		Vec3* subtract(const Vec3& v)const;
		Vec3* multiply(float value)const;
		Vec3* add(const Vec3& v)const;
		Vec3* add(const Vec3& v)const;

		std::string Vec3::toString();

		float getX()const;
		float getY()const;
		float getZ()const;

		float setX(float x);
		float setY(float y);
		float setZ(float z);

		bool equals(const Vec3& v)const;
	private:
		float x;
		float y;
		float z;
	};
}