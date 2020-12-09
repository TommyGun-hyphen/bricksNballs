#include "Vec2.h"

Vec2::Vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vec2 Vec2::operator+(Vec2 & rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 & Vec2::operator+=(Vec2 & rhs)
{
	return *this = *this + rhs;
}

Vec2 Vec2::operator*(float rhs) const
{
	return Vec2(x * rhs, y * rhs);
}

Vec2 & Vec2::operator*=(float rhs)
{
	return *this = *this * rhs;
}

Vec2 Vec2::operator-(Vec2 & rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}

Vec2 & Vec2::operator-=(Vec2 & rhs)
{
	return *this = *this - rhs;
}


void Vec2::Normalize()
{
	float magnitude = std::sqrt(x*x + y * y);
	x /= magnitude;
	y /= magnitude;
}

Vec2 Vec2::GetNormalized()
{
	float magnitude = std::sqrt(x*x + y * y);
	return *this * (1.0f/magnitude);
}

