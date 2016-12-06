//
//  Vec4.h
//  SharpEngine
//
//  Created by ccf on 16/9/21.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef Vec4_h
#define Vec4_h

#include "PlatformMacros.h"
#include "Vec3.h"

NS_SP_BEGIN

class Vec4
{
public:
    Vec4() = default;
    Vec4(float scalar);
    Vec4(float fX, float fY, float fZ, float fW);
    Vec4(const Vec3& xyz, float w);
    
    Vec4& add(const Vec4& other);
    Vec4& sub(const Vec4& other);
    Vec4& multiply(const Vec4& other);
    Vec4& divide(const Vec4& other);
    
    friend Vec4 operator+(Vec4 left, const Vec4& right);
    friend Vec4 operator-(Vec4 left, const Vec4& right);
    friend Vec4 operator*(Vec4 left, const Vec4& right);
    friend Vec4 operator/(Vec4 left, const Vec4& right);
    
    bool operator==(const Vec4& other);
    bool operator!=(const Vec4& other);
    
    Vec4& operator+=(const Vec4& other);
    Vec4& operator-=(const Vec4& other);
    Vec4& operator*=(const Vec4& other);
    Vec4& operator/=(const Vec4& other);
    
    float dot(const Vec4& other);
    
    friend std::ostream& operator<<(std::ostream& stream, const Vec4& vector);
public:
    float x;
    float y;
    float z;
    float w;
};



NS_SP_END



#endif /* Vec4_h */
