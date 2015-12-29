#include <fstream>
#include <ctime>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <thread>
#include <future>
#include "StopWatch.h"

//Targets
#include "../ChessPlusPlus.Dll/ChessPlusPlus.Dll.h"
#include "../ChessPlusPlus.Dll/Coordinate.h"
#include "../ChessPlusPlus.Dll/InvalidCoordinateException.h"
#include "../ChessPlusPlus.Dll/Knight.h"
#include "../ChessPlusPlus.Dll/MaxDistanceSelectCriterion.h"
#include "../ChessPlusPlus.Dll/PathFinder.h"

static const std::string COORDINATES[] =
{
	"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8",
	"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8",
	"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8",
	"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8",
	"E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8",
	"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8",
	"G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8",
	"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8",
};

std::mutex mu;
std::condition_variable cond;
std::ostringstream log_buff;
bool test_completed;
volatile int test_count = 0;

void run_test(std::promise<int>& pr)
{
	for (auto const& src : COORDINATES)
	{
		for (auto const& tgt : COORDINATES)
		{
			StopWatch test_watch;
			test_watch.Start();
			PathFinder pathFinder;

			std::vector<std::shared_ptr<Path>> pathes =
				pathFinder.GetShortestPath(Coordinate(src), Coordinate(tgt), Knight::GetNextSteps);
			clock_t test_clk_cycle = test_watch.Stop();

			log_buff << "STR: " << src << " END: " << tgt
				<< " PATHES " << pathes.size()
				<< " \tTIME " << test_clk_cycle / (double)CLOCKS_PER_SEC
				<< " \tCLOCK " << test_clk_cycle
				<< std::endl;

			for (auto& path : pathes)
			{
				log_buff << "PTH (" << path->GetLength() << "): " << path->ToString() << std::endl;
			}

			log_buff << std::endl;

			test_count++;
			//pr.set_value(index++);
			cond.notify_one();
		}
	}

	test_completed = true;
}

int main()
{	
	std::promise<int> pr;

	StopWatch total_watch;
	total_watch.Start();
	std::thread worker_thread(run_test, std::ref(pr));
	
	while (!test_completed)
	{
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker);
		//int test_count = pr.get_future().get();
		std::cout << "\r" << "Calculating... " << std::fixed << std::setprecision(2) << (double)test_count / 4096 * 100 << "%";
	}

	worker_thread.join();

	double total_test_time = total_watch.Stop() / (double)CLOCKS_PER_SEC;
	log_buff << "TOTAL TIME: " << std::fixed << std::setprecision(3) << total_test_time << " s" << std::endl;
	std::cout << "\nTOTAL TIME: " << std::fixed << std::setprecision(3) << total_test_time << " s" << std::endl;

	time_t unix_time_stamp;
	struct tm* time_info;
	char time_str[100];

	time(&unix_time_stamp);
	time_info = std::localtime(&unix_time_stamp);
	std::strftime(time_str, 100, "%Y_%m_%d_%H_%M", time_info);
	std::ofstream logFile("fliu_" + std::string(time_str) + ".txt");
	logFile << log_buff.str();

	log_buff.clear();
}