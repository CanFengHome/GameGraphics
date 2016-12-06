//
//  Mat4.cpp
//  SharpEngine
//
//  Created by ccf on 16/9/21.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Mat4.h"
#include "math_func.h"

NS_SP_BEGIN

Mat4::Mat4()
{
    memset(m_arrEle, 0, 16 * sizeof(float));
}

Mat4::Mat4(float diagonal)
:Mat4()
{
    m_arrEle[0 + 0*4] = diagonal;
    m_arrEle[1 + 1*4] = diagonal;
    m_arrEle[2 + 2*4] = diagonal;
    m_arrEle[3 + 3*4] = diagonal;
}

Mat4::Mat4(float* m_arrEle)
{
    memcpy(m_arrEle, m_arrEle, 16 * sizeof(float));
}

Mat4::Mat4(const Vec4& col0, const Vec4& col1, const Vec4& col2, const Vec4& col3)
{
	m_arrCol[0] = col0;
	m_arrCol[1] = col1;
	m_arrCol[2] = col2;
	m_arrCol[3] = col3;
}

Mat4 Mat4::identity()
{
    return Mat4(1.0f);
}

/*// test
Mat4 leftMat(Vec4(1, 0, 1, 0),
             Vec4(0, 1, 0, 1),
             Vec4(1, 0, 0, 1),
             Vec4(0, 1, 1, 0));
cout << leftMat << endl;

Mat4 rightMat(Vec4(1, 0, 1, 0),
              Vec4(1, 1, 1, 0),
              Vec4(0, 0, 1, 0),
              Vec4(0, 0, 0, 1));
cout << rightMat << endl;

leftMat.multiply(rightMat);
cout << leftMat << endl;
// --test*/
Mat4& Mat4::multiply(const Mat4& other)
{
    float data[16];
    
    for (int row = 0; row < 4; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            float sum = 0.0f;
            for (int i = 0; i < 4; ++i)
            {
                sum += (m_arrEle[row + i*4] * other.m_arrEle[i + col*4]);
            }
            data[row + col * 4] = sum;
        }
    }
    
    memcpy(m_arrEle, data, 16*sizeof(float));
    
    return *this;
}

Mat4 operator*(Mat4 left, const Mat4& right)
{
    left.multiply(right);
    return left;
}

Mat4& Mat4::operator*=(const Mat4& other)
{
    return multiply(other);
}


Vec3 Mat4::multiply(const Vec3& other) const
{
	return Vec3(
		m_arrCol[0].x * other.x + m_arrCol[1].x * other.y + m_arrCol[2].x * other.z + m_arrCol[3].x,
		m_arrCol[0].y * other.x + m_arrCol[1].y * other.y + m_arrCol[2].y * other.z + m_arrCol[3].y,
		m_arrCol[0].z * other.x + m_arrCol[1].z * other.y + m_arrCol[2].z * other.z + m_arrCol[3].z
		);
}

Vec3 operator*(const Mat4& left, const Vec3& right)
{
	return left.multiply(right);
}

Vec4 Mat4::multiply(const Vec4& other) const
{
	return Vec4(
		m_arrCol[0].x * other.x + m_arrCol[1].x * other.y + m_arrCol[2].x * other.z + m_arrCol[3].x * other.w,
		m_arrCol[0].y * other.x + m_arrCol[1].y * other.y + m_arrCol[2].y * other.z + m_arrCol[3].y * other.w,
		m_arrCol[0].z * other.x + m_arrCol[1].z * other.y + m_arrCol[2].z * other.z + m_arrCol[3].z * other.w,
		m_arrCol[0].w * other.x + m_arrCol[1].w * other.y + m_arrCol[2].w * other.z + m_arrCol[3].w * other.w
		);
}

