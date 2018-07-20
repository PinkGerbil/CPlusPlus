#pragma once
#include "Vector2.h"
#include <vector>	

float min(float a, float b) { return a < b ? a : b; };
float max(float a, float b) { return a > b ? a : b; };
Vector2 Vmin(const Vector2& a, const Vector2& b) { return { min(a.m_x, b.m_x), min(a.m_y, b.m_y) }; };
Vector2 Vmax(const Vector2& a, const Vector2& b) { return { max(a.m_x, b.m_x), max(a.m_y, b.m_y) }; };


float clamp(float t, float a, float b) { return max(a, min(b, t)); };
Vector2 Vclamp(const Vector2& t, const Vector2& a, const Vector2& b) { return Vmax(a, Vmin(b, t)); };

class AABB
{
public:
	AABB();
	AABB(const Vector2& min, const Vector2 & max) : Min(min), Max(max) {};
	~AABB();
	Vector2 Min, Max;

	Vector2 center();
	Vector2 extents();
	std::vector<Vector2> corners() const;

	void fit(const Vector2* points, unsigned int count); 

	bool overlaps(const AABB& other)const;

	Vector2 closestPoint(const Vector2& p) const; 
};

