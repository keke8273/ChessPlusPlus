// ChessPlusPlus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

#include "../ChessPlusPlus.Dll/ChessPlusPlus.Dll.h"
#include "../ChessPlusPlus.Dll/Coordinate.h"
#include "../ChessPlusPlus.Dll/InvalidCoordinateException.h"
#include "../ChessPlusPlus.Dll/Knight.h"
#include "../ChessPlusPlus.Dll/PathFinder.h"

void toUpper(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), toupper);
}


int _tmain(int argc, _TCHAR* argv[])
{
	
	std::string start_position;
	std::string target_position;

	while (true)
	{
		std::cout << "Enter your start position: (for example: A1, a1)" << std::endl;
		std::cin >> start_position;
		PathFinder pathFinder;

		try
		{
			std::cout << "Enter your target position:" << std::endl;
			std::cin >> target_position;

			std::vector<std::shared_ptr<Path>> pathes =
				pathFinder.GetShortestPath(Coordinate(start_position), Coordinate(target_position), Knight::GetNextSteps);

			toUpper(start_position);
			toUpper(target_position);

			for (auto& path : pathes)
			{
				std::cout << "STR : " << start_position << std::endl;
				std::cout << "END : " << target_position << std::endl;
				std::cout << "PTH (" << path->GetLength() << "): " << path->ToString() << std::endl << std::endl;
			}
		}
		catch (InvalidCoordinateException e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
