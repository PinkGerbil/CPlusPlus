#include "Matrix3.h"
#include <cmath>



Matrix3::Matrix3()
{

}

Matrix3::Matrix3(float a_x, float a_y, float a_z, float b_x, float b_y, float b_z, float c_x, float c_y, float c_z)
{
	xAxis = { a_x, a_y, a_z };
	yAxis = { b_x, b_y, b_z };
	zAxis = { c_x, c_y, c_z };
}

const Matrix3 Matrix3::identity = Matrix3(1, 0, 0,
									      0, 1, 0,
										  0, 0, 1);

Vector3& Matrix3::operator[](int index)
{
	return axis[index];
}

const Vector3& Matrix3::operator[](int index) const
{
	return axis[index];
}

Matrix3 Matrix3::operator*(const Matrix3 & other) const
{
	Matrix3 result;
	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			result.data[c][r] = data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1] +
				data[2][r] * other.data[c][2];
		}
	}
	return result;
}

Vector3 Matrix3::operator*(const Vector3& v) const
{
	Vector3 result;
	result.data[0] = data[0][0] * v.data[0] + data[1][0] * v.data[1] + data[2][0] * v.data[2];
	result.data[1] = data[0][1] * v.data[0] + data[1][1] * v.data[1] + data[2][1] * v.data[2];
	result.data[2] = data[0][2] * v.data[0] + data[1][2] * v.data[1] + data[2][2] * v.data[2];
	return result;
}

Matrix3 Matrix3::createTranlation(float c_x, float c_y, float c_z)
{
	return Matrix3();
}

Matrix3 Matrix3::createRotation(float a_rot)
{
	return Matrix3();
}

Matrix3 Matrix3::createScale(float xscale, float yscale)
{
	return Matrix3();
}

Matrix3 Matrix3::transposed()
{
	Matrix3 result;

	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			result.data[r][c] = data[c][r];
		}
	}
	return result;
}

void Matrix3::setScaled(float x, float y, float z)
{
	xAxis = { x, 0, 0 };
	yAxis = { 0, y, 0 };
	zAxis = { 0, 0, z };
}

void Matrix3::scale(const Vector3 & v)
{
	Matrix3 m;
	m.setScaled(v.m_x, v.m_y, v.m_z);

	*this = *this * m;
}

void Matrix3::setRotateX(float radians)
{
	xAxis = { 1, 0, 0 };
	yAxis = { 0, cosf(radians), sinf(radians) };
	zAxis = { 0, -sinf(radians), cosf(radians) };
}

void Matrix3::rotateX(float radians)
{
	Matrix3 m;
	m.setRotateX(radians);

	*this = *this * m;
}

void Matrix3::setRotateY(float radians)
{
	xAxis = { cosf(radians), 0, -sinf(radians) };
	yAxis = { 0, 1, 0 };
	zAxis = { sinf(radians), 0, cosf(radians) };
}

void Matrix3::rotateY(float radians)
{
	Matrix3 m;
	m.setRotateY(radians);

	*this = *this * m;
}

void Matrix3::setRotateZ(float radians)
{
	xAxis = { cosf(radians), sinf(radians), 0 };
	yAxis = { -sinf(radians), cosf(radians), 0 };
	zAxis = { 0, 0, 1 };
}

void Matrix3::rotateZ(float radians)
{
	Matrix3 m;
	m.setRotateZ(radians);

	*this = *this * m;
}

void Matrix3::translate(float x, float y, float z)
{
	translation += Vector3(x, y, z);
}

void Matrix3::setEuler(float pitch, float yaw, float roll)
{
	Matrix3 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);

	*this = z * y * x;
}

Matrix3::~Matrix3()
{
}
