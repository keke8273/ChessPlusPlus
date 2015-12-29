#pragma once
#include <vector>
#include "Step.h"

class CHESSPLUSPLUSDLL_API Path
{
public:
	Path();
	~Path(){};

	void AppendStep(const Step& step);
	inline const Step& EndStep() const { return m_steps.back(); };
	inline int GetLength() const { return m_steps.size(); }
	std::string ToString();

private:
	std::vector<Step> m_steps;
};

