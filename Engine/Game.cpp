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
	//initializing all Bricks in the bricks[][] matrix
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 15; i++) {
			bricks[j][i].Init(Vec2(float( (3+Brick::width)* i +3 ),float( (2+Brick::height)*j) ), 50, 20, Colors::Blue);
		}
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
	for (int i = 0; i < currBalls; i++) {
		balls[0].Update();
	}
}

void Game::DestroyBrick(int j, int i)
{
	const int currElement = j * brickCols + i +1;
	for (int k = currElement; k < currBricks; k++) {
		if (i > brickCols - 1) {
			j++;
			i = 0;
		}

		if (i + 1 < brickCols) {
			bricks[i][j] = bricks[i + 1][j];
		}
		else
		{
			bricks[i][j] = bricks[0][j + 1];
		}
		i++;
	}
	currBricks--;
}

void Game::CheckBrickCollision()
{
	for (int i = 0; i < currBalls; i++) {
		int brickCounter = 0;
		for (int j = 0; j < currBricks; j++) {
			
		}
	}
}

void Game::ComposeFrame()
{
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 15; i++) {
			bricks[j][i].Draw(gfx);
		}
	}
	for (int i = 0; i < currBalls; i++) {
		balls[i].Draw(gfx);
	}
}
