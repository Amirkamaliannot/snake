#pragma once
#include <random>
#include "Graphics.h"
#include "snake.h"

class item
{
public:
	
	item(int _x, int _y);

	bool is_active();

	void change_status(bool status);

	void show_item(Graphics& gfx);

	void random_move(std::mt19937& rng, snake& Snake);



	void move(int _x, int _y);

	int get_x() const;
	int get_y() const;
	int get_size() const;


private:

	int x;
	int y;
	static constexpr int item_size= 10;

	bool active = false;

};

