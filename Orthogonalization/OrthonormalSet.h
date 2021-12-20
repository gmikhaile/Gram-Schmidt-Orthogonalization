#pragma once

#include <vector>
#include <memory>
#include <cmath>
#include <assert.h>


static const double eps = 1e-10;

struct Vec3D
{
	double x = 0;
	double y = 0;
	double z = 0;

	Vec3D(double x = 0, double y = 0, double z = 0)
		: x(x)
		, y(y)
		, z(z)
	{

	}

	bool isZero(double value) const
	{
		return std::abs(value) <= eps;
	}

	double dot(const Vec3D& other) const
	{
		const double scalar = x * other.x + y * other.y + z * other.z;

		return scalar;
	}

	double length() const
	{
		double length = sqrt((x * x) + (y * y) + (z * z));

		return length;
	}

	Vec3D normalize() const
	{
		const double vecLength = length();

		if (isZero(vecLength))
		{
			return Vec3D();
		}

		const Vec3D unitVec = Vec3D(x / vecLength, y / vecLength, z / vecLength);

		return unitVec;
	}
};


inline Vec3D operator*(const Vec3D& vec3D, double scalar)
{
	return Vec3D(vec3D.x * scalar, vec3D.y * scalar, vec3D.z * scalar);
}

inline Vec3D operator*(double scalar, const Vec3D& vec3D)
{
	return Vec3D(vec3D.x * scalar, vec3D.y * scalar, vec3D.z * scalar);
}

inline Vec3D operator-(const Vec3D& lhs, const Vec3D& rhs)
{
	return Vec3D(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}


using Set = std::vector<Vec3D>;

class OrthonormalSet
{
public:
	OrthonormalSet(const Set& vectors);
	void print() const;

private:
	void orthogonalize(const Set& vectors);
	Vec3D project(const Vec3D& from, const Vec3D& onto) const;
	
private:
	Set m_orthonormalNormalizedSet;
	Set m_orthonormalSet;
};

