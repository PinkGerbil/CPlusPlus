#pragma once
class Vector2
{
public:

	union {
		struct {
			float m_x;
			float m_y;
		};
		float data[2];
	};

	Vector2();
	Vector2(float x, float y);

	Vector2 operator + (Vector2 other);
	Vector2 operator - (Vector2 other);
	Vector2 operator * (float scalar);
	Vector2 operator / (float scalar);
	Vector2 operator += (Vector2 other);
	Vector2 operator -= (Vector2 other);
	Vector2 operator *= (float scalar);
	Vector2 operator /= (float scalar);

	float magnitude();
	void normalise();
	Vector2 cross(Vector2 other);
	float dot(const Vector2 other);
	Vector2 getPerpendicularRH() const;

	float angleBetween(Vector2& other);

	friend Vector2 operator *(float scalar, const Vector2 a_vec);
	explicit operator float * ();
	Vector2 normalized()const;



	~Vector2();
};