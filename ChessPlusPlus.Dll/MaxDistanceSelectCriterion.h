#pragma once
#include "SelectCriterion.h"

class CHESSPLUSPLUSDLL_API MaxDistanceSelectCriterion :
	public SelectCriterion
{
public:
	MaxDistanceSelectCriterion(double max_distance);

	virtual bool Filter(const Coordinate& candidate, const Coordinate& src, const Coordinate& dst) const;

private:
	double m_max_distance;
};

