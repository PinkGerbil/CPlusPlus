#include "Matrix2.h"
#include <cmath>


Matrix2::Matrix2()
{
}

Matrix2::Matrix2(float a_x, float a_y, float b_x, float b_y)
{
	xAxis = { a_x, a_y };
	yAxis = { b_x, b_y };
}

Matrix2::Matrix2(const Matrix2 & other)
{
	for (int r = 0; r < 2; r++) {
		for (int c = 0; c < 2; c++) {
			data[r][c] = other.data[r][c];
		}
	}
}

const Matrix2 Matrix2::identity()
{
	return Matrix2(1, 0,
		0, 1);
}

Vector2& Matrix2::operator[](int index)
{
	return axis[index];
}

const Vector2& Matrix2::operator[](int index) const
{
	return axis[index];
}

Matrix2& Matrix2::operator*(const Matrix2 & other) const
{
	Matrix2 result;
	for (int r = 0; r < 2; ++r) {
		for (int c = 0; c < 2; ++c) {
			result.data[c][r] = data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1];
		}
	}
	return result;
}

Vector2 Matrix2::operator*(const Vector2 & v) const
{
	Vector2 result;
	result.data[0] = data[0][0] * v.data[0] + data[1][0] * v.data[1];
	result.data[1] = data[0][1] * v.data[0] + data[1][1] * v.data[1];
	return result;
}

Matrix2 Matrix2::transposed() const
{
	Matrix2 result;

	for (int r = 0; r < 2; ++r) {
		for (int c = 0; c < 2; ++c) {
			result.data[r][c] = data[c][r];
		}
	}
	return result;
}

void Matrix2::setScaled(float x, float y)
{
	xAxis = { x, 0 };
	yAxis = { 0, y };
}

void Matrix2::scale(const Vector2 & v)
{
	Matrix2 m;
	m.setScaled(v.m_x, v.m_y);

	*this = *this * m;
}

void Matrix2::setRotate(float radians)
{
	xAxis = { cosf(radians), sinf(radians) };
	yAxis = { -sinf(radians), cosf(radians) };
}

void Matrix2::rotate(float radians)
{
	Matrix2 m;
	m.setRotate(radians);

	*this = *this * m;
}

Matrix2::~Matrix2()
{
}