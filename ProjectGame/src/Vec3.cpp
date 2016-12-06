//
//  Vec3.cpp
//  SharpEngine
//
//  Created by ccf on 16/9/20.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Vec3.h"

#include "Vec2.h"

NS_SP_BEGIN

Vec3::Vec3()
:Vec3(0.0f, 0.0f, 0.0f)
{
    
}

Vec3::Vec3(float scale)
:Vec3(scale, scale, scale)
{
    
}

Vec3::Vec3(float fX, float fY)
:Vec3(fX, fY, 0.0f)
{
    
}

Vec3::Vec3(float fX, float fY, float fZ)
:x(fX), y(fY), z(fZ)
{
    
}

Vec3::Vec3(const Vec2& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = 0.0f;
}

Vec3::Vec3(const Vec3& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
}

Vec3& Vec3::operator=(const Vec3& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    
    return *this;
}


Vec3 Vec3::up()
{
    return Vec3(0.0f, 1.0f, 0.0f);
}

Vec3 Vec3::down()
{
    return Vec3(0.0f, -1.0f, 0.0f);
}

Vec3 Vec3::left()
{
    return Vec3(-1.0f, 0.0f, 0.0f);
}

Vec3 Vec3::right()
{
    return Vec3(1.0f, 0.0f, 0.0f);
}

Vec3 Vec3::zero()
{
    return Vec3(0.0f, 0.0f, 0.0f);
}

Vec3 Vec3::xAxis()
{
    return Vec3(1.0f, 0.0f, 0.0f);
}

Vec3 Vec3::yAxis()
{
    return Vec3(0.0f, 1.0f, 0.0f);
}

Vec3 Vec3::zAxis()
{
    return Vec3(0.0f, 0.0f, 1.0f);
}


Vec3& Vec3::add(const Vec3& rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    
    return *this;
}

Vec3& Vec3::sub(const Vec3& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    
    return *this;
}

Vec3& Vec3::multiply(const Vec3& rhs)
{
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    
    return *this;
}

Vec3& Vec3::divide(const Vec3& rhs)
{
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    
    return *this;
}

Vec3& Vec3::add(float rhs)
{
    x += rhs;
    y += rhs;
    z += rhs;
    
    return *this;
}

Vec3& Vec3::sub(float rhs)
{
    x -= rhs;
    y -= rhs;
    z -= rhs;
    
    return *this;
}

Vec3& Vec3::multiply(float rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;
    
    return *this;
}

Vec3& Vec3::divide(float rhs)
{
    x /= rhs;
    y /= rhs;
    z /= rhs;
    
    return *this;
}


Vec3 operator+(Vec3 lhs, const Vec3& rhs)
{
    return lhs.add(rhs);
}

Vec3 operator-(Vec3 lhs, const Vec3& rhs)
{
    return lhs.sub(rhs);
}

Vec3 operator*(Vec3 lhs, const Vec3& rhs)
{
    return lhs.multiply(rhs);
}

Vec3 operator/(Vec3 lhs, const Vec3& rhs)
{
    return lhs.divide(rhs);
}

Vec3 operator+(Vec3 lhs, float rhs)
{
    return lhs.add(rhs);
}

Vec3 operator-(Vec3 lhs, float rhs)
{
    return lhs.sub(rhs);
}

Vec3 operator*(Vec3 lhs, float rhs)
{
    return lhs.multiply(rhs);
}

Vec3 operator/(Vec3 lhs, float rhs)
{
    return lhs.divide(rhs);
}


bool Vec3::operator==(const Vec3& rhs) const
{
    return x == rhs.x && y == rhs.y;
}

bool Vec3::operator!=(const Vec3& rhs) const
{
    return !(*this == rhs);
}

bool Vec3::operator<(const Vec3& other) const
{
	return x < other.x && y < other.y && z < other.z;
}

bool Vec3::operator<=(const Vec3& other) const
{
	return x <= other.x && y <= other.y && z <= other.z;
}

bool Vec3::operator>(const Vec3& other) const
{
	return x > other.x && y > other.y && z > other.z;
}

bool Vec3::operator>=(const Vec3& other) const
{
	return x >= other.x && y >= other.y && z >= other.z;
}


Vec3 operator-(const Vec3& rhs)
{
    return Vec3(-rhs.x, -rhs.y, -rhs.z);
}

Vec3 Vec3::cross(const Vec3& rhs) const
{
    return Vec3(y*rhs.z - z*rhs.y,
                z*rhs.x - x*rhs.z,
                x*rhs.y - y*rhs.x);
}

float Vec3::dot(const Vec3& rhs) const
{
    return x*rhs.x + y*rhs.y + z*rhs.z;
}

float Vec3::magnitude() const
{
    return sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::normalize() const
{
    float length = magnitude();
    return Vec3(x / length, y / length, z / length);
}

float Vec3::distance(const Vec3& rhs) const
{
    float a = x - rhs.x;
    float b = y - rhs.y;
    float c = z - rhs.z;
    return sqrt(a * a + b * b + c * c);
}

std::string Vec3::toString() const
{
    std::stringstream result;
    result << "Vec3: (" << x << "," << y << z << ")";
    return result.str();
}

std::ostream& operator<<(std::ostream& stream, const Vec3& rhs)
{
    stream << rhs.toString() << std::endl;
    return stream;
}


NS_SP_END

























