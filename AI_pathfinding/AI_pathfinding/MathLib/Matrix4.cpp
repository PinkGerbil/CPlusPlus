#include "Matrix4.h"
#include <math.h>


Matrix4::Matrix4(float a_x, float a_y, float a_z, float a_w, float b_x, float b_y, float b_z, float b_w, float c_x, float c_y, float c_z, float c_w, float d_x, float d_y, float d_z, float d_w)
{
	xAxis = { a_x, a_y, a_z, a_w };
	yAxis = { b_x, b_y, b_z, b_w };
	zAxis = { c_x, c_y, c_z, c_w };
	translation = { d_x, d_y, d_z, d_w };
}

Matrix4::Matrix4()
{
}

const Matrix4 Matrix4::identity = Matrix4(1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1);

Vector4& Matrix4::operator[](int index)
{
	return axis[index];
}

const Vector4& Matrix4::operator[](int index) const
{
	return axis[index];
}

Matrix4 Matrix4::operator*(const Matrix4 & other) const
{
	Matrix4 result;
	for (int r = 0; r < 4; ++r) {
		for (int c = 0; c < 4; ++c) {
			result.data[c][r] = data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1] +
				data[2][r] * other.data[c][2] +
				data[3][r] * other.data[c][3];
		}
	}
	return result;
}

Vector4 Matrix4::operator*(const Vector4& v) const
{
	Vector4 result;
	result.data[0] = data[0][0] * v.data[0] + data[1][0] * v.data[1] + data[2][0] * v.data[2] + data[3][0] * v.data[3];
	result.data[1] = data[0][1] * v.data[0] + data[1][1] * v.data[1] + data[2][1] * v.data[2] + data[3][1] * v.data[3];
	result.data[2] = data[0][2] * v.data[0] + data[1][2] * v.data[1] + data[2][2] * v.data[2] + data[3][2] * v.data[3];
	result.data[3] = data[0][3] * v.data[0] + data[1][3] * v.data[1] + data[2][3] * v.data[2] + data[3][3] * v.data[3];
	return result;
}

Matrix4 Matrix4::transposed()
{
	Matrix4 result;

	for (int r = 0; r < 4; ++r) {
		for (int c = 0; c < 4; ++c) {
			result.data[r][c] = data[c][r];
		}
	}
	return result;
}

void Matrix4::setScaled(float x, float y, float z)
{
	xAxis = { x, 0, 0, 0 };
	yAxis = { 0, y, 0, 0 };
	zAxis = { 0, 0, z, 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::scale(const Vector4 & v)
{
	Matrix4 m;
	m.setScaled(v.m_x, v.m_y, v.m_z);

	*this = *this * m;
}

void Matrix4::setRotateX(float radians)
{
	xAxis = { 1, 0, 0 , 0 };
	yAxis = { 0, cosf(radians), sinf(radians), 0 };
	zAxis = { 0, -sinf(radians), cosf(radians), 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::rotateX(float radians)
{
	Matrix4 m;
	m.setRotateX(radians);

	*this = *this * m;
}

void Matrix4::setRotateY(float radians)
{
	xAxis = { cosf(radians), 0, -sinf(radians), 0 };
	yAxis = { 0, 1, 0, 0 };
	zAxis = { sinf(radians), 0, cosf(radians), 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::rotateY(float radians)
{
	Matrix4 m;
	m.setRotateY(radians);

	*this = *this * m;
}

void Matrix4::setRotateZ(float radians)
{
	xAxis = { cosf(radians), sinf(radians), 0, 0 };
	yAxis = { -sinf(radians), cosf(radians), 0, 0 };
	zAxis = { 0, 0, 1, 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::rotateZ(float radians)
{
	Matrix4 m;
	m.setRotateZ(radians);

	*this = *this * m;
}

void Matrix4::setEuler(float pitch, float yaw, float roll)
{
	Matrix4 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);

	*this = z * y * x;
}

Matrix4::~Matrix4()
{
}
