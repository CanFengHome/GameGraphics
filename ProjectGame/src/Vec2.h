//
//  Vec2.h
//  SharpEngine
//
//  Created by ccf on 16/9/20.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef Vec2_h
#define Vec2_h

#include "PlatformMacros.h"


NS_SP_BEGIN

class Vec3;
class Vec2
{
public:
    Vec2();
    Vec2(float scalar);
    Vec2(float fX, float fY);
    Vec2(const Vec2& rhs);
	Vec2(const Vec3& vector);
    
    Vec2& add(const Vec2& rhs);
    Vec2& sub(const Vec2& rhs);
    Vec2& multiply(const Vec2& rhs);
    Vec2& divide(const Vec2& rhs);
    
    Vec2& add(float val);
    Vec2& sub(float val);
    Vec2& multiply(float val);
    Vec2& divide(float val);

    friend Vec2 operator+(Vec2 lhs, const Vec2& rhs);
    friend Vec2 operator-(Vec2 lhs, const Vec2& rhs);
    friend Vec2 operator*(Vec2 lhs, const Vec2& rhs);
    friend Vec2 operator/(Vec2 lhs, const Vec2& rhs);
    
    friend Vec2 operator+(Vec2 lhs, float val);
    friend Vec2 operator-(Vec2 lhs, float val);
    friend Vec2 operator*(Vec2 lhs, float val);
    friend Vec2 operator/(Vec2 lhs, float val);
    
    bool operator==(const Vec2& rhs) const;
    bool operator!=(const Vec2& rhs) const;
    
    Vec2& operator+(const Vec2& rhs);
    Vec2& operator-(const Vec2& rhs);
    Vec2& operator*(const Vec2& rhs);
    Vec2& operator/(const Vec2& rhs);
    
    Vec2& operator+(float val);
    Vec2& operator-(float val);
    Vec2& operator*(float val);
    Vec2& operator/(float val);

	bool operator<(const Vec2& other) const;
	bool operator<=(const Vec2& other) const;
	bool operator>(const Vec2& other) const;
	bool operator>=(const Vec2& other) const;

    // 向量的大小
    float magnitude() const;
    Vec2 normalize() const;
    float distance(const Vec2& rhs) const;
    float dot(const Vec2& rhs) const;
    
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& stream, const Vec2& rhs);
    
public:
    float x;
    float y;
};

NS_SP_END



#endif /* Vec2_h */




















