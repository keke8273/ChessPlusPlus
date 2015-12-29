#include "StdAfx.h"
#include "ChessPiece.h"


ChessPiece::ChessPiece(const Coordinate& intial_coordinate)
	:m_position(intial_coordinate)
{
}

void ChessPiece::Move(const Coordinate& dst)
{
	m_position = dst;
}
