//
//  Vec3.h
//  SharpEngine
//
//  Created by ccf on 16/9/20.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef Vec3_h
#define Vec3_h

#include "PlatformMacros.h"

NS_SP_BEGIN

class Vec2;
class Vec3
{
public:
    Vec3();
    Vec3(float scale);
    Vec3(float fX, float fY);
    Vec3(float fX, float fY, float fZ);
    Vec3(const Vec2& rhs);
    //拷贝
    Vec3(const Vec3& rhs);
    //赋值
    Vec3& operator=(const Vec3& rhs);
    
    static Vec3 up();
    static Vec3 down();
    static Vec3 left();
    static Vec3 right();
    static Vec3 zero();
    
    static Vec3 xAxis();
    static Vec3 yAxis();
    static Vec3 zAxis();
    
    Vec3& add(const Vec3& rhs);
    Vec3& sub(const Vec3& rhs);
    Vec3& multiply(const Vec3& rhs);
    Vec3& divide(const Vec3& rhs);
    
    Vec3& add(float rhs);
    Vec3& sub(float rhs);
    Vec3& multiply(float rhs);
    Vec3& divide(float rhs);
    
    friend Vec3 operator+(Vec3 lhs, const Vec3& rhs);
    friend Vec3 operator-(Vec3 lhs, const Vec3& rhs);
    friend Vec3 operator*(Vec3 lhs, const Vec3& rhs);
    friend Vec3 operator/(Vec3 lhs, const Vec3& rhs);
    
    friend Vec3 operator+(Vec3 lhs, float rhs);
    friend Vec3 operator-(Vec3 lhs, float rhs);
    friend Vec3 operator*(Vec3 lhs, float rhs);
    friend Vec3 operator/(Vec3 lhs, float rhs);
    
    bool operator==(const Vec3& rhs) const;
    bool operator!=(const Vec3& rhs) const;
    
	bool operator<(const Vec3& other) const;
	bool operator<=(const Vec3& other) const;
	bool operator>(const Vec3& other) const;
	bool operator>=(const Vec3& other) const;

    friend Vec3 operator-(const Vec3& rhs);
    
    Vec3 cross(const Vec3& rhs) const;
    float dot(const Vec3& rhs) const;
    float magnitude() const;
    Vec3 normalize() const;
    float distance(const Vec3& rhs) const;
    
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& stream, const Vec3& rhs);
public:
    float x;
    float y;
    float z;
};

NS_SP_END

#endif /* Vec3_h */


























