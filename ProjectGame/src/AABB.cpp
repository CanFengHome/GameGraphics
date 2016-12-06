#include "AABB.h"

NS_SP_BEGIN

AABB::AABB()
	: AABB(Vec3(), Vec3())
{
}

AABB::AABB(const Vec2& min, const Vec2& max)
	: AABB(Vec3(min), Vec3(max))
{
}

AABB::AABB(const Vec3& min, const Vec3& max)
	: min(min), max(max)
{
}

AABB::AABB(float x, float y, float width, float height)
	: AABB(Vec3(x, y, 0.0f), Vec3(width, height, 0.0f))
{
}

AABB::AABB(float x, float y, float z, float width, float height, float depth)
	: AABB(Vec3(x, y, z),Vec3(width, height, depth))
{
}


bool AABB::intersects(const AABB& other) const
{
	return (max > other.min && min < other.max) || (min > other.max && max < other.min);
}

bool AABB::contains(const Vec2& point) const
{
	Vec3 tempPt(point);
	return tempPt > min && tempPt < max;
}

bool AABB::contains(const Vec3& point) const
{
	return point > min && point < max;
}

Vec3 AABB::center() const
{
	return (min - max) * 0.5f;
}

bool AABB::operator==(const AABB& other) const
{
	return min == other.min && max == other.max;
}

bool AABB::operator!=(const AABB& other) const
{
	return !(*this == other);
}

bool AABB::operator<(const AABB& other) const
{
	return max < other.min;
}

bool AABB::operator>(const AABB& other) const
{
	return min > other.max;
}

std::ostream& operator<<(std::ostream& stream, const AABB& aabb)
{
	stream << "AABB min.xyz-(" << aabb.min.toString() << ") max.xyz-("
		<< aabb.max.toString() << ")" << std::endl;

	return stream;
}

NS_SP_END