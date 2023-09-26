#include "Timecounter.h"

Timecounter::Timecounter()
{
	last = std::chrono::steady_clock::now();
}

void Timecounter::reset_last()
{
	last = std::chrono::steady_clock::now();
}

float Timecounter::get_dt()
{
	std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
	std::chrono::duration <float> dt = now - last;
	return dt.count();
}
