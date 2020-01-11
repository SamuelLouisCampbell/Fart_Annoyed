/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "RectF.h"
#include "Brick.h"
#include "Colors.h"
#include "Ball.h"
#include "Vec2.h"
#include "FrameTimer.h"
#include "Paddle.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();

private:
    static constexpr float paddleWidth = 100.0f;
    static constexpr float paddleHeight = 20.0f;
    static constexpr float padddleVelocity = 200.0f;

    Color innerColor = Colors::Red;
    Color outerColor = Colors::Red;
	MainWindow& wnd;
    Graphics gfx;
    FrameTimer ft;
    Color brickcol = Colors::Blue;
    RectF brickset = { 200.0f, 500.0f, 360.0f, 400.0f };
    Vec2 ballPos = { 200.0f,200.0f };
    Vec2 ballVel = { 200.0f,200.0f };
    Vec2 paddlePos = { float(gfx.ScreenWidth / 2), 550.0f };
    RectF window;
    Ball ball; 
    Brick brick;
    Paddle paddle; 
   
    
   
};