#include "Brick.h"
#include "Graphics.h"

Brick::Brick(const RectF& rect_in, Color c_in)
	:
	rect(rect_in),
	c(c_in)
	{}

void Brick::Draw(Graphics& gfx)
{
	if (!destroyed)
	{
		gfx.DrawRect(rect, c);
	}
	else if(destroyed)
	{
		nohits = true;
	}

}

bool Brick::Destroyed(Ball& ball)
{
	
	if (rect.OverlapTest(ball.MakeRect()))
	{
		destroyed = true;
		if (!nohits)
		{
			ball.changeVy();
		}
	
	}
	return destroyed;
}


