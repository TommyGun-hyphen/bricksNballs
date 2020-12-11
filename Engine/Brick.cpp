#include "Brick.h"

void Brick::Init(Vec2 pos, int width, int height, Color c)
{
	this->collider = RectCollider(pos, Brick::width, Brick::height);
	this->c = c;
}

void Brick::Draw(Graphics& gfx)
{
	for (int i = collider.GetX(); i < collider.GetX() + collider.GetWidth(); i++) {
		for (int j = collider.GetY(); j < collider.GetY() + collider.GetHeight(); j++) {
			gfx.PutPixel(i, j, c);
		}
	}
	gfx.PutPixel(collider.GetX(), collider.GetY(), Colors::Red);
	gfx.PutPixel(collider.GetX() + collider.GetWidth(), collider.GetY() + collider.GetHeight(), Colors::Red);
	gfx.PutPixel(collider.GetX(), collider.GetY() + collider.GetHeight(), Colors::Red);
	gfx.PutPixel(collider.GetX() + collider.GetWidth(), collider.GetY(), Colors::Red);
}
