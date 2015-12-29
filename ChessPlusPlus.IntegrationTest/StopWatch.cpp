#include "StopWatch.h"
#include <ctime>

StopWatch::StopWatch():
m_duration_clock_cycle(0)
{
}

void StopWatch::Start()
{
	m_duration_clock_cycle = std::clock();
}

clock_t StopWatch::Stop()
{
	return (std::clock() - m_duration_clock_cycle);
}