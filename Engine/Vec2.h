#pragma once
#include <cmath>
class Vec2
{
public:
	Vec2() = default;
	Vec2(float x, float y);

	//opetations:
	Vec2 operator+(Vec2& rhs) const;
	Vec2& operator+=(Vec2& rhs);
	Vec2 operator*(float rhs) const;
	Vec2& operator*=(float rhs);
	Vec2 operator-(Vec2& rhs) const;
	Vec2& operator-=(Vec2& rhs);

	//getters
	float GetX()const { return x; }
	float GetY()const { return y; }

	//vector normalization
	void Normalize();
	Vec2 GetNormalized();
private:
	float x;
	float y;
};