Mat4& Mat4::Invert()
{
	double temp[16];

	temp[0] = m_arrEle[5] * m_arrEle[10] * m_arrEle[15] -
		m_arrEle[5] * m_arrEle[11] * m_arrEle[14] -
		m_arrEle[9] * m_arrEle[6] * m_arrEle[15] +
		m_arrEle[9] * m_arrEle[7] * m_arrEle[14] +
		m_arrEle[13] * m_arrEle[6] * m_arrEle[11] -
		m_arrEle[13] * m_arrEle[7] * m_arrEle[10];

	temp[4] = -m_arrEle[4] * m_arrEle[10] * m_arrEle[15] +
		m_arrEle[4] * m_arrEle[11] * m_arrEle[14] +
		m_arrEle[8] * m_arrEle[6] * m_arrEle[15] -
		m_arrEle[8] * m_arrEle[7] * m_arrEle[14] -
		m_arrEle[12] * m_arrEle[6] * m_arrEle[11] +
		m_arrEle[12] * m_arrEle[7] * m_arrEle[10];

	temp[8] = m_arrEle[4] * m_arrEle[9] * m_arrEle[15] -
		m_arrEle[4] * m_arrEle[11] * m_arrEle[13] -
		m_arrEle[8] * m_arrEle[5] * m_arrEle[15] +
		m_arrEle[8] * m_arrEle[7] * m_arrEle[13] +
		m_arrEle[12] * m_arrEle[5] * m_arrEle[11] -
		m_arrEle[12] * m_arrEle[7] * m_arrEle[9];

	temp[12] = -m_arrEle[4] * m_arrEle[9] * m_arrEle[14] +
		m_arrEle[4] * m_arrEle[10] * m_arrEle[13] +
		m_arrEle[8] * m_arrEle[5] * m_arrEle[14] -
		m_arrEle[8] * m_arrEle[6] * m_arrEle[13] -
		m_arrEle[12] * m_arrEle[5] * m_arrEle[10] +
		m_arrEle[12] * m_arrEle[6] * m_arrEle[9];

	temp[1] = -m_arrEle[1] * m_arrEle[10] * m_arrEle[15] +
		m_arrEle[1] * m_arrEle[11] * m_arrEle[14] +
		m_arrEle[9] * m_arrEle[2] * m_arrEle[15] -
		m_arrEle[9] * m_arrEle[3] * m_arrEle[14] -
		m_arrEle[13] * m_arrEle[2] * m_arrEle[11] +
		m_arrEle[13] * m_arrEle[3] * m_arrEle[10];

	temp[5] = m_arrEle[0] * m_arrEle[10] * m_arrEle[15] -
		m_arrEle[0] * m_arrEle[11] * m_arrEle[14] -
		m_arrEle[8] * m_arrEle[2] * m_arrEle[15] +
		m_arrEle[8] * m_arrEle[3] * m_arrEle[14] +
		m_arrEle[12] * m_arrEle[2] * m_arrEle[11] -
		m_arrEle[12] * m_arrEle[3] * m_arrEle[10];

	temp[9] = -m_arrEle[0] * m_arrEle[9] * m_arrEle[15] +
		m_arrEle[0] * m_arrEle[11] * m_arrEle[13] +
		m_arrEle[8] * m_arrEle[1] * m_arrEle[15] -
		m_arrEle[8] * m_arrEle[3] * m_arrEle[13] -
		m_arrEle[12] * m_arrEle[1] * m_arrEle[11] +
		m_arrEle[12] * m_arrEle[3] * m_arrEle[9];

	temp[13] = m_arrEle[0] * m_arrEle[9] * m_arrEle[14] -
		m_arrEle[0] * m_arrEle[10] * m_arrEle[13] -
		m_arrEle[8] * m_arrEle[1] * m_arrEle[14] +
		m_arrEle[8] * m_arrEle[2] * m_arrEle[13] +
		m_arrEle[12] * m_arrEle[1] * m_arrEle[10] -
		m_arrEle[12] * m_arrEle[2] * m_arrEle[9];

	temp[2] = m_arrEle[1] * m_arrEle[6] * m_arrEle[15] -
		m_arrEle[1] * m_arrEle[7] * m_arrEle[14] -
		m_arrEle[5] * m_arrEle[2] * m_arrEle[15] +
		m_arrEle[5] * m_arrEle[3] * m_arrEle[14] +
		m_arrEle[13] * m_arrEle[2] * m_arrEle[7] -
		m_arrEle[13] * m_arrEle[3] * m_arrEle[6];

	temp[6] = -m_arrEle[0] * m_arrEle[6] * m_arrEle[15] +
		m_arrEle[0] * m_arrEle[7] * m_arrEle[14] +
		m_arrEle[4] * m_arrEle[2] * m_arrEle[15] -
		m_arrEle[4] * m_arrEle[3] * m_arrEle[14] -
		m_arrEle[12] * m_arrEle[2] * m_arrEle[7] +
		m_arrEle[12] * m_arrEle[3] * m_arrEle[6];

	temp[10] = m_arrEle[0] * m_arrEle[5] * m_arrEle[15] -
		m_arrEle[0] * m_arrEle[7] * m_arrEle[13] -
		m_arrEle[4] * m_arrEle[1] * m_arrEle[15] +
		m_arrEle[4] * m_arrEle[3] * m_arrEle[13] +
		m_arrEle[12] * m_arrEle[1] * m_arrEle[7] -
		m_arrEle[12] * m_arrEle[3] * m_arrEle[5];

	temp[14] = -m_arrEle[0] * m_arrEle[5] * m_arrEle[14] +
		m_arrEle[0] * m_arrEle[6] * m_arrEle[13] +
		m_arrEle[4] * m_arrEle[1] * m_arrEle[14] -
		m_arrEle[4] * m_arrEle[2] * m_arrEle[13] -
		m_arrEle[12] * m_arrEle[1] * m_arrEle[6] +
		m_arrEle[12] * m_arrEle[2] * m_arrEle[5];

	temp[3] = -m_arrEle[1] * m_arrEle[6] * m_arrEle[11] +
		m_arrEle[1] * m_arrEle[7] * m_arrEle[10] +
		m_arrEle[5] * m_arrEle[2] * m_arrEle[11] -
		m_arrEle[5] * m_arrEle[3] * m_arrEle[10] -
		m_arrEle[9] * m_arrEle[2] * m_arrEle[7] +
		m_arrEle[9] * m_arrEle[3] * m_arrEle[6];

	temp[7] = m_arrEle[0] * m_arrEle[6] * m_arrEle[11] -
		m_arrEle[0] * m_arrEle[7] * m_arrEle[10] -
		m_arrEle[4] * m_arrEle[2] * m_arrEle[11] +
		m_arrEle[4] * m_arrEle[3] * m_arrEle[10] +
		m_arrEle[8] * m_arrEle[2] * m_arrEle[7] -
		m_arrEle[8] * m_arrEle[3] * m_arrEle[6];

	temp[11] = -m_arrEle[0] * m_arrEle[5] * m_arrEle[11] +
		m_arrEle[0] * m_arrEle[7] * m_arrEle[9] +
		m_arrEle[4] * m_arrEle[1] * m_arrEle[11] -
		m_arrEle[4] * m_arrEle[3] * m_arrEle[9] -
		m_arrEle[8] * m_arrEle[1] * m_arrEle[7] +
		m_arrEle[8] * m_arrEle[3] * m_arrEle[5];

	temp[15] = m_arrEle[0] * m_arrEle[5] * m_arrEle[10] -
		m_arrEle[0] * m_arrEle[6] * m_arrEle[9] -
		m_arrEle[4] * m_arrEle[1] * m_arrEle[10] +
		m_arrEle[4] * m_arrEle[2] * m_arrEle[9] +
		m_arrEle[8] * m_arrEle[1] * m_arrEle[6] -
		m_arrEle[8] * m_arrEle[2] * m_arrEle[5];

	double determinant = m_arrEle[0] * temp[0] + m_arrEle[1] * temp[4] + m_arrEle[2] * temp[8] + m_arrEle[3] * temp[12];
	determinant = 1.0 / determinant;

	for (int i = 0; i < 4 * 4; i++)
		m_arrEle[i] = temp[i] * determinant;

	return *this;
}

Mat4 Mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
{
	Mat4 result(1.0f);

	result.m_arrEle[0 + 0 * 4] = 2.0f / (right - left);

	result.m_arrEle[1 + 1 * 4] = 2.0f / (top - bottom);

	result.m_arrEle[2 + 2 * 4] = 2.0f / (near - far);

	result.m_arrEle[0 + 3 * 4] = (left + right) / (left - right);
	result.m_arrEle[1 + 3 * 4] = (bottom + top) / (bottom - top);
	result.m_arrEle[2 + 3 * 4] = -(far + near) / (far - near);

	return result;
}

Mat4 Mat4::perspective(float fov, float aspectRatio, float near, float far)
{
	Mat4 result(1.0f);

	float q = 1.0f / tan(toRadians(0.5f * fov));
	float a = q / aspectRatio;

	float b = (near + far) / (near - far);
	float c = (2.0f * near * far) / (near - far);

	result.m_arrEle[0 + 0 * 4] = a;
	result.m_arrEle[1 + 1 * 4] = q;
	result.m_arrEle[2 + 2 * 4] = b;
	result.m_arrEle[3 + 2 * 4] = -1.0f;
	result.m_arrEle[2 + 3 * 4] = c;

	return result;
}

Mat4 Mat4::translate(const Vec3& translation)
{
	Mat4 result(1.0f);

	result.m_arrEle[0 + 3 * 4] = translation.x;
	result.m_arrEle[1 + 3 * 4] = translation.y;
	result.m_arrEle[2 + 3 * 4] = translation.z;

	return result;
}

