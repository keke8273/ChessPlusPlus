#pragma once
#include <memory>
#include "Coordinate.h"
#include "Path.h"

class CHESSPLUSPLUSDLL_API ChessPiece
{
public:

	ChessPiece(const Coordinate&);
	virtual ~ChessPiece(void){};

	virtual std::shared_ptr<Path> GetShortestPath(const Coordinate& dst) = 0;

	void Move(const Coordinate& dst);

protected:
	//virtual std::vector<std::unique_ptr<Step>> GetNextSteps(const Step& scr) const = 0;

	inline const Coordinate& get_position() const { return m_position; }

private:
	Coordinate m_position;
};

