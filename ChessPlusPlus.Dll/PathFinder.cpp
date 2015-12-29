#include "stdafx.h"
#include "PathFinder.h"

void PathFinder::BuildPath(const Step& step)
{
	Path path;
	Step currentStep = step;
	while (currentStep.get_parent() != 0)
	{
		path.AppendStep(currentStep);
		currentStep = *currentStep.get_parent();
	}

	{
		std::lock_guard<std::mutex> lock(m_path_mutex);
		if (m_pathes.empty() || m_pathes[0]->GetLength() == path.GetLength())
		{
			m_pathes.push_back(std::make_shared<Path>(path));
		}
		else if (m_pathes[0]->GetLength() > path.GetLength())
		{
			m_pathes.clear();
			m_pathes.push_back(std::make_shared<Path>(path));
		}
	}

	m_is_path_found = true;
}

bool PathFinder::IsMorePathPossible(int index)
{
	if (index > m_stepVector.size())
		//no more candidates left.
		return false;

	if ((m_maximum_path_required != 0) && (m_pathes.size() >= m_maximum_path_required))
		return false;

	if (m_stepVector[index]->get_generation() > m_pathes[0]->GetLength())
		return false;

	return true;
}
