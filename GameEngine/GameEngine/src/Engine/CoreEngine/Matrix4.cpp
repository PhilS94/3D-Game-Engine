#include "Matrix4.h"

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

Matrix4& Matrix4::initIdentity() {
	m[0][0] = 1;	m[0][1] = 0;	m[0][2] = 0;	m[0][3] = 0;
	m[1][0] = 0;	m[1][1] = 1;	m[1][2] = 0;	m[1][3] = 0;
	m[2][0] = 0;	m[2][1] = 0;	m[2][2] = 1;	m[2][3] = 0;
	m[3][0] = 0;	m[3][1] = 0;	m[3][2] = 0;	m[3][3] = 1;
	return *this;
}

Matrix4& Matrix4::initTranslation(float x, float y, float z) {
	m[0][0] = 1;	m[0][1] = 0;	m[0][2] = 0;	m[0][3] = x;
	m[1][0] = 0;	m[1][1] = 1;	m[1][2] = 0;	m[1][3] = y;
	m[2][0] = 0;	m[2][1] = 0;	m[2][2] = 1;	m[2][3] = z;
	m[3][0] = 0;	m[3][1] = 0;	m[3][2] = 0;	m[3][3] = 1;

	return *this;
}

//Matrix4 initRotation(float x, float y, float z);

Matrix4& Matrix4::initRotation(Vec3 forward, Vec3 up) {
	return initRotation(forward.normalized(), up.normalized(), forward.cross(up).normalized());
}

Matrix4& Matrix4::initRotation(Vec3 forward, Vec3 up, Vec3 right) {

	m[0][0] = right.getX();		m[0][1] = right.getY();		m[0][2] = right.getZ();		m[0][3] = 0;
	m[1][0] = up.getX();		m[1][1] = up.getY();		m[1][2] = up.getZ();		m[1][3] = 0;
	m[2][0] = forward.getX();	m[2][1] = forward.getY();	m[2][2] = forward.getZ();	m[2][3] = 0;
	m[3][0] = 0;				m[3][1] = 0;				m[3][2] = 0;				m[3][3] = 1;

	return *this;
}
Matrix4& Matrix4::initScale(float x, float y, float z) {
	m[0][0] = x;	m[0][1] = 0;	m[0][2] = 0;	m[0][3] = 0;
	m[1][0] = 0;	m[1][1] = y;	m[1][2] = 0;	m[1][3] = 0;
	m[2][0] = 0;	m[2][1] = 0;	m[2][2] = z;	m[2][3] = 0;
	m[3][0] = 0;	m[3][1] = 0;	m[3][2] = 0;	m[3][3] = 1;

	return *this;
}
Matrix4& Matrix4::initPerspective(float fov, float aspect, float zNear, float zFar) {
	float tanHalfFOV = tan(fov / 2);
	float zRange = zNear - zFar;

	m[0][0] = 1.0f / (tanHalfFOV * aspect);	m[0][1] = 0;					m[0][2] = 0;						m[0][3] = 0;
	m[1][0] = 0;							m[1][1] = 1.0f / tanHalfFOV;	m[1][2] = 0;						m[1][3] = 0;
	m[2][0] = 0;							m[2][1] = 0;					m[2][2] = (-zNear - zFar) / zRange;	m[2][3] = 2 * zFar * zNear / zRange;
	m[3][0] = 0;							m[3][1] = 0;					m[3][2] = 1;						m[3][3] = 0;


	return *this;
}
Matrix4& Matrix4::initOrthographic(float left, float right, float bottom, float top, float near, float far) {
	float width = right - left;
	float height = top - bottom;
	float depth = far - near;

	m[0][0] = 2 / width; m[0][1] = 0;			m[0][2] = 0;			m[0][3] = -(right + left) / width;
	m[1][0] = 0;		m[1][1] = 2 / height;	m[1][2] = 0;			m[1][3] = -(top + bottom) / height;
	m[2][0] = 0;		m[2][1] = 0;			m[2][2] = -2 / depth;	m[2][3] = -(far + near) / depth;
	m[3][0] = 0;		m[3][1] = 0;			m[3][2] = 0;			m[3][3] = 1;

	return *this;
}

Vec3 Matrix4::multiply(const Vec3& v)const {
	return Vec3(m[0][0] * v.getX() + m[0][1] * v.getY() + m[0][2] * v.getZ() + m[0][3],
		m[1][0] * v.getX() + m[1][1] * v.getY() + m[1][2] * v.getZ() + m[1][3],
		m[2][0] * v.getX() + m[2][1] * v.getY() + m[2][2] * v.getZ() + m[2][3]);
}

Matrix4 Matrix4::multiply(const Matrix4& N)const {
	Matrix4 result = Matrix4();

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.set(i, j, m[i][0] * N.get(0, j) +
				m[i][1] * N.get(1, j) +
				m[i][2] * N.get(2, j) +
				m[i][3] * N.get(3, j));
		}
	}
	return result;
}

float** Matrix4::getM() const {
	return m;
}

float Matrix4::get(int x, int y)const {
	return m[x][y];
}

void Matrix4::set(int x, int y, float value) {
	m[x][y] = value;
}
