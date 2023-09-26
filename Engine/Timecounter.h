#pragma once
#include <chrono>

class Timecounter {

public:
	Timecounter();
	void reset_last();

	float get_dt();

private:

	std::chrono::steady_clock::time_point last;

};