#include "Ball.h"

Ball::Ball(Vec2& pos_in, Vec2& vel_in)
{
	position = pos_in;
	velocity = vel_in;
}

void Ball::Draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(position,gfx);
}

void Ball::Update()
{
	position += velocity;
}
