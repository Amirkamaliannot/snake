#pragma once
#include <random>
#include "Graphics.h"
#include "snake.h"

class item
{
public:
	
	item(float _x, float _y);

	bool is_active();

	void change_status(bool status);

	void show_item(Graphics& gfx);

	void random_move(std::mt19937& rng, snake& Snake);








	void move(int _x, int _y);

	float get_x() const;
	float get_y() const;
	float get_size() const;


private:

	float x;
	float y;
	static constexpr float item_size= 10;

	bool active = false;

};

