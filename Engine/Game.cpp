/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include "Colors.h"
#include "Graphics.h"
#include "FrameTimer.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
    window(0.0f, float(gfx.ScreenWidth), 0.0f,float( gfx.ScreenHeight)),
    ball(ballPos, ballVel),
    paddle(wnd,paddlePos, innerColor, outerColor)
{
    const Color brickcol[4] = { Colors::Blue, Colors::LightGray, Colors::Magenta, Colors::Green };
    const Vec2 topLeft(40.0f, 40.0f);

    int i = 0;

    for (int y = 0; y < gridHeight; y++)
    {
        const Color c = brickcol[y];
        for (int x = 0; x < gridWidth; x++)
        {
            bricks[i] = Brick(RectF(
                topLeft + Vec2(x * brickWidth, y * brickHeight),
                brickWidth, brickHeight), c);
            i++;
        }
    }
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
  
}

void Game::UpdateModel()
{
   
    float dt = ft.Mark();
    ball.CollideWindow(window);
    ball.Update(dt);
    for (Brick& b : bricks)
    {
        b.Destroyed(ball);
    }
    paddle.Update(dt);
    paddle.CollideBall(ball);
    paddle.CollideWindow(window);
  
   
}

void Game::ComposeFrame()
{
    for (Brick& b : bricks)
    {
        b.Draw(gfx);
    }
    ball.Draw(gfx);
    paddle.Draw(gfx);

}
