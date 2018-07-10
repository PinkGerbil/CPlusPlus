#include "Vector2.h"
#include <cmath>
#include <iostream>

Vector2::Vector2()
{
	m_x = 0;
	m_y = 0;
}

Vector2::Vector2(float x, float y)
{
	m_x = x;
	m_y = y;
}

Vector2 Vector2::operator+(Vector2 other)
{
	return { m_x + other.m_x, m_y + other.m_y };
}

Vector2 Vector2::operator-(Vector2 other)
{
	return { m_x - other.m_x, m_y - other.m_y };
}

Vector2 Vector2::operator*(float scalar)
{
	return { m_x * scalar, m_y * scalar };
}

Vector2 Vector2::operator/(float scalar)
{
	return { m_x / scalar, m_y / scalar };
}

Vector2 Vector2::operator+=(Vector2 other)
{
	return { m_x += other.m_x, m_y += other.m_y };
}

Vector2 Vector2::operator-=(Vector2 other)
{
	return { m_x -= other.m_x, m_y -= other.m_y };
}

Vector2 Vector2::operator*=(float scalar)
{
	return { m_x *= scalar, m_y *= scalar };
}

Vector2 Vector2::operator/=(float scalar)
{
	return { m_x /= scalar, m_y /= scalar };
}

float Vector2::magnitude()
{
	return sqrt(m_x * m_x + m_y * m_y);
}

void Vector2::normalise()
{
	float mag = sqrt(m_x * m_x + m_y * m_y);
	m_x /= mag;
	m_y /= mag;
}

Vector2 Vector2::cross(Vector2 other)
{
	return Vector2();
}

float Vector2::dot(const Vector2 other)
{
	return m_x * other.m_x + m_y * other.m_y;
}

Vector2 Vector2::getPerpendicularRH() const
{
	return { -m_y, m_x };
}

float Vector2::angleBetween(Vector2 & other)
{
	Vector2 a = normalized();
	Vector2 b = other.normalized();

	float d = a.m_x * b.m_x + a.m_y * b.m_y;

	return acos(d);
}

Vector2 operator*(float scalar, const Vector2 a_vec)
{
	return { a_vec.m_x * scalar, a_vec.m_y * scalar };
}

Vector2::operator float*()
{
	return data;
}

Vector2 Vector2::normalized() const
{
	float mag = sqrtf(m_x * m_x + m_y * m_y);
	return { m_x / mag, m_y / mag };
}

Vector2::~Vector2()
{
}

