#include "Quaternion.h"

Quaternion::Quaternion() {
	this->x = 1;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}
Quaternion::Quaternion(float x, float y, float z, float w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}
Quaternion::Quaternion(const Vec3& axis, float angle) {
	float sinHalfAngle = sin(angle / 2);
	float cosHalfAngle = cos(angle / 2);

	this->x = axis.getX() * sinHalfAngle;
	this->y = axis.getY() * sinHalfAngle;
	this->z = axis.getZ() * sinHalfAngle;
	this->w = cosHalfAngle;
}

Quaternion::~Quaternion() {

}

float Quaternion::length() {
	return sqrt(x*x + y*y + z*z + w*w);
}

Quaternion Quaternion::normalized() {
	float length = this->length();
	return Quaternion(x / length, y / length, z / length, w / length);
}

Quaternion Quaternion::conjugate() {
	return Quaternion(-x, -y, -z, w);
}

Quaternion Quaternion::mul(const Quaternion& q) const {
	float newX = x * q.getW() + w * q.getX() + y * q.getZ() - z * q.getY();
	float newY = y * q.getW() + w * q.getY() + z * q.getX() - x * q.getZ();
	float newZ = z * q.getW() + w * q.getZ() + x * q.getY() - y * q.getX();
	float newW = w * q.getW() - x * q.getX() - y * q.getY() - z * q.getZ();

	return Quaternion(newX, newY, newZ, newW);
}

Quaternion Quaternion::mul(float value) const {
	return Quaternion(x*value, y*value, z*value, w*value);
}

/*
Quaternion Quaternion::mul(const Vec3& v) const {
	//TODO
	return NULL;
}

Matrix4 Quaternion::toRotationMatrix() const {
	//TODO
	return NULL;
}
float Quaternion::dot(const Quaternion& q) const {
	return x* q.getX() + y*q.getY() + z*q.getZ() + w*q.getW();
}

Quaternion Quaternion::nlerp(const Quaternion& dest, float lerpFactor, bool shortest) const {
	//TODO
	return NULL;
}
Quaternion Quaternion::SLerp(const Quaternion& dest, float lerpFactor, bool shortest) const {
	//TODO
	return NULL;
}

Quaternion toRotationMatrix(const Matrix4& rot) {
	//TODO
	return NULL;
}
*/
Vec3 Quaternion::getForward()const {
	return Vec3(0, 0, 1).rotate(*this);;
}
Vec3 Quaternion::getBack() const {
	return Vec3(0, 0, -1).rotate(*this);
}
Vec3 Quaternion::getUp() const {
	return Vec3(0, 1, 0).rotate(*this);
}
Vec3 Quaternion::getDown() const {
	return Vec3(0, -1, 0).rotate(*this);
}
Vec3 Quaternion::getRight() const {
	return Vec3(1, 0, 0).rotate(*this);
}
Vec3 Quaternion::getLeft()const {
	return Vec3(-1, 0, 0).rotate(*this);
}

float Quaternion::getX() const { return x; }
float Quaternion::getY() const { return y; }
float Quaternion::getZ() const { return z; }
float Quaternion::getW() const { return w; }

bool Quaternion::equals(const Quaternion& q) const {
	return x == q.getX() && y == q.getY() && z == q.getZ() && w == q.getW();
}