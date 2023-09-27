#pragma once



class Vec2 {

public:
	Vec2() = default;
	Vec2(float _x, float _y);

	float X();
	float Y();

	bool operator==(const Vec2& rhs) const;

	Vec2 operator+(const Vec2& rhs) const;
	void operator+=(const Vec2& rhs);		
	
	Vec2 operator-(const Vec2& rhs) const;
	void operator-=(const Vec2& rhs);	
	
	Vec2 operator*(float r) const;
	void operator*=(float r);	
	
	Vec2 operator/(float r) const;
	void operator/=(float r);

	float get_length_witout_sqrt();
	float get_length();

	void normalize();
	Vec2 get_normalize();


private:
	float x;
	float y;


};
