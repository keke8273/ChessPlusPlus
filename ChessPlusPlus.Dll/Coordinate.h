#pragma once
#include <string>

class CHESSPLUSPLUSDLL_API Coordinate
{
public:
	Coordinate(const std::string& coordinate_string);
	Coordinate(int column, int row);

	~Coordinate(){};

	static double Distance(const Coordinate& src, const Coordinate& dst);

	bool IsValidColumn(int value);

	bool IsValidRow(int value);
	
	std::string ToString();

	inline int column() const { return m_column; }

	inline int row() const { return m_row; }

	inline bool operator==(const Coordinate& other)
	{
		return (this->m_column == other.m_column && this->m_row == other.m_row);
	}
	
	friend inline bool operator==(const Coordinate& lhs, const Coordinate& rhs)
	{
		return (lhs.m_column == rhs.m_column && lhs.m_row == rhs.m_row);
	}

	friend inline bool operator!=(const Coordinate& lhs, const Coordinate& rhs)
	{
		return !(lhs == rhs);
	}

private:
	int m_column;
	int m_row;
};


