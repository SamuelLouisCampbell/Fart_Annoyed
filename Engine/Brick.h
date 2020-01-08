#pragma once
#include "Graphics.h"
#include "RectF.h"

class Brick
{
public:
	Brick() = default;
	Brick(RectF& rect_in, Color c_in);
	void Draw(Graphics& gfx);

public:
	RectF& rect;
	Color& c; 
	bool destroyed = false;

};

