#ifndef AABB_h
#define AABB_h

#include "PlatformMacros.h"
#include "Vec2.h"
#include "Vec3.h"

NS_SP_BEGIN

class AABB
{
public:
	AABB();
	AABB(const Vec2& min, const Vec2& max);
	AABB(const Vec3& min, const Vec3& max);
	AABB(float x, float y, float width, float height);
	AABB(float x, float y, float z, float width, float height, float depth);

	bool intersects(const AABB& other) const;
	bool contains(const Vec2& point) const;
	bool contains(const Vec3& point) const;

	Vec3 center() const;

	bool operator==(const AABB& other) const;
	bool operator!=(const AABB& other) const;

	bool operator<(const AABB& other) const;
	bool operator>(const AABB& other) const;

	friend std::ostream& operator<<(std::ostream& stream, const AABB& aabb);

public:
	Vec3 min;
	Vec3 max;
};

NS_SP_END

#endif /* AABB_h */