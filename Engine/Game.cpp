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
#include <iostream>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	x_dist(50.0f, 750.0f),
	y_dist(50.0f, 550.0f),
	snake_( (float)(Graphics::ScreenWidth / 2), (float)(Graphics::ScreenHeight / 2) ),
	Item(x_dist(rng), y_dist(rng))
{


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

	float DT = tc.get_dt();
	tc.reset_last();


	if (snake_.touch_wall() || snake_.isCollition()) {
		game_over = true;
	}

	show_padding();

	if (!game_over) {

		Item.random_move(rng, snake_);

		if (snake_.head_touch_item(Item.get_x(), Item.get_y(), Item.get_size() )) {
		
			Item.change_status(false);
			snake_.grow();
		}
		else {

			snake_.move_forward(wnd, DT*100.0f);
		}

	}

}


void Game::show_padding()
{
	gfx.draw_reqt(0, 0, 10, Graphics::ScreenHeight, { 255,5,255 });
	gfx.draw_reqt(0, 0, Graphics::ScreenWidth, 10, { 255,5,255 });

	gfx.draw_reqt(0, Graphics::ScreenHeight-10 , Graphics::ScreenWidth-10 , 10, { 255,5,255 });
	gfx.draw_reqt(Graphics::ScreenWidth-10, 0, 10 , Graphics::ScreenHeight , { 255,5,255 });
}

void Game::ComposeFrame()
{

		
	Item.show_item(gfx);
	snake_.draw(gfx);

	

}


