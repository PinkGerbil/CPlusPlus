#include "AABB.h"

AABB::AABB()
{
}

AABB::~AABB()
{
}

Vector2 AABB::center()
{
	return ((Min + Max) * 0.5f);
}

Vector2 AABB::extents()
{
	return { abs(Max.m_x - Min.m_x) * 0.5f, abs(Max.m_y - Min.m_y) * 0.5f };
}

std::vector<Vector2> AABB::corners() const
{
	std::vector<Vector2> corners(4);
	corners[0] = Min;
	corners[1] = { Min.m_x, Max.m_y };
	corners[2] = Max;
	corners[3] = { Max.m_x, Min.m_y };
	return corners;
}

void AABB::fit(const Vector2 * points, unsigned int count)
{
	Min = { FLT_MAX, FLT_MAX };
	Max = { FLT_MIN, FLT_MIN };

	for (unsigned int i = 0; i < count; ++i, ++points) {
		Min = Vmin(Min, *points);
		Max = Vmax(Max, *points);
	}
}

bool AABB::overlaps(const AABB & other) const
{
	return !(Max.m_x < other.Min.m_x || Max.m_y < other.Min.m_y || Min.m_x > other.Max.m_x || Min.m_y > other.Max.m_y);
}

Vector2 AABB::closestPoint( Vector2 & p) 
{
	return Vclamp(p, Min, Max); 
}
