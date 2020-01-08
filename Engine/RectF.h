#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float in_top, float in_bottom, float in_left, float in_right);
	RectF(Vec2& topLeft_in, Vec2& bottomRight_in);
	RectF(Vec2& topLeft_in, float width_in, float height_in);
	RectF(float offsetX_in, float offsetY_in, Vec2& center);
	bool OverlapTest(RectF& incoming_rect);

public:
	bool isOverlapping = false;
	float top;
	float bottom;
	float left;
	float right; 
};

