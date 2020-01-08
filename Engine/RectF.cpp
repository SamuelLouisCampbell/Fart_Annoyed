#include "RectF.h"

RectF::RectF(float in_top, float in_bottom, float in_left, float in_right)
{
	top = in_top;
	bottom = in_bottom;
	left = in_left;
	right = in_right;
}

RectF::RectF(Vec2& topLeft_in, Vec2& bottomRight_in)
{
	RectF(topLeft_in.x, topLeft_in.y, bottomRight_in.x, bottomRight_in.y);
}

RectF::RectF(Vec2& topLeft_in, float width_in, float height_in)
{
	RectF(topLeft_in.x, topLeft_in.y, width_in, height_in);
}

RectF::RectF(float offsetX_in, float offsetY_in, Vec2& center)
{
	RectF(center, (offsetX_in / 2.0f), (offsetY_in / 2.0f));
}

bool RectF::OverlapTest(RectF& incoming_rect)
{
	return
		top <= incoming_rect.top &&
		bottom >= incoming_rect.bottom &&
		left <= incoming_rect.left &&
		right >= incoming_rect.right;
	
}

