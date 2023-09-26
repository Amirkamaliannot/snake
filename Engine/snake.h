#pragma once
#include <vector>
#include "MainWindow.h"
#include "Graphics.h"
#include "Colors.h"


struct node
{
	float x;
	float y;
};

class snake {

public:

	snake(float x, float y);

	void grow();

	void move_forward(MainWindow& wnd, float dt);

	bool isCollition();
	bool touch_wall();

	bool head_touch_item(float Item_x, float Item_y, float Item_size);




	bool body_touch_item(float Item_x, float Item_y, float Item_size);

	void draw(Graphics& gfx);

	int get_size() const;
	float get_node_size() const;
	node get_node(int index);
	void add_node();
	void increace_limit();
	void reduce_limit();



private:

	float v_x;
	float v_y;

	float node_size = 10.0f;
	float speed = 2.0f;

	int grow_rate = 5;

	Color body_color = { 0,255,0 };
	Color head_color = { 255,255,0 };
	Color padding = { 255,255, 128};


	std::vector <node> snake_vector;

};