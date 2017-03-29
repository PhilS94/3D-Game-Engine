#ifndef MATRIX4_H
#define MATRIX4_H

#include "Vec3.h"

class Matrix4
{
public:
	Matrix4();
	~Matrix4();
	Matrix4& initIdentity();
	Matrix4& initTranslation(float x, float y, float z);
	//Matrix4 initRotation(float x, float y, float z);
	Matrix4& initRotation(Vec3 forward, Vec3 up);
	Matrix4& initRotation(Vec3 forward, Vec3 up, Vec3 right);
	Matrix4& initScale(float x, float y, float z);
	Matrix4& initPerspective(float fov, float aspect, float zNear, float zFar);
	Matrix4& initOrthographic(float left, float right, float bottom, float top, float near, float far);

	Vec3 multiply(const Vec3& v)const;
	Matrix4 multiply(const Matrix4& N) const;

	float** getM() const;
	float get(int x, int y) const;
	void set(int x, int y, float value);

private:
	float** m;
};
#endif // !MATRIX4_H