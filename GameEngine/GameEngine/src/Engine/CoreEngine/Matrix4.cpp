#include "Matrix4.h"

namespace core {

	Matrix4::Matrix4() {
		m = new float*[4];
		for (int i = 0; i < 4; i++)
			m[i] = new float[4];
	}

	Matrix4::~Matrix4() {
		for (int i = 0; i < 4; i++)
			delete m[i];

		delete m;
	}

	Matrix4* Matrix4::initIdentity() {
		m[0][0] = 1;	m[0][1] = 0;	m[0][2] = 0;	m[0][3] = 0;
		m[1][0] = 0;	m[1][1] = 1;	m[1][2] = 0;	m[1][3] = 0;
		m[2][0] = 0;	m[2][1] = 0;	m[2][2] = 1;	m[2][3] = 0;
		m[3][0] = 0;	m[3][1] = 0;	m[3][2] = 0;	m[3][3] = 1;

		return this;
	}

	Matrix4* Matrix4::initTranslation(float x, float y, float z);
	//Matrix4 initRotation(float x, float y, float z);
	Matrix4* Matrix4::initRotation(Vec3 forward, Vec3 up);
	Matrix4* Matrix4::initRotation(Vec3 forward, Vec3 up, Vec3 right);
	Matrix4* Matrix4::initScale(float x, float y, float z);
	Matrix4* Matrix4::initPerspective(float fov, float aspect, float zNear, float zFar);
	Matrix4* Matrix4::initOrthographic(float left, float right, float bottom, float top, float near, float far);

	Vec3* Matrix4::multiply(Vec3 v);
	Matrix4* Matrix4::multiply(Matrix4 N);

	float** Matrix4::getM() {
		return m;
	}

	float Matrix4::get(int x, int y) {
		return m[x][y];
	}

	void Matrix4::set(int x, int y, float value) {
		m[x][y] = value;
	}
}