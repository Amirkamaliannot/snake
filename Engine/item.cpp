#include "item.h"
#include "Graphics.h"

item::item(float _x, float _y)
{
	x = _x;
	y = _y;

}

bool item::is_active()
{
	return active;
}

void item::change_status(bool status)
{
	active = status;
}

void item::show_item(Graphics& gfx)
{
	if (active) {

		gfx.draw_square(x, y, item_size, 255, 0, 0);

	}
}



void item::random_move(std::mt19937& rng, snake& Snake){
	std::uniform_real_distribution<float> dist_x(50, 750);
	std::uniform_real_distribution<float> dist_y(50, 550);
	if (!active) {
		do {
			move(dist_x(rng), dist_y(rng));
			change_status(true);
		} while (Snake.body_touch_item(get_x(), get_y(), get_size())  );
	}
}

void item::move(int _x, int _y)
{
	x = _x;
	y = _y;
}

float item::get_x() const
{
	return x;
}
float item::get_y() const
{
	return y;
}

float item::get_size() const
{
	return item_size;
}
