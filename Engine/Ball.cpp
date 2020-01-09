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

bool Ball::CollideWindow(const RectF & windowBounds)
{
	bool collided = false;
	const RectF boundary = MakeRect();
	
	if (boundary.left < windowBounds.left)
	{
		position.x = windowBounds.left;
		changeVx();
		collided = true;
	}
	else if (boundary.right > windowBounds.right)
	{
		position.x = windowBounds.right;
		changeVx();
		collided = true;
	}
	if (boundary.top < windowBounds.top)
	{
		position.y = windowBounds.top;
		changeVy();
		collided = true;
	}
	else if (boundary.bottom > windowBounds.bottom)
	{
		
		position.y = windowBounds.bottom;
		changeVy();
		collided = true;
	}
	return collided;
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
