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


	if (boundary.bottom > windowBounds.bottom - radius)
	{
		
		changeVy();
		collided = true;
	}
	else if (boundary.top < windowBounds.top + radius + 1.0f)
	{
		
		changeVy();
		collided = true; 
	}
	if (boundary.right > windowBounds.right - radius)
	{
		
		changeVx();
		collided = true;
	}
	else if (boundary.left < windowBounds.left + radius + 1.0f)
	{
		
		changeVx();
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

Vec2 Ball::GetVelocity() const
{
	return velocity; 
}


RectF Ball::MakeRect() const
{
	return RectF::FromCenter(position, radius, radius);
}
