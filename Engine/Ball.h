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
	
	RectF MakeRect() const;
	void Draw(Graphics& gfx);
	void Update(float dt);
	bool CollideWindow(const RectF& windowBounds);
	void changeVx();
	void changeVy();
	
private:
	Vec2 position;
	Vec2 velocity;
	static constexpr float radius = 7.0f;

};

