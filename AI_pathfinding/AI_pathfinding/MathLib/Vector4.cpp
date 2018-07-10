#include "Vector4.h"
#include <cmath>


Vector4::Vector4()
{
}

Vector4::Vector4(float x, float y, float z, float w) :m_x(x), m_y(y), m_z(z), m_w(w)
{
}

Vector4 Vector4::operator+(Vector4 other)
{
	return { m_x + other.m_x, m_y + other.m_y, m_z + other.m_z, m_w + other.m_w };
}

Vector4 Vector4::operator-(Vector4 other)
{
	return { m_x - other.m_x, m_y - other.m_y, m_z - other.m_z, m_w - other.m_w };
}

Vector4 Vector4::operator*(float scalar)
{
	return { m_x * scalar, m_y * scalar, m_z * scalar, m_w * scalar };
}

Vector4 operator*(float scalar, const Vector4 & other)
{
	return { other.m_x * scalar, other.m_y * scalar, other.m_z * scalar, other.m_w * scalar };
}

Vector4 Vector4::operator/(float scalar)
{
	return { m_x / scalar, m_y / scalar, m_z / scalar, m_w / scalar };
}

float Vector4::magnitude()
{
	return sqrtf((m_x * m_x) + (m_y * m_y) + (m_z * m_z) + (m_w * m_w));
}

void Vector4::normalise()
{
	float mag = magnitude();
	m_x /= mag;
	m_y /= mag;
	m_z /= mag;
	m_w /= mag;
}

Vector4 Vector4::cross(Vector4 other)
{
	//y*other.z - z*other.y
	//z*other.x - x*other.z
	//x*other.y - y*other.x
	return { m_y * other.m_z - m_z * other.m_y,
		m_z * other.m_x - m_x * other.m_z,
		m_x * other.m_y - m_y * other.m_x,
		0 };
}

float Vector4::dot(const Vector4 other)
{
	return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z + m_w * other.m_w;
}

Vector4::operator float*()
{
	return data;
}


Vector4::~Vector4()
{
}