#include "snake.h"
#include <cassert>
#include "MainWindow.h"
#include "Graphics.h"
#include "Keyboard.h"
#include <math.h>



snake::snake(float x, float y)
{

	assert(snake_vector.size() == 0);

	snake_vector.push_back({ x, y });
}


void snake::grow()
{
	for (int i = 0; i < grow_rate; i++) {
		add_node();
	}
}

void snake::move_forward(MainWindow& wnd, float dt)
{

	if (wnd.kbd.KeyIsPressed('w')) {
		increace_limit();
	}
	else if (wnd.kbd.KeyIsPressed('s')) {

		if (speed> 0.0f) {
			reduce_limit();

		}
	}


	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		
		if (V.X() == 0.0f) {

			V = Vec2(-speed , 0.0f) * dt;
		}

	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {

		if (V.X() == 0.0f) {

			V = Vec2(speed, 0.0f) * dt;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {

		if (V.Y() == 0.0f) {

			V = Vec2(0.0f, speed) * dt;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_UP)) {

		if (V.Y() == 0.0f) {
		
			V = Vec2(0.0f, -speed) * dt;
		}
	}

	if (V.X() != 0.0f || V.Y() != 0.0f) {

		for (int i = 0; i < snake_vector.size()-1; i++) {
			snake_vector[i] = snake_vector[i+1];
		}
	}
	snake_vector[snake_vector.size() - 1] += V;
}



bool snake::isCollition()
{

	Vec2 last_node = get_node(get_size() - 1);

	int close_nodes = 0;
	for (int i = 0; i < get_size() - 1; i++) {
		if (snake_vector[i].distance_without_sqrt(last_node) < speed * speed)
		{
			close_nodes++;
		}
	}
	if (close_nodes > 0) {
		return true;
	}
	return false;
}


bool snake::touch_wall()
{
	Vec2 last_node = get_node(get_size()- 1); 


	if (last_node.X() <= node_size + 0.0f ||
		last_node.X() >= (Graphics::ScreenWidth - node_size) ||
		last_node.Y() <= node_size + 0.0f ||
		last_node.Y() >= (Graphics::ScreenHeight - node_size)) {

		return true;
	}

	return false;
}


bool snake::head_touch_item(float Item_x, float Item_y, float Item_size)
{
	Vec2 last_node = get_node(get_size() - 1);

	if ((last_node.X() - node_size/2.0f) < (Item_x + Item_size ) &&
		(last_node.X() + node_size/2.0f) > (Item_x - Item_size ) &&
		(last_node.Y() - node_size/2.0f) < (Item_y + Item_size ) &&
		(last_node.Y() + node_size/2.0f) > (Item_y - Item_size )) {
		return true;
	}

	return false;
}

bool snake::body_touch_item(float Item_x, float Item_y, float Item_size)
{
	for (int i = 0; i < get_size() - 1; i++) {
		if ((snake_vector[i].X() - node_size / 2.0f) < (Item_x + Item_size) &&
			(snake_vector[i].X() + node_size / 2.0f) > (Item_x - Item_size) &&
			(snake_vector[i].Y() - node_size / 2.0f) < (Item_y + Item_size) &&
			(snake_vector[i].Y() + node_size / 2.0f) > (Item_y - Item_size)) {
			return true;
		}
	}

	return false;
}

void snake::draw(Graphics& gfx)
{
	for (int i = 0; i < snake_vector.size() -1; i++) {
			gfx.draw_square(snake_vector[i].X(), snake_vector[i].Y(), node_size, body_color, padding);
	}
	
	gfx.draw_square(snake_vector[snake_vector.size()-1].X(), snake_vector[snake_vector.size() - 1].Y(), node_size, head_color, padding);
}

int snake::get_size() const
{
	return snake_vector.size();
}

float snake::get_node_size() const
{
	return node_size;
}

Vec2 snake::get_node(int index)
{
	return snake_vector[index];
}

void snake::add_node()
{
	assert(snake_vector.size() != 0);
	snake_vector.push_back({ snake_vector[snake_vector.size() - 1] + V });	
}

void snake::increace_limit()
{
	speed++;
}

void snake::reduce_limit()
{
	speed--;
}
