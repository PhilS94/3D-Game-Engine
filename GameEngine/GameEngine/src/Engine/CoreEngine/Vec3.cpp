#include "Vec3.h"
#include <cmath>

namespace core {
	Vec3::Vec3() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Vec3::Vec3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vec3::~Vec3() {

	}

	float Vec3::length() {
		return sqrt(x*x + y*y + z*z);
	}

	float Vec3::max() {
		if (x < y) {
			if (y < z)
				return z;
			else return y;
		}
		else {
			if (x < z)
				return z;
			else return x;
		}
	}

	float Vec3::dot(const Vec3& v) const {
		return x*v.getX() + y*v.getY() + z*v.getZ();
	}

	Vec3* Vec3::cross(const Vec3& v)const {
		return &Vec3(y*v.getZ() - z* v.getY(), z*v.getX() - x*v.getZ(), x*v.getY() - y*v.getX());
	}

	void Vec3::normalize() {
		float length = this->length();
		x /= length;
		y /= length;
		z /= length;
	}

	Vec3* Vec3::normalized() {
		float length = this->length();
		return &Vec3(x / length, y / length, z / length);
	}

	Vec3* Vec3::rotate(const Vec3& axis, float angle) {
		float sinAngle = sin(-angle);
		float cosAngle = cos(-angle);
		return this->cross(axis.multiply(sinAngle)).add(this->multiply(cosAngle)).add(axis.multiply(this->dot(axis.multiply(1 - cosAngle))));
	}

	Vec3* Vec3::rotate(const Quaternion& q) {
		//TODO
	}

	Vec3* Vec3::lerp(const Vec3& dest, float lerp)const {
		return dest.subtract(this).multiply(lerp).add(this);
	}

	Vec3* Vec3::add(const Vec3& v)const {
		return &Vec3(x + v.getX(), y + v.getY(), z + v.getX());
	}

	Vec3* Vec3::subtract(const Vec3& v) const {
		return &Vec3(x - v.getX(), y - v.getY(), z - v.getX());
	}

	Vec3* Vec3::multiply(float value) const {
		return &Vec3(value *x, value*y, value*z);
	}

	std::string Vec3::toString() {
		return "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + ")";
	}

	float Vec3::getX() const { return x; }
	float Vec3::getY() const { return y; }
	float Vec3::getZ() const { return z; }

	float Vec3::setX(float x) {
		this->x = x;
	}
	float Vec3::setY(float y) {
		this->y = y;
	}
	float Vec3::setZ(float z) {
		this->z = z;
	}

	bool Vec3::equals(const Vec3& v)const {
		return x == v.getX() && y == v.getY() && z == v.getY();
	}
}