//
//  Vec2.cpp
//  SharpEngine
//
//  Created by ccf on 16/9/20.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Vec2.h"
#include "Vec3.h"
NS_SP_BEGIN

Vec2::Vec2()
:Vec2(0.0f, 0.0f)
{
    
}

Vec2::Vec2(float scalar)
:Vec2(scalar, scalar)
{
    
}

Vec2::Vec2(float fX, float fY)
:x(fX), y(fY)
{
    
}

Vec2::Vec2(const Vec2& rhs)
{
    x = rhs.x;
    y = rhs.y;
}

Vec2::Vec2(const Vec3& vector)
	:Vec2(vector.x, vector.y)
{

}


Vec2& Vec2::add(const Vec2& rhs)
{
    x += rhs.x;
    y += rhs.y;
    
    return *this;
}

Vec2& Vec2::sub(const Vec2& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    
    return *this;
}

Vec2& Vec2::multiply(const Vec2& rhs)
{
    x *= rhs.x;
    y *= rhs.y;
    
    return *this;
}

Vec2& Vec2::divide(const Vec2& rhs)
{
    x /= rhs.x;
    y /= rhs.y;
    
    return *this;
}



Vec2& Vec2::add(float val)
{
    x += val;
    y += val;
    
    return *this;
}

Vec2& Vec2::sub(float val)
{
    x -= val;
    y -= val;
    
    return *this;
}

Vec2& Vec2::multiply(float val)
{
    x *= val;
    y *= val;
    
    return *this;
}

Vec2& Vec2::divide(float val)
{
    x /= val;
    y /= val;
    
    return *this;
}


Vec2 operator+(Vec2 lhs, const Vec2& rhs)
{
    return lhs.add(rhs);
}

Vec2 operator-(Vec2 lhs, const Vec2& rhs)
{
    return lhs.sub(rhs);
}

Vec2 operator*(Vec2 lhs, const Vec2& rhs)
{
    return lhs.multiply(rhs);
}

Vec2 operator/(Vec2 lhs, const Vec2& rhs)
{
    return lhs.divide(rhs);
}


Vec2 operator+(Vec2 lhs, float val)
{
    return lhs.add(val);
}

Vec2 operator-(Vec2 lhs, float val)
{
    return lhs.sub(val);
}

Vec2 operator*(Vec2 lhs, float val)
{
    return lhs.multiply(val);
}

Vec2 operator/(Vec2 lhs, float val)
{
    return lhs.divide(val);
}


bool Vec2::operator==(const Vec2& rhs) const
{
    return x == rhs.x && y == rhs.y;
}

bool Vec2::operator!=(const Vec2& rhs) const
{
    return !(*this == rhs);
}


Vec2& Vec2::operator+(const Vec2& rhs)
{
    return add(rhs);
}

Vec2& Vec2::operator-(const Vec2& rhs)
{
    return sub(rhs);
}

Vec2& Vec2::operator*(const Vec2& rhs)
{
    return multiply(rhs);
}

Vec2& Vec2::operator/(const Vec2& rhs)
{
    return divide(rhs);
}

Vec2& Vec2::operator+(float val)
{
    return add(val);
}

Vec2& Vec2::operator-(float val)
{
    return sub(val);
}

Vec2& Vec2::operator*(float val)
{
    return multiply(val);
}

Vec2& Vec2::operator/(float val)
{
    return divide(val);
}


bool Vec2::operator<(const Vec2& other) const
{
	return x < other.x && y < other.y;
}

bool Vec2::operator<=(const Vec2& other) const
{
	return x <= other.x && y <= other.y;
}

bool Vec2::operator>(const Vec2& other) const
{
	return x > other.x && y > other.y;
}

bool Vec2::operator>=(const Vec2& other) const
{
	return x >= other.x && y >= other.y;
}

float Vec2::magnitude() const
{
    return sqrt(x*x + y*y);
}

Vec2 Vec2::normalize() const
{
    float len = magnitude();
    return Vec2(x / len, y / len);
}

float Vec2::distance(const Vec2& rhs) const
{
    float a = x-rhs.x;
    float b = y-rhs.y;
    return sqrtf(a*a+b*b);
}

float Vec2::dot(const Vec2& rhs) const
{
    return x*rhs.x + y*rhs.y;
}

std::string Vec2::toString() const
{
    std::stringstream result;
    result << "Vec2: (" << x << "," << y << ")";
    return result.str();
}

std::ostream& operator<<(std::ostream& stream, const Vec2& rhs)
{
    stream << rhs.toString() << std::endl;
    return stream;
}

NS_SP_END





























