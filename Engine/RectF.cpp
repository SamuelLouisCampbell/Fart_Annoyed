#include "RectF.h"

RectF::RectF(const float in_left, float in_right, float in_top, float in_bottom)
	:
	top(in_top),
	bottom(in_bottom),
	left(in_left),
	right(in_right)
{
}

RectF::RectF(const Vec2 & topLeft_in,const Vec2 & bottomRight_in)
	:
	RectF(topLeft_in.x, bottomRight_in.x, topLeft_in.y, bottomRight_in.y)
{
}

RectF::RectF(const Vec2 & topLeft_in, float width_in, float height_in)
	:
	RectF(topLeft_in, topLeft_in + Vec2( width_in, height_in))
{
}


bool RectF::OverlapTest(const RectF& incoming_rect) const 
{
	return
		top < incoming_rect.bottom &&
		bottom > incoming_rect.top &&
		left < incoming_rect.right &&
		right > incoming_rect.left;
	
}

RectF RectF::AddSomePadding(float padding_input) const
{	
	return RectF(left - padding_input, right + padding_input, top - padding_input, bottom + padding_input);
}

RectF RectF::FromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return RectF(center - half, center + half);
}
