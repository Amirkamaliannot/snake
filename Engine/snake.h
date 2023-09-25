#pragma once
#include <vector>
#include "MainWindow.h"
#include "Graphics.h"
#include "Colors.h"


struct node
{
	int x;
	int y;
};

class snake {

public:

	snake(int x, int y);

	void grow();

	void move_forward(MainWindow& wnd);

	bool isCollition();
	bool touch_wall();

	bool head_touch_item(int Item_x, int Item_y, int Item_size);




	bool body_touch_item(int Item_x, int Item_y, int Item_size);

	void draw(Graphics& gfx);

	int get_size() const;
	int get_node_size() const;
	node get_node(int index);
	void add_node();
	void increace_limit();
	void reduce_limit();



private:

	int v_x;
	int v_y;

	int node_size = 10;
	int speed_limit = 3;

	int grow_rate = 15;

	Color body_color = { 0,255,0 };
	Color head_color = { 255,255,0 };
	Color padding = { 255,255, 128};


	std::vector <node> snake_vector;

};