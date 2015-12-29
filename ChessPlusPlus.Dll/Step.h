#pragma once
#include "Coordinate.h"

class CHESSPLUSPLUSDLL_API Step
{
public:
	Step(const Coordinate& coordinate);
	Step(const Coordinate& coordinate, const Step& parent);
	Step(Step&& other);
	~Step(){};

	const Coordinate& get_coordinate() const { return m_coordinate; }
	const Step* get_parent() const { return m_parent; }
	int get_generation() const { return m_generation; }
	std::string ToString();

	friend inline bool operator==(const Step& lhs, const Step& rhs)
	{
		return (lhs.m_coordinate == rhs.m_coordinate && lhs.m_parent == rhs.m_parent);
	}

	friend inline bool operator!=(const Step& lhs, const Step& rhs)
	{
		return !(lhs == rhs);
	}

private:
	Coordinate m_coordinate;
	const Step* m_parent;
	int m_generation;
};

