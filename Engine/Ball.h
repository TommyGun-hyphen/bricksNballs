#pragma once
#include "Vec2.h"
#include "RectCollider.h"
#include "Colors.h"
#include "Graphics.h"
class Ball
{
public:
	Ball() = default;
	void Init(Vec2 pos, Vec2 init_vel, int size, Color c);
private:
	RectCollider collider;
	int radius;
	Vec2 center;
	Color c;
	Vec2 velocity;
	void RevertY() { velocity = Vec2(velocity.GetX(), -velocity.GetY()); }
	void RevertX(){ velocity = Vec2( -velocity.GetX(), velocity.GetY()); }
public:
	void Draw(Graphics& gfx)const;
	void Update();
	bool IsColliding(RectCollider& other);
	
	void ChangeColor() { c = Colors::Red; }
};

