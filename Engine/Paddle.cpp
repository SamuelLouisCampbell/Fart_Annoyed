#include "Paddle.h"

Paddle::Paddle(MainWindow& wnd, Vec2& pos_in, Color& col1_in, Color& col2_in)
	:
	wnd(wnd),
	pos(pos_in),
	innerColor(col1_in),
	outerColor(col2_in)
{
}

void Paddle::Draw(Graphics& gfx)
{
	gfx.DrawRect(MakeRect(), innerColor);
}

void Paddle::CollideWindow(const RectF& windowBounds)
{
	const RectF boundary = MakeRect();
	if (boundary.left < windowBounds.left + 1.0f)
	{
		pos.x = windowBounds.left + width + 1.0f;
	}
	else if (boundary.right > windowBounds.right)
	{
		pos.x = windowBounds.right - width;
	}
}


void Paddle::Update(float dt)
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += velocity * dt;
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= velocity * dt;
	}
}
bool Paddle::CollideBall(Ball& ball)
{
	bool collided = false;
	const RectF boundary = MakeRect();
	const RectF ballbound = ball.MakeRect();

	if (boundary.OverlapTest(ballbound))
	{
			ball.changeVy();
			collided = true;
	}
	
	return collided;
}

RectF Paddle::MakeRect() const
{
	return RectF::FromCenter(pos, width, height);
}

