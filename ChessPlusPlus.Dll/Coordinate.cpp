#include "stdafx.h"
#include <ctype.h>
#include "Coordinate.h"
#include "ChessBoard.h"
#include "InvalidCoordinateException.h"

Coordinate::Coordinate(const std::string& coordinate_str)
{
	if (coordinate_str.length() != 2)
	{
		throw  InvalidCoordinateException(coordinate_str);
	}

	if (isalpha(coordinate_str.c_str()[0]) == 0)
	{
		throw InvalidCoordinateException(coordinate_str);
	}

	if (isdigit(coordinate_str.c_str()[1]) == 0)
	{
		throw InvalidCoordinateException(coordinate_str);
	}

	int column = tolower(coordinate_str.c_str()[0]) - 0x60;
	int row = static_cast<int>(coordinate_str.c_str()[1]) - 0x30;

	if (IsValidColumn(column))
	{
		throw  InvalidCoordinateException(coordinate_str);
	}

	if (IsValidRow(row))
	{
		throw  InvalidCoordinateException(coordinate_str);
	}

	m_column = column;
	m_row = row;
}

Coordinate::Coordinate(int column, int row)
{
	if (IsValidColumn(column))
	{
		throw  InvalidCoordinateException();
	}

	if (IsValidRow(row))
	{
		throw  InvalidCoordinateException();
	}

	m_column = column;
	m_row = row;
}

bool Coordinate::IsValidColumn(int value)
{
	return (value > ChessBoard::kColumnMax || value < ChessBoard::kColumnMin);
}

bool Coordinate::IsValidRow(int value)
{
	return (value > ChessBoard::kRowMax || value < ChessBoard::kRowMin);
}

std::string Coordinate::ToString()
{
	std::string str;
	str.append(1, static_cast<char>(m_column + 0x40));
	str.append(1, static_cast<char>(m_row    + 0x30));
	return str;
}

double Coordinate::Distance(const Coordinate& src, const Coordinate& dst)
{
	int xdistance = src.column() - dst.column();
	int ydistance = src.row() - dst.row();
	
	return std::sqrt(std::pow(xdistance, 2) + std::pow(ydistance, 2));
}
