#include "snake.h"
#include <cassert>
#include "MainWindow.h"
#include "Graphics.h"
#include "Keyboard.h"
#include <math.h>

snake::snake(float x, float y)
{

	assert(snake_vector.size() == 0);
	v_x = 0.0f;
	v_y = 0.0f;
	snake_vector.push_back({ x, y });
}


void snake::grow()
{
	for (int i = 0; i < grow_rate; i++) {
		add_node();
	}
}

void snake::move_forward(MainWindow& wnd)
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
		
		if (v_x ==0.0f) {

			v_x = -speed;
			v_y = 0.0f;
		}

	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {

		if (v_x == 0.0f) {
			v_x = speed;
			v_y = 0.0f;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {

		if (v_y == 0.0f) {
			v_x = 0.0f;
			v_y = speed;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_UP)) {

		if (v_y == 0.0f) {
		
			v_x = 0.0f;
			v_y = -speed;
		}
	}

	if (v_x != 0 || v_y != 0) {

		for (int i = 0; i < snake_vector.size()-1; i++) {
			snake_vector[i] = snake_vector[i+1];
		}
	}
	snake_vector[snake_vector.size()-1].x += v_x;
	snake_vector[snake_vector.size()-1].y += v_y;
}



bool snake::isCollition()
{

	node last_node = get_node(get_size() - 1);

	int close_nodes = 0;
	for (int i = 0; i < get_size() - 1; i++) {
		if (  sqrt(pow(last_node.x - snake_vector[i].x , 2) + pow(last_node.y - snake_vector[i].y, 2)) < speed)
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
	node last_node = get_node(get_size()- 1); 


	if (last_node.x <= node_size + 0 ||
		last_node.x >= (Graphics::ScreenWidth - node_size) ||
		last_node.y <= node_size + 0 ||
		last_node.y >= (Graphics::ScreenHeight - node_size) ) {

		return true;
	}

	return false;
}


bool snake::head_touch_item(float Item_x, float Item_y, float Item_size)
{
	node last_node = get_node(get_size() - 1);

	if ((last_node.x - node_size/2.0f) < (Item_x + Item_size ) &&
		(last_node.x + node_size/2.0f) > (Item_x - Item_size ) &&
		(last_node.y - node_size/2.0f) < (Item_y + Item_size ) &&
		(last_node.y + node_size/2.0f) > (Item_y - Item_size )) {
		return true;
	}

	return false;
}

bool snake::body_touch_item(float Item_x, float Item_y, float Item_size)
{
	for (int i = 0; i < get_size() - 1; i++) {
		if ((snake_vector[i].x - node_size / 2.0f) < (Item_x + Item_size) &&
			(snake_vector[i].x + node_size / 2.0f) > (Item_x - Item_size) &&
			(snake_vector[i].y - node_size / 2.0f) < (Item_y + Item_size) &&
			(snake_vector[i].y + node_size / 2.0f) > (Item_y - Item_size)) {
			return true;
		}
	}

	return false;
}

void snake::draw(Graphics& gfx)
{
	for (int i = 0; i < snake_vector.size() -1; i++) {
			gfx.draw_square(snake_vector[i].x, snake_vector[i].y, node_size, body_color, padding);
	}
	
	gfx.draw_square(snake_vector[snake_vector.size()-1].x, snake_vector[snake_vector.size()-1].y, node_size, head_color, padding);
}

int snake::get_size() const
{
	return snake_vector.size();
}

float snake::get_node_size() const
{
	return node_size;
}

node snake::get_node(int index)
{
	return snake_vector[index];
}

void snake::add_node()
{
	assert(snake_vector.size() != 0);
	snake_vector.push_back({ snake_vector[snake_vector.size()-1].x+v_x , snake_vector[snake_vector.size()-1].y + v_y });
}

void snake::increace_limit()
{
	speed++;
}

void snake::reduce_limit()
{
	speed--;
}
