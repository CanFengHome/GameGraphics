#include "Quaternion.h"

NS_SP_BEGIN

Quaternion::Quaternion()
	: Quaternion(0.0f, 0.0f, 0.0f, 1.0f)
{
}

Quaternion::Quaternion(const Quaternion& Quaternion)
{
	x = Quaternion.x;
	y = Quaternion.y;
	z = Quaternion.z;
	w = Quaternion.w;
}

Quaternion::Quaternion(float x, float y, float z, float w)
	: x(x), y(y), z(z), w(w)
{
}

Quaternion::Quaternion(const Vec4& vec)
	: Quaternion(vec.x, vec.y, vec.z, vec.w)
{
}

Quaternion::Quaternion(float scalar)
	: Quaternion(scalar, scalar, scalar, scalar)
{
}

Quaternion::Quaternion(const Vec3& xyz, float w)
	: Quaternion(xyz.x, xyz.y, xyz.z, w)
{
}

Quaternion& Quaternion::operator=(const Quaternion & Quaternion)
{
	x = Quaternion.x;
	y = Quaternion.y;
	z = Quaternion.z;
	w = Quaternion.w;
	return *this;
}

Quaternion & Quaternion::setXYZ(const Vec3 & vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	return *this;
}

const Vec3 Quaternion::getXYZ() const
{
	return Vec3(x, y, z);
}

Quaternion & Quaternion::setElem(int idx, float value)
{
	*(&x + idx) = value;
	return *this;
}

float Quaternion::getElem(int idx) const
{
	return *(&x + idx);
}

Vec3 Quaternion::getAxis() const
{
	float x = 1.0f - w * w;
	if (x < 0.0000001f) // Divide by zero safety check
		return Vec3::xAxis();

	float x2 = x * x;
	return getXYZ() / x2;
}

Vec3 Quaternion::toEulerAngles() const
{
	return Vec3(atan2(2 * x * w - 2 * y * z, 1 - 2 * x * x - 2 * z * z),
		atan2(2 * y * w - 2 * x * z, 1 - 2 * y * y - 2 * z * z),
		asin(2 * x * y + 2 * z * w));
}

const Quaternion Quaternion::operator+(const Quaternion& quaternion) const
{
	return Quaternion(x + quaternion.x, y + quaternion.y, z + quaternion.z, w + quaternion.w);
}

const Quaternion Quaternion::operator-(const Quaternion& quaternion) const
{
	return Quaternion(x - quaternion.x, y - quaternion.y, z - quaternion.z, w - quaternion.w);
}

const Quaternion Quaternion::operator*(float scalar) const
{
	return Quaternion(x * scalar, y * scalar, z * scalar, w * scalar);
}

const Quaternion Quaternion::operator/(float scalar) const
{
	return Quaternion(x / scalar, y / scalar, z / scalar, w / scalar);
}

const Quaternion Quaternion::operator*(const Quaternion& quat) const
{
	return Quaternion(
		(((w * quat.x) + (x * quat.w)) + (y * quat.z)) - (z * quat.y),
		(((w * quat.y) + (y * quat.w)) + (z * quat.x)) - (x * quat.z),
		(((w * quat.z) + (z * quat.w)) + (x * quat.y)) - (y * quat.x),
		(((w * quat.w) - (x * quat.x)) - (y * quat.y)) - (z * quat.z)
		);
}

float Quaternion::operator [](int idx) const
{
	return *(&x + idx);
}


const Quaternion Quaternion::operator-() const
{
	return Quaternion(-x, -y, -z, -w);
}

bool Quaternion::operator ==(const Quaternion & Quaternion) const
{
	return (x == Quaternion.x) && (y == Quaternion.y) && (z == Quaternion.z) && (w == Quaternion.w);
}

bool Quaternion::operator !=(const Quaternion & Quaternion) const
{
	return !(*this == Quaternion);
}

const Quaternion Quaternion::identity()
{
	return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
}


Vec3 Quaternion::rotate(const Quaternion & quat, const Vec3 & vec)
{
	float tmpX, tmpY, tmpZ, tmpW;
	tmpX = (((quat.w * vec.x) + (quat.y * vec.z)) - (quat.z * vec.y));
	tmpY = (((quat.w * vec.y) + (quat.z * vec.x)) - (quat.x * vec.z));
	tmpZ = (((quat.w * vec.z) + (quat.x * vec.y)) - (quat.y * vec.x));
	tmpW = (((quat.x * vec.x) + (quat.y * vec.y)) + (quat.z * vec.z));
	return Vec3(
		((((tmpW * quat.x) + (tmpX * quat.w)) - (tmpY * quat.z)) + (tmpZ * quat.y)),
		((((tmpW * quat.y) + (tmpY * quat.w)) - (tmpZ * quat.x)) + (tmpX * quat.z)),
		((((tmpW * quat.z) + (tmpZ * quat.w)) - (tmpX * quat.y)) + (tmpY * quat.x))
		);
}

const Quaternion Quaternion::rotation(const Vec3& unitVec0, const Vec3& unitVec1)
{
	float cosHalfAngleX2, recipCosHalfAngleX2;
	cosHalfAngleX2 = sqrt((2.0f * (1.0f + unitVec0.dot(unitVec1))));
	recipCosHalfAngleX2 = (1.0f / cosHalfAngleX2);
	return Quaternion((unitVec0.cross(unitVec1) * recipCosHalfAngleX2), (cosHalfAngleX2 * 0.5f));
}

const Quaternion Quaternion::rotation(float radians, const Vec3 & unitVec)
{
	float angle = radians * 0.5f;
	return Quaternion((unitVec * sin(angle)), cos(angle));
}

float Quaternion::dot(const Quaternion& other) const
{
	float result = (x * other.x);
	result = (result + (y * other.y));
	result = (result + (z * other.z));
	result = (result + (w * other.w));
	return result;
}

Quaternion Quaternion::conjugate() const
{
	return Quaternion(-x, -y, -z, w);
}

NS_SP_END
