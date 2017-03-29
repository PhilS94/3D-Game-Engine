#pragma once

#include "Vec3.h";
#include "Quaternion.h";
namespace core {
	class Matrix4
	{
	public:
		Matrix4();
		~Matrix4();
		Matrix4 initIdentity();
		Matrix4 initTranslation();
		Matrix4 initRotation();
		Matrix4 initRotation();
		Matrix4 initRotation();
		Matrix4 initScale();
		Matrix4 initPerspective();
		Matrix4 initOrthographic();

		Vec3 multiply(Vec3 v);
		Matrix4 multiply(Matrix4 N);

		float[][] getM();
		float get(int x, int y);
		void set(int x, int y, float value);
	private:
		float m[4][4];
	};
}