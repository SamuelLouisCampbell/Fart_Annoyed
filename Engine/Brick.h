#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rect_in, Color c_in);
	void Draw(Graphics& gfx);
	bool Destroyed(Ball& ball);

public:
	RectF rect;
	Color c;
	bool destroyed = false;
	bool nohits = false;


};
//class Brick
//{
//public:
//	Brick() = default;
//	Brick(const RectF& rect_in, Color color_in);
//	void Draw(Graphics& gfx) const;
//	bool DoBallCollision(Ball& ball);
//private:
//	RectF rect;
//	Color color;
//	bool destroyed = false;
//};
