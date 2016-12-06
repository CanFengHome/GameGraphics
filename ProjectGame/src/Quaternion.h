//
//  Quaternion.h
//  SharpEngine
//
//  Created by ccf on 16/9/21.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef Quaternion_h
#define Quaternion_h

#include "PlatformMacros.h"
#include "Vec3.h"
#include "Vec4.h"

NS_SP_BEGIN

class Quaternion
{
public:
	Quaternion();
	Quaternion(const Quaternion& Quaternion);
	Quaternion(float x, float y, float z, float w);
	Quaternion(const Vec3& xyz, float w);
	Quaternion(const Vec4& vec);
	Quaternion(float scalar);

	Quaternion& operator=(const Quaternion& quat);

	Quaternion& setXYZ(const Vec3& vec);
	const Vec3 getXYZ() const;

	Quaternion& setElem(int idx, float value);
	float getElem(int idx) const;
	Vec3 getAxis() const;
	Vec3 toEulerAngles() const;

	const Quaternion operator+(const Quaternion& Quaternion) const;
	const Quaternion operator-(const Quaternion& Quaternion) const;
	const Quaternion operator*(const Quaternion& Quaternion) const;
	const Quaternion operator*(float scalar) const;
	const Quaternion operator/(float scalar) const;
	float operator[](int idx) const;

	Quaternion& operator+=(const Quaternion& Quaternion)
	{
		*this = *this + Quaternion;
		return *this;
	}

	Quaternion& operator-=(const Quaternion& Quaternion)
	{
		*this = *this - Quaternion;
		return *this;
	}

	Quaternion& operator*=(const Quaternion& Quaternion)
	{
		*this = *this * Quaternion;
		return *this;
	}

	Quaternion& operator*=(float scalar)
	{
		*this = *this * scalar;
		return *this;
	}

	Quaternion& operator/=(float scalar)
	{
		*this = *this / scalar;
		return *this;
	}

	const Quaternion operator-() const;
	bool operator==(const Quaternion & Quaternion) const;
	bool operator!=(const Quaternion & Quaternion) const;
	static const Quaternion identity();

	static Vec3 rotate(const Quaternion & quat, const Vec3 & vec);

	static const Quaternion rotation(const Vec3 & unitVec0, const Vec3 & unitVec1);
	static const Quaternion rotation(float radians, const Vec3 & unitVec);

	static const Quaternion rotationX(float radians)
	{
		float angle = radians * 0.5f;
		return Quaternion(sin(angle), 0.0f, 0.0f, cos(angle));
	}

	static const Quaternion rotationY(float radians)
	{
		float angle = radians * 0.5f;
		return Quaternion(0.0f, sin(angle), 0.0f, cos(angle));
	}

	static const Quaternion rotationZ(float radians)
	{
		float angle = radians * 0.5f;
		return Quaternion(0.0f, 0.0f, sin(angle), cos(angle));
	}

	float dot(const Quaternion& other) const;
	Quaternion conjugate() const;
public:
	float x, y, z, w;
};

NS_SP_END

#endif /* Quaternion_h */
