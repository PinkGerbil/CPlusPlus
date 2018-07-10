#pragma once
#include "Vector3.h"
class Matrix3
{
public:
	union {
		struct {
			Vector3 xAxis;
			Vector3 yAxis;
			union {
				Vector3 zAxis;
				Vector3 translation;
			};
		};
		struct {

			Vector3 Right;
			Vector3 Forward;
			Vector3 Position;
		};
		Vector3 axis[3];
		float data[3][3];
	};
	Matrix3(float a_x, float a_y, float a_z, float b_x, float b_y, float b_z, float c_x, float c_y, float c_z);
	static const Matrix3 identity;

	Matrix3();
	Vector3& operator[] (int index);
	const Vector3& operator[] (int index) const;
	Matrix3 operator * (const Matrix3& other) const;
	Vector3 operator * (const Vector3& v) const;

	static Matrix3 createTranlation(float c_x, float c_y, float c_z);
	static Matrix3 createRotation(float a_rot);
	static Matrix3 createScale(float xscale, float yscale);


	Matrix3 transposed();

	void setScaled(float x, float y, float z);
	void scale(const Vector3& v);

	void setRotateX(float radians);
	void rotateX(float radians);
	void setRotateY(float radians);
	void rotateY(float radians);
	void setRotateZ(float radians);
	void rotateZ(float radians);
	void translate(float x, float y, float z);
	void setEuler(float pitch, float yaw, float roll);

	~Matrix3();
};