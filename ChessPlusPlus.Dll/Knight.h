#pragma once
#include "ChessPiece.h"

class CHESSPLUSPLUSDLL_API Knight : public ChessPiece
{
public:
	Knight(const Coordinate&);
	Knight(const std::string& coordinate_string);
	virtual ~Knight(){};

	virtual std::shared_ptr<Path> GetShortestPath(const Coordinate& dst);

	static std::vector<std::unique_ptr<Step>> GetNextSteps(const Step& scr);

private:
	static const int kMoveCount = 8;
	static const std::pair<int, int> kMoves[kMoveCount];
};

