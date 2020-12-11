#include "Ball.h"
#include <cmath>
void Ball::Init(Vec2 pos, Vec2 init_vel, int size, Color c)
{
	collider = RectCollider(pos, size, size);
	this->c = c;
	this->radius = size / 2;
	this->center = Vec2(pos.GetX() + radius, pos.GetY() + radius);
	this->velocity = init_vel;
}

void Ball::Update()
{
	if (collider.GetX() <= 1 + std::abs( velocity.GetX() ) || collider.GetX() + collider.GetWidth() >= 799 - std::abs( velocity.GetX()) ) {
		velocity = Vec2(-velocity.GetX(), velocity.GetY());
	}
	if (collider.GetY() <= 1 + std::abs( velocity.GetY() ) || collider.GetY() + collider.GetHeight() >= 599 - std::abs( velocity.GetY()) ) {
		velocity = Vec2(velocity.GetX(), -velocity.GetY());
	}
	collider.Move(velocity);
	center = Vec2(collider.GetX() + radius, collider.GetY() + radius);
	
}

bool Ball::IsColliding(RectCollider& other)
{
	if (collider.isColliding(other)) {
		if (velocity.GetX() > 0 && velocity.GetY() > 0) {
			if ((collider.GetX() + collider.GetWidth()) - other.GetX() < (collider.GetY() + collider.GetHeight()) - other.GetY()) {
				RevertX();
			}
			else {
				RevertY();
			}
		}
		else if (velocity.GetX() < 0 && velocity.GetY() < 0) {
			if (other.GetX() + other.GetWidth() - collider.GetX() < other.GetY() + other.GetHeight() - collider.GetY()) {
				RevertX();
			}
			else {
				RevertY();
			}
		}
		else if (velocity.GetX() < 0 && velocity.GetY() > 0) {
			if (other.GetX() + other.GetWidth() - collider.GetX() < (collider.GetY() + collider.GetHeight()) - other.GetY()) {
				RevertX();
			}
			else {
				RevertY();
			}
		}
		else if (velocity.GetX() > 0 && velocity.GetY() < 0) {
			if ((collider.GetY() + collider.GetHeight()) - other.GetY() < other.GetX() + other.GetWidth() - collider.GetX()) {
				RevertX();
			}
			else {
				RevertY();
			}
		}
	}
	return collider.isColliding(other);
}

void Ball::Draw(Graphics& gfx)const
{
	for (int i = collider.GetX(); i < collider.GetX() + collider.GetWidth(); i++) {
		for (int j = collider.GetY(); j < collider.GetY() + collider.GetHeight(); j++) {
			if ( (center.GetX() - i)*(center.GetX() - i) + (center.GetY() - j)*(center.GetY() - j) <= radius*radius) {
				gfx.PutPixel(i, j, c);
			}
		}
	}
	gfx.PutPixel(collider.GetX(), collider.GetY(), Colors::Red);
}
//updates position using the velocity

