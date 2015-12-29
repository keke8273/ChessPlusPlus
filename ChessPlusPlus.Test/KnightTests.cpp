#include "stdafx.h"
#include "CppUnitTest.h"

#include "../ChessPlusPlus.Dll/ChessPlusPlus.Dll.h"
#include "../ChessPlusPlus.Dll/Knight.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessPlusPlusTest
{		
	TEST_CLASS(KnightTests)
	{
	public:

		TEST_METHOD(KnightTest_GetShortestPath_OneStepAway)
		{
			//Setup
			int expected_step_num = 1;
			Path expected;
			expected.AppendStep(Step(Coordinate("E6")));

			//Execute
			Knight target("D4");

			auto actual = target.GetShortestPath(Coordinate("E6"));

			//Verify
			Assert::AreEqual(expected_step_num, actual->GetLength());
			Assert::AreEqual(expected.ToString(), actual->ToString());
		}

		TEST_METHOD(KnightTest_GetShortestPath_TwoStepsAway)
		{
			//Setup
			int expected_step_num = 2;
			Path expected;
			expected.AppendStep(Step(Coordinate("E5")));
			expected.AppendStep(Step(Coordinate("F3")));

			//Execute
			Knight target("D4");

			auto actual = target.GetShortestPath(Coordinate("E5"));

			//Verify
			Assert::AreEqual(expected_step_num, actual->GetLength());
			Assert::AreEqual(expected.ToString(), actual->ToString());
		}

		TEST_METHOD(KnightTest_GetShortestPath_ThreeStepsAway)
		{
			//Setup
			int expected_step_num = 3;
			Path expected;
			expected.AppendStep(Step(Coordinate("D5")));
			expected.AppendStep(Step(Coordinate("F4")));
			expected.AppendStep(Step(Coordinate("E6")));

			//Execute
			Knight target("D4");

			auto actual = target.GetShortestPath(Coordinate("D5"));

			//Verify
			Assert::AreEqual(expected_step_num, actual->GetLength());
			Assert::AreEqual(expected.ToString(), actual->ToString());
		}

		TEST_METHOD(KnightTest_GetShortestPath_FourStepsAway)
		{
			//Setup
			int expected_step_num = 4;
			Path expected;
			expected.AppendStep(Step(Coordinate("B7")));
			expected.AppendStep(Step(Coordinate("D6")));
			expected.AppendStep(Step(Coordinate("C8")));
			expected.AppendStep(Step(Coordinate("B6")));

			//Execute
			Knight target("A8");

			auto actual = target.GetShortestPath(Coordinate("B7"));

			//Verify
			Assert::AreEqual(expected_step_num, actual->GetLength());
			Assert::AreEqual(expected.ToString(), actual->ToString());
		}
	};
}