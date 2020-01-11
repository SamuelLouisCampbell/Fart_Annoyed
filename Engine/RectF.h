#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(const float in_top, float in_bottom, float in_left, float in_right);
	RectF(const Vec2& topLeft,const Vec2& bottomRight);
	RectF(const Vec2& topLeft_in, float width_in, float height_in);
	bool OverlapTest(const RectF& other) const;
	static RectF FromCenter(const Vec2& center, float offset_x, float offset_y);
	RectF AddSomePadding(float padding_input) const;

public:
	bool isOverlapping = false;
	float top;
	float bottom;
	float left;
	float right; 
};

