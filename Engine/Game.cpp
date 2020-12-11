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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	//initializing all Bricks in the bricks[] array
	int row = 0;
	int col = 0;
	for (int i = 0; i < currBricks; i++) {
		if (col > brickCols-1) {
			col = 0;
			row++;
		}
		bricks[i].Init(Vec2( (3+50)*col+3 , (2+20)*row + 2 ), 50, 20, Colors::Blue);

		col++;
	}
	//initializing the first Ball	
	balls[currBalls].Init(Vec2(400.0f, 350.0f), Vec2(3.0f, 3.0f), 20, Colors::Yellow);
	currBalls++;
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
	CheckBrickCollision();
	for (int i = 0; i < currBalls; i++) {
		balls[0].Update();
	}
	
}

void Game::DestroyBrick(int i)
{
	for ( ; i < currBricks-1; i++) {
		bricks[i] = bricks[i + 1];
	}
	currBricks--;
}

void Game::CheckBrickCollision()
{
	for (int i = 0; i < currBalls; i++) {
		int brickCounter = 0;
		for (int j = 0; j < currBricks; j++) {
			if (balls[i].IsColliding(bricks[j].GetCollider())) {
				DestroyBrick(j);
				balls[i].ChangeColor();
			}
		}
	}
}

void Game::ComposeFrame()
{
	for (int i = 0; i < currBricks; i++) {
		bricks[i].Draw(gfx);
	}
	for (int i = 0; i < currBalls; i++) {
		balls[i].Draw(gfx);
	}
}
