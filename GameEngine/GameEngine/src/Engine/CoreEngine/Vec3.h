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
		float dot(Vec3 v);
		Vec3 cross(Vec3 v);
		Vec3 normalized();
		Vec3 rotate(Vec3 axis, float angle);
		Vec3 rotate(Quaternion q);
		Vec3 lerp(Vec3 dest, float lerp);

		Vec3 add(Vec3 v);
		Vec3 subtract(Vec3 v);
		Vec3 multiply(Vec3 v);
		Vec3 multiply(float value);
		Vec3 add(Vec3 v);
		Vec3 add(Vec3 v);

		std::string Vec3::toString();

		float getX();
		float getY();
		float getZ();

		float setX(float x);
		float setY(float y);
		float setZ(float z);

		bool equals(Vec3 v);
	private:
		float x;
		float y;
		float z;
	};
}