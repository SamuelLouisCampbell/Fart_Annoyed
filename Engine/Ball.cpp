#include "Ball.h"

Ball::Ball(Vec2& pos_in, Vec2& vel_in)	
	:
	position(pos_in),
	velocity(vel_in)
	{
	}

void Ball::Draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(position,gfx);
}

void Ball::Update(float dt)
{
	position += velocity * dt;


}

bool Ball::CollideWindow(const RectF& windowBounds)
{
	bool collided = false;
	const RectF boundary = MakeRect();
	return collided; 

	if (boundary.bottom - radius > windowBounds.bottom)
	{
		position.y = windowBounds.bottom - radius;
		changeVy();
		collided = true;
	}
}

void Ball::changeVx()
{
	velocity.x = -velocity.x;
}

void Ball::changeVy()
{
	velocity.y = -velocity.y;
}

RectF Ball::MakeRect() const
{
	return RectF::FromCenter(position, radius, radius);
}
