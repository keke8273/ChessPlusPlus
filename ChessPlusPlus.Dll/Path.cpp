#include "stdafx.h"
#include "Path.h"


Path::Path()
{
}

void Path::AppendStep(const Step& step)
{
	m_steps.push_back(step);
}

std::string Path::ToString()
{
	std::string path_str;

	for (std::vector<Step>::reverse_iterator it = m_steps.rbegin(); it != m_steps.rend(); ++it)
	{
		path_str.append((*it).ToString() + " ");
	}

	return path_str;
}
