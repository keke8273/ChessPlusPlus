#pragma once
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <algorithm>
#include <functional>

#include "Path.h"
#include "Step.h"

class CHESSPLUSPLUSDLL_API PathFinder
{
public:
	PathFinder():
		m_is_path_found(false),
		m_maximum_path_required(0),
		m_thread_count(min_thread_allowed)
	{
	}

	PathFinder(int maximum_path_required) :
		m_is_path_found(false),
		m_maximum_path_required(maximum_path_required),
		m_thread_count(min_thread_allowed)
	{
	}

	template <class GetNextSteps>
	std::vector<std::shared_ptr<Path>> GetShortestPath(const Coordinate& origin, const Coordinate& destination, GetNextSteps getNextSteps);

private:
	void BuildPath(const Step& step);
	bool IsMorePathPossible(int index);

	template <class GetNextSteps>
	void ProcessStep(int strIndex, const Coordinate& destination, GetNextSteps getNextSteps);
	
	const unsigned int min_thread_allowed = 2;
	const unsigned int max_thread_allowed = std::thread::hardware_concurrency() == 0 ? min_thread_allowed : std::thread::hardware_concurrency();

	std::vector<std::unique_ptr<Step>> m_stepVector;
	std::vector<std::shared_ptr<Path>> m_pathes;
	std::mutex m_stepVector_mutex;
	std::mutex m_path_mutex;
	bool m_is_path_found;
	int m_maximum_path_required;                   //default 0, find all possible path.
	int m_thread_count;
};

template <class GetNextSteps>
std::vector<std::shared_ptr<Path>> PathFinder::GetShortestPath(const Coordinate& origin, const Coordinate& destination, GetNextSteps getNextSteps)
{
	//Check Generation 0
	if (origin == destination)
	{
		BuildPath(Step(origin));
		return m_pathes;
	}

	m_stepVector.push_back(std::make_unique<Step>(origin));

	////Check Generation 1
	//for (auto& step : getNextSteps(*m_stepVector[0]))
	//{
	//	if (step->get_coordinate() == destination)
	//	{
	//		BuildPath(*step);
	//		return m_pathes;
	//	}
	//	else
	//	{
	//		m_stepVector.push_back(std::move(step));
	//	}
	//}

	//m_thread_count = std::min(m_stepVector.size() - 1, max_thread_allowed);

	//std::vector<std::thread> threads(m_thread_count - 1);

	//for (int i = 0; i < m_thread_count -1; i++)
	//{
	//	threads[i] = std::thread(std::mem_fn(&PathFinder::ProcessStep<GetNextSteps>), std::ref(*this), i + 1, destination, getNextSteps);
	//}

	ProcessStep(0, destination, getNextSteps);

	//for (auto& thread : threads)
	//{
	//	thread.join();
	//}
	return m_pathes;
}

template <class GetNextSteps>
void PathFinder::ProcessStep(int strIndex, const Coordinate& destination, GetNextSteps getNextSteps)
{
	int index = strIndex;

	while (!m_is_path_found || IsMorePathPossible(index))
	{
		for (auto& step : getNextSteps(*m_stepVector[index]))
		{
			if (step->get_coordinate() == destination)
			{
				BuildPath(*step);
			}
			else
			{
				std::lock_guard<std::mutex> lock(m_stepVector_mutex);
				m_stepVector.push_back(std::move(step));
			}
		}

		index++;
	}
}