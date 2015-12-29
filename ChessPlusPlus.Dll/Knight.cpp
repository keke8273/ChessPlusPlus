#include "stdafx.h"
#include "Knight.h"
#include "InvalidCoordinateException.h"
#include "Step.h"

const std::pair<int, int> Knight::kMoves[] =
{
	{ 1, 2 },
	{ 1, -2},
	{ 2, 1 },
	{ 2, -1},
	{ -1, 2},
	{ -1, -2},
	{ -2, 1},
	{ -2, -1},
};

Knight::Knight(const Coordinate& intial_coordinate)
	: ChessPiece(intial_coordinate)
{
}

Knight::Knight(const std::string& coordinate_string)
	: ChessPiece(Coordinate(coordinate_string))
{
}

std::shared_ptr<Path> Knight::GetShortestPath(const Coordinate& dst)
{
	std::vector<std::unique_ptr<Step>> steps;
	steps.push_back(std::make_unique<Step>(get_position()));

	std::shared_ptr<Path> path = std::make_shared<Path>();
	int i = 0;
	bool is_path_found = false;

	if (steps[i]->get_coordinate() == dst)
	{
		is_path_found = true;
		path->AppendStep(*steps[i]);
	}

	while (!is_path_found)
	{
		for (auto& step : GetNextSteps(*steps[i]))
		{
			if (step->get_coordinate() == dst)
			{
				path->AppendStep(*step);

				while ((path->EndStep().get_parent() != 0) && (*path->EndStep().get_parent() != *steps[0]))
				{
					path->AppendStep(*path->EndStep().get_parent());
				}

				is_path_found = true;
			}
			else
			{
				steps.push_back(std::move(step));
			}
		}
		i++;
	}

	return path;
}

std::vector<std::unique_ptr<Step>> Knight::GetNextSteps(const Step& scr)
{
	std::vector<std::unique_ptr<Step>> step;

	for (size_t i = 0; i < kMoveCount; i++)
	{
		try
		{
			auto coordinate = Coordinate(scr.get_coordinate().column() + kMoves[i].first, scr.get_coordinate().row() + kMoves[i].second);

			if (scr.get_parent() != 0)
			{ 
				if (scr.get_parent()->get_coordinate() == coordinate)
				{
					continue;
				}
			}

			step.push_back(std::make_unique<Step>(coordinate, scr));
		}
		catch (InvalidCoordinateException)
		{
		}
	}

	return step;
}


