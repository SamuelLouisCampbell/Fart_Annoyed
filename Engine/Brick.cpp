#include "Brick.h"
#include "Graphics.h"

Brick::Brick(RectF& rect_in, Color& c_in)
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

}
