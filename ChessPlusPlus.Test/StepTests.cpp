#include "stdafx.h"
#include "CppUnitTest.h"

#include "../ChessPlusPlus.Dll/ChessPlusPlus.Dll.h"
#include "../ChessPlusPlus.Dll/Step.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessPlusPlusTest
{		
	TEST_CLASS(StepTests)
	{
	public:

		TEST_METHOD(StepTest_GetCoordinate_Pass)
		{
			//Setup
			Coordinate expected("A1");
			Step target(expected);

			//Execute
			auto actual = target.get_coordinate();

			//Verify
			Assert::AreEqual(expected.ToString(), actual.ToString());
		}
	};
}