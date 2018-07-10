#include "Vector3.h"
#include <cmath>


Vector3::Vector3()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

Vector3::Vector3(float x, float y, float z) :m_x(x), m_y(y), m_z(z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

Vector3 Vector3::operator+(Vector3 other)
{
	return { m_x + other.m_x, m_y + other.m_y, m_z + other.m_z };
}

Vector3 Vector3::operator-(Vector3 other)
{
	return { m_x - other.m_x, m_y - other.m_y, m_z - other.m_z };
}

Vector3 Vector3::operator*(float scalar)
{
	return { m_x * scalar, m_y * scalar, m_z * scalar };
}

Vector3 Vector3::operator*(Vector3 other)
{
	return { m_x * other.m_x, m_y * other.m_y, m_z * other.m_z };
}

Vector3 operator*(const Vector3 & other, float scalar)
{
	return { other.m_x * scalar, other.m_y * scalar, other.m_z * scalar };
}

Vector3 Vector3::operator/(float scalar)
{
	return { m_x / scalar, m_y / scalar, m_z / scalar };
}

Vector3 Vector3::operator+=(Vector3 other)
{
	return { m_x += other.m_x, m_y += other.m_y, m_z += other.m_z };
}

Vector3 Vector3::operator-=(Vector3 other)
{
	return { m_x -= other.m_x, m_y -= other.m_y, m_z -= other.m_z };
}

Vector3 Vector3::operator*=(float scalar)
{
	return { m_x *= scalar, m_y *= scalar, m_z *= scalar };
}

Vector3 Vector3::operator/=(float scalar)
{
	return Vector3();
}

float Vector3::magnitude()
{
	return sqrtf((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
}

void Vector3::normalise()
{
	float mag = magnitude();
	m_x /= mag;
	m_y /= mag;
	m_z /= mag;

}

Vector3 Vector3::cross(Vector3 other)
{
	//y*other.z - z*other.y
	//z*other.x - x*other.z
	//x*other.y - y*other.x
	return { m_y * other.m_z - m_z * other.m_y,
		m_z * other.m_x - m_x * other.m_z,
		m_x * other.m_y - m_y * other.m_x };
}

float Vector3::dot(const Vector3 other)
{
	return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}

Vector3::operator float*()
{
	return data;
}


Vector3::~Vector3()
{
}