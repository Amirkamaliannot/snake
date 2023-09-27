#include "Vec2.h"
#include <math.h>

Vec2::Vec2(float _x, float _y)
{
	x = _x;
	y = _y;
}

float Vec2::X()
{
	return x;
}
float Vec2::Y()
{
	return y;
}

bool Vec2::operator==(const Vec2& rhs)const
{
	return (rhs.x == x && rhs.y == y);

}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
	return Vec2(x+rhs.x, y+rhs.y);
}

void Vec2::operator+=(const Vec2& rhs)
{
	x += rhs.x;
	y += rhs.y;
}

Vec2 Vec2::operator-(const Vec2& rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}

void Vec2::operator-=(const Vec2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
}

Vec2 Vec2::operator*(float r) const
{
	return Vec2(x * r, y * r);
}

void Vec2::operator*=(float r)
{
	x *= r;
	y *= r;
}

Vec2 Vec2::operator/(float r) const
{
	if (r != 0.0f) {
		return Vec2(x / r, y / r);
	}
	return *this;
}

void Vec2::operator/=(float r)
{
	if (r != 0.0f) {
		x /= r;
		y /= r;
	}
	else {
		x = 0;
		y = 0;
	}
}

float Vec2::get_length_witout_sqrt()
{
	return y * y + x * x;
}

float Vec2::get_length()
{
	return sqrt(get_length_witout_sqrt());
}

void Vec2::normalize()
{
	*this = get_normalize();
}

Vec2 Vec2::get_normalize()
{
	float length = get_length();

	if (length != 0.0f) {

		return *this / get_length();
	}
	else {
		return *this;
	}
}

