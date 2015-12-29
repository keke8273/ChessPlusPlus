#pragma once
#include "Coordinate.h"

class CHESSPLUSPLUSDLL_API SelectCriterion
{
public:
	virtual bool Filter(const Coordinate& candidate, const Coordinate& src, const Coordinate& dst) const = 0;
};
