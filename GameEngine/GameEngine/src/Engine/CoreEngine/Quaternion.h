#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vec3.h"
#include "Matrix4.h"

class Quaternion
{
public:
	Quaternion();
	Quaternion(float x, float y, float z, float w);
	Quaternion(const Vec3& axis, float angle);
	~Quaternion();

	float length();
	Quaternion normalized();
	Quaternion conjugate();
	Quaternion mul(const Quaternion& q) const;
	Quaternion mul(float value)const;
	Quaternion mul(const Vec3& v)const;
	Matrix4 toRotationMatrix()const;
	float dot(const Quaternion& q)const;
	Quaternion nlerp(const Quaternion& dest, float lerpFactor, bool shortest)const;
	Quaternion SLerp(const Quaternion& dest, float lerpFactor, bool shortest)const;
	Quaternion toRotationMatrix(const Matrix4& rot)const;

	Vec3 getForward()const;
	Vec3 getBack()const;
	Vec3 getUp()const;
	Vec3 getDown()const;
	Vec3 getRight()const;
	Vec3 getLeft()const;

	float getX()const;
	float getY()const;
	float getZ()const;
	float getW()const;
	bool equals(const Quaternion& q)const;

private:
	float x;
	float y;
	float z;
	float w;
};
#endif