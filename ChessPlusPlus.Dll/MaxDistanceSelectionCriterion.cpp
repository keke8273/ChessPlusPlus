#include "stdafx.h"
#include "MaxDistanceSelectCriterion.h"


MaxDistanceSelectCriterion::MaxDistanceSelectCriterion(double max_double)
	:m_max_distance(max_double)
{
}

bool MaxDistanceSelectCriterion::Filter(const Coordinate& candidate, const Coordinate& src, const Coordinate& dst) const
{
	return Coordinate::Distance(candidate, dst) - Coordinate::Distance(src, dst) > m_max_distance;
}

