//
//  Vec4.cpp
//  SharpEngine
//
//  Created by ccf on 16/9/21.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Vec4.h"

NS_SP_BEGIN

Vec4::Vec4(float scalar)
: Vec4(scalar, scalar, scalar, scalar)
{
}

Vec4::Vec4(float fX, float fY, float fZ, float fW)
: x(fX), y(fY), z(fZ), w(fW)
{
}

Vec4::Vec4(const Vec3& xyz, float w)
: Vec4(xyz.x, xyz.y, xyz.z, w)
{
}

Vec4& Vec4::add(const Vec4& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    
    return *this;
}

Vec4& Vec4::sub(const Vec4& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    
    return *this;
}

Vec4& Vec4::multiply(const Vec4& other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    
    return *this;
}

Vec4& Vec4::divide(const Vec4& other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
    
    return *this;
}


Vec4 operator+(Vec4 left, const Vec4& right)
{
    return left.add(right);
}

Vec4 operator-(Vec4 left, const Vec4& right)
{
    return left.sub(right);
}

Vec4 operator*(Vec4 left, const Vec4& right)
{
    return left.multiply(right);
}

Vec4 operator/(Vec4 left, const Vec4& right)
{
    return left.divide(right);
}

Vec4& Vec4::operator+=(const Vec4& other)
{
    return add(other);
}

Vec4& Vec4::operator-=(const Vec4& other)
{
    return sub(other);
}

Vec4& Vec4::operator*=(const Vec4& other)
{
    return multiply(other);
}

Vec4& Vec4::operator/=(const Vec4& other)
{
    return divide(other);
}

bool Vec4::operator==(const Vec4& other)
{
    return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool Vec4::operator!=(const Vec4& other)
{
    return !(*this == other);
}

float Vec4::dot(const Vec4& other)
{
    return x * other.x + y * other.y + z * other.z + w * other.w;
}

std::ostream& operator<<(std::ostream& stream, const Vec4& vector)
{
    stream << "vec4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")" << std::endl;
    return stream;
}





















NS_SP_END






