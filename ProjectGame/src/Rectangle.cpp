#include "Rectangle.h"


NS_SP_BEGIN

Rectangle::Rectangle()
	: Rectangle(0.0f, 0.0f, 0.0f, 0.0f)
{
}

Rectangle::Rectangle(const Vec2& position, const Vec2& size)
	: position(position), size(size)
{
}

Rectangle::Rectangle(float x, float y, float width, float height)
	: Rectangle(Vec2(x, y), Vec2(width, height))
{
}

bool Rectangle::intersects(const Rectangle& other) const
{
	return (position + size > other.position && position < other.position + other.size) || 
		(position > other.position + other.size && position + size < other.position);
}

bool Rectangle::contains(const Vec2& point) const
{
	return point > position && point < position + size;
}

bool Rectangle::contains(const Vec3& point) const
{
	return contains(Vec2(point));
}

Vec2 Rectangle::center() const
{
	return position + size * 0.5f;
}

bool Rectangle::operator==(const Rectangle& other) const
{
	return position == other.position && size == other.size;
}

bool Rectangle::operator!=(const Rectangle& other) const
{
	return !(*this == other);
}

bool Rectangle::operator<(const Rectangle& other) const
{
	return size < other.size;
}

bool Rectangle::operator>(const Rectangle& other) const
{
	return size > other.size;
}














NS_SP_END
