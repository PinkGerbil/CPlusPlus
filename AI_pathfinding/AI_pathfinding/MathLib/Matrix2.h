#pragma once
#include "Vector2.h"
class Matrix2
{
public:
	union {
		struct {
			Vector2 xAxis;
			Vector2 yAxis;
		};
		Vector2 axis[2];
		float data[2][2];
	};
	static const Matrix2 identity();
	Matrix2(float a_x, float a_y, float b_x, float b_y);
	Matrix2(const Matrix2& other);
	Matrix2();
	Vector2& operator[] (int index);
	const Vector2& operator[] (int index) const;
	Matrix2& operator * (const Matrix2& other) const;
	Vector2 operator * (const Vector2& v) const;
	//Matrix2 operator = (Matrix2& other);

	Matrix2 transposed() const;

	void setScaled(float x, float y);
	void scale(const Vector2& v);

	void setRotate(float radians);
	void rotate(float radians);

	~Matrix2();
};