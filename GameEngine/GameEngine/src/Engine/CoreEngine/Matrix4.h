#pragma once

#include "Vec3.h";
#include "Quaternion.h";

namespace core {
	class Matrix4
	{
	public:
		Matrix4();
		~Matrix4();
		Matrix4* initIdentity();
		Matrix4* initTranslation(float x, float y, float z);
		//Matrix4 initRotation(float x, float y, float z);
		Matrix4* initRotation(Vec3 forward, Vec3 up);
		Matrix4* initRotation(Vec3 forward, Vec3 up, Vec3 right);
		Matrix4* initScale(float x, float y, float z);
		Matrix4* initPerspective(float fov, float aspect, float zNear, float zFar);
		Matrix4* initOrthographic(float left, float right, float bottom, float top, float near, float far);

		Vec3* multiply(Vec3 v);
		Matrix4* multiply(Matrix4 N);

		float** getM();
		float get(int x, int y);
		void set(int x, int y, float value);
	private:
		float** m;
	};
}