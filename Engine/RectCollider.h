#pragma once
#include "Vec2.h"
class RectCollider
{
public:
	RectCollider() = default;
	RectCollider(Vec2 pos, int width, int height);
	RectCollider(int x, int y, int right, int bottom) { RectCollider(Vec2(float(x), float(y)), width, height); }
	
	int GetX()const { return pos.GetX(); }
	int GetY()const { return pos.GetY(); }
	int GetWidth()const { return width; }
	int GetHeight()const { return height; }

	//collision system might work. but there might be a better implementation... GET TO WORK.
	bool isColliding(RectCollider other);
	void Move(Vec2 delta_pos) { pos += delta_pos; };
private:
	Vec2 pos;
	int width;
	int height;
	//bool Colliding;
};

