#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "SpriteCodex.h"
#include "Vec2.h"

class Ball
{
public: 
	Ball() = default;
	Ball(Vec2& pos_in, Vec2& vel_in);

	void Draw(Graphics& gfx);
	void Update();

public:
	Vec2 position;
	Vec2 velocity;



};