Mat4 Mat4::rotate(float angle, const Vec3& axis)
{
	Mat4 result(1.0f);

	float r = toRadians(angle);
	float c = cos(r);
	float s = sin(r);
	float omc = 1.0f - c;

	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	result.m_arrEle[0 + 0 * 4] = x * omc + c;
	result.m_arrEle[1 + 0 * 4] = y * x * omc + z * s;
	result.m_arrEle[2 + 0 * 4] = x * z * omc - y * s;

	result.m_arrEle[0 + 1 * 4] = x * y * omc - z * s;
	result.m_arrEle[1 + 1 * 4] = y * omc + c;
	result.m_arrEle[2 + 1 * 4] = y * z * omc + x * s;

	result.m_arrEle[0 + 2 * 4] = x * z * omc + y * s;
	result.m_arrEle[1 + 2 * 4] = y * z * omc - x * s;
	result.m_arrEle[2 + 2 * 4] = z * omc + c;

	return result;
}

Mat4 Mat4::scale(const Vec3& scale)
{
	Mat4 result(1.0f);

	result.m_arrEle[0 + 0 * 4] = scale.x;
	result.m_arrEle[1 + 1 * 4] = scale.y;
	result.m_arrEle[2 + 2 * 4] = scale.z;

	return result;
}

Mat4 Mat4::invert(const Mat4& matrix)
{
	Mat4 result = matrix;
	return result.Invert();
}


std::ostream& operator<<(std::ostream& stream, const Mat4& mat)
{
    stream << "----------------------------" << std::endl;
    for (int row = 0; row < 4; ++row)
    {
        stream << "| ";
        for (int col = 0; col < 4; ++col)
        {
            stream << mat.m_arrEle[row + col * 4] << " ";
        }
        stream << "|" << std::endl;
    }
    stream << "----------------------------" << std::endl;
    
    return stream;
}


NS_SP_END

























