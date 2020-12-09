#pragma once
#include "Vec2.h"
#include "Colors.h"
#include "RectCollider.h"
#include "Graphics.h"
class Brick
{
public:
	Brick() = default;
	void Init(Vec2 pos, int width, int height, Color c);
	void Init(float x, float y, int width, int height, Color c) { Init(Vec2(x, y), width, height, c); }

	static constexpr int width = 50;
	static constexpr int height = 20;
private:
	
	RectCollider collider;
	Color c;
	bool isDestroyed;
public:
	void Draw(Graphics& gfx);
	bool Destroyed() { return isDestroyed; }
};

