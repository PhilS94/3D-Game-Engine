#ifndef VEC3_H
#define VEC3_H

#include <string>

class Quaternion;	//forward declaration because Quaternion and Vec3 depend on eachother
class Vec3
{
public:
	Vec3();
	Vec3(float x, float y, float z);
	~Vec3();

	float length() const;
	float max() const;
	float dot(const Vec3& v)const;
	Vec3 cross(const Vec3& v)const;
	void normalize();
	Vec3 normalized();
	Vec3 rotate(const Vec3& axis, float angle)const;
	Vec3 rotate(const Quaternion& q)const;
	Vec3 lerp(const Vec3& dest, float lerp)const;

	Vec3 add(const Vec3& v)const;
	Vec3 subtract(const Vec3& v)const;
	Vec3 multiply(float value)const;

	std::string Vec3::toString();

	float getX()const;
	float getY()const;
	float getZ()const;

	void setX(float x);
	void setY(float y);
	void setZ(float z);

	bool equals(const Vec3& v)const;
private:
	float x;
	float y;
	float z;
};
#endif // !VEC3_H