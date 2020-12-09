#include "RectCollider.h"

RectCollider::RectCollider(Vec2 pos, int width, int height):
	pos(pos),
	width(width),
	height(height),
	Colliding(false)
{
}

//collision system might work. but there might be a better implementation... GET TO WORK.
bool RectCollider::isColliding(RectCollider other)
{

	return !(pos.GetX() + width < other.pos.GetX() || pos.GetX() > other.pos.GetX() + other.width) && (  pos.GetY() + width < other.pos.GetY() || pos.GetY() > other.pos.GetY() + other.width  );
}
