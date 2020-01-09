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
	//{
	//	bool collided = false;
	//	const RectF rect = GetRect();
	//	if (rect.left < walls.left)
	//	{
	//		pos.x += walls.left - rect.left;
	//		ReboundX();
	//		collided = true;
	//	}
	//	else if (rect.right > walls.right)
	//	{
	//		pos.x -= rect.right - walls.right;
	//		ReboundX();
	//		collided = true;
	//	}
	//	if (rect.top < walls.top)
	//	{
	//		pos.y += walls.top - rect.top;
	//		ReboundY();
	//		collided = true;
	//	}
	//	else if (rect.bottom > walls.bottom)
	//	{
	//		pos.y -= rect.bottom - walls.bottom;
	//		ReboundY();
	//		collided = true;
	//	}
	//	return collided;
	//}
	if (boundary.left < windowBounds.left)
	{
		position.x += windowBounds.left - boundary.left;
		changeVx();
		collided = true;
	}
	else if (boundary.right > windowBounds.right)
	{
		position.x -= boundary.right - windowBounds.right;
		changeVx();
		collided = true;
	}
	if (boundary.top < windowBounds.top)
	{
		position.y += windowBounds.top - boundary.top;
		changeVy();
		collided = true;
	}
	else if (boundary.bottom > windowBounds.bottom)
	{
		
		position.y -= boundary.bottom - windowBounds.bottom;
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
