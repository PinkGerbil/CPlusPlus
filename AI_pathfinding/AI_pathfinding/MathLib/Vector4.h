#pragma once
class Vector4
{
public:
	union {
		struct {
			float m_x, m_y, m_z, m_w;
		};
		float data[4];
	};

	Vector4();
	Vector4(float x, float y, float z, float w);

	Vector4 operator + (Vector4 other);
	Vector4 operator - (Vector4 other);
	Vector4 operator * (float scalar);
	Vector4 operator /(float scalar);

	friend Vector4 operator * (float scalar, const Vector4 & other);

	float magnitude();
	void normalise();
	Vector4 cross(Vector4 other);
	float dot(const Vector4 other);
	explicit operator float * ();
	~Vector4();
};