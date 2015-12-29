#pragma once
#include <ctime>

class StopWatch
{
public:
	StopWatch();
	~StopWatch(){};

	void Start();
	clock_t Stop();

private:

	static const int k_ms_per_sec = 1000;
	static const int k_us_per_ms  = 1000;

	clock_t m_duration_clock_cycle;
};

