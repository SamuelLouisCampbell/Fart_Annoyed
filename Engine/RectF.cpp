//#include "RectF.h"
//
//RectF::RectF(const float in_top, float in_bottom, float in_left, float in_right)
//	:
//	top(in_top),
//	bottom(in_bottom),
//	left(in_left),
//	right(in_right)
//{
//}
//
//RectF::RectF(const Vec2 & topLeft_in, Vec2 & bottomRight_in)
//	:
//	RectF(topLeft_in.x, bottomRight_in.x, topLeft_in.y, bottomRight_in.y)
//{
//}
//
//RectF::RectF(const Vec2 & topLeft_in, float width_in, float height_in)
//	:
//	RectF(topLeft_in, topLeft_in + Vec2( width_in, height_in))
//{
//}
//
//
//bool RectF::OverlapTest(RectF& incoming_rect)
//{
//	return
//		top <= incoming_rect.top &&
//		bottom >= incoming_rect.bottom &&
//		left <= incoming_rect.left &&
//		right >= incoming_rect.right;
//	
//}
//
//RectF RectF::FromCenter(const Vec2& center, float halfWidth, float halfHeight)
//{
//	const Vec2 half(halfWidth, halfHeight);
//	return RectF(center - half, center + half);
//}
//

#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectF::RectF(const Vec2& topLeft, const Vec2& bottomRight)
	:
	RectF(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
{
}

RectF::RectF(const Vec2& topLeft, float width, float height)
	:
	RectF(topLeft, topLeft + Vec2(width, height))
{
}

bool RectF::OverlapTest(const RectF& other) const
{
	return right > other.left&& left < other.right
		&& bottom > other.top&& top < other.bottom;
}

RectF RectF::FromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return RectF(center - half, center + half);
}
