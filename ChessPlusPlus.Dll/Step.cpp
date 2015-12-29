#include "stdafx.h"
#include "Step.h"


Step::Step(const Coordinate& coordinate) :
m_coordinate(coordinate),
m_parent(0),
m_generation(0)
{
}

Step::Step(const Coordinate& coordinate, const Step& parent):
m_coordinate(coordinate),
m_parent(&parent)
{
	m_generation = parent.get_generation();
	++m_generation;
}

//if std::move is not used to cast the members into there rvalue ref form &&,
//copy construtor of the members are likely to be invoked during the construction of the object.
Step::Step(Step&& other) :
m_coordinate(std::move(other.m_coordinate)),
m_parent(std::move(other.m_parent)),
m_generation(std::move(other.m_generation))
{
	//null the pointer of the dying object.
	other.m_parent = 0;
}

std::string Step::ToString()
{
	return m_coordinate.ToString();
}


