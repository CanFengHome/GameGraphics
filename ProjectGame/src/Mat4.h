//
//  Mat4.h
//  SharpEngine
//
//  Created by ccf on 16/9/21.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef Mat4_h
#define Mat4_h

#include "PlatformMacros.h"
#include "Vec3.h"
#include "Vec4.h"

NS_SP_BEGIN

class Mat4
{
public:    
    Mat4();
    Mat4(float diagonal);
    Mat4(float* elements);
    Mat4(const Vec4& col0, const Vec4& col1, const Vec4& col2, const Vec4& col3);

    static Mat4 identity();
    
    Mat4& multiply(const Mat4& other);
    friend Mat4 operator*(Mat4 left, const Mat4& right);
    Mat4& operator*=(const Mat4& other);
    
	Vec3 multiply(const Vec3& other) const;
	friend Vec3 operator*(const Mat4& left, const Vec3& right);

	Vec4 multiply(const Vec4& other) const;
	friend Vec4 operator*(const Mat4& left, const Vec4& right);

	Mat4& Invert();

	static Mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
	static Mat4 perspective(float fov, float aspectRatio, float near, float far);

	static Mat4 translate(const Vec3& translation);
	static Mat4 rotate(float angle, const Vec3& axis);
	static Mat4 scale(const Vec3& scale);
	static Mat4 invert(const Mat4& matrix);

    friend std::ostream& operator<<(std::ostream& stream, const Mat4& mat);
public:
	union
	{
		float m_arrEle[16];
		Vec4 m_arrCol[4];
	};
};

NS_SP_END

#endif /* Mat4_h */



















