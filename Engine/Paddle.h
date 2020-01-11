#pragma once
#include "ball.h"
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "MainWindow.h"
#include "Vec2.h"

class Paddle
{
public:
	RectF MakeRect() const;
	Paddle() = default;
	Paddle(MainWindow& wnd, Vec2& pos_in, Color& col1_in, Color& col2_in);
	void Draw(Graphics & gfx);
	void CollideWindow(const RectF& windowBounds);
	void Update(float dt);
	bool CollideBall(Ball& ball);

private:

	MainWindow& wnd;
	Vec2 pos; 
	Color& innerColor;
	Color& outerColor;
	float width = 40.0f;
	static constexpr float height = 10.0f;
	const float	velocity = 400.0f;

};

