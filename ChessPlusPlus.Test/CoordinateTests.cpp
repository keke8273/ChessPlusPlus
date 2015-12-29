#include "stdafx.h"
#include "CppUnitTest.h"

#include "../ChessPlusPlus.Dll/ChessPlusPlus.Dll.h"
#include "../ChessPlusPlus.Dll/Coordinate.h"
#include "../ChessPlusPlus.Dll/InvalidCoordinateException.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessPlusPlusTest
{		
	TEST_CLASS(CoordinateTests)
	{
	public:
		
		TEST_METHOD(CoordinateTest_ValidCoordinate_MinimumColumn_MinimumRow)
		{
			//Setup
			int expected_column = 1;
			int expected_row    = 1;
			std::string expected_string = "A1";

			//Execute
			Coordinate actual("A1");

			//Verify
			Assert::AreEqual<int>(expected_column, actual.column());
			Assert::AreEqual<int>(expected_row,    actual.row());
			Assert::AreEqual(expected_string, actual.ToString());
		}

		TEST_METHOD(CoordinateTest_ValidCoordinate_MinimumColumn_MaximumRow)
		{
			//Setup
			int expected_column = 1;
			int expected_row = 8;
			std::string expected_string = "A8";

			//Execute
			Coordinate actual("A8");

			//Verify
			Assert::AreEqual<int>(expected_column, actual.column());
			Assert::AreEqual<int>(expected_row, actual.row());
			Assert::AreEqual(expected_string, actual.ToString());
		}

		TEST_METHOD(CoordinateTest_ValidCoordinate_MaximumColumn_MaximumRow)
		{
			//Setup
			int expected_column = 8;
			int expected_row = 8;
			std::string expected_string = "H8";

			//Execute
			Coordinate actual("H8");

			//Verify
			Assert::AreEqual<int>(expected_column, actual.column());
			Assert::AreEqual<int>(expected_row, actual.row());
			Assert::AreEqual(expected_string, actual.ToString());
		}

		TEST_METHOD(CoordinateTest_ValidCoordinate_MaximumColumn_MinimumRow)
		{
			//Setup
			int expected_column = 8;
			int expected_row = 1;
			std::string expected_string = "H1";

			//Execute
			Coordinate actual("H1");

			//Verify
			Assert::AreEqual<int>(expected_column, actual.column());
			Assert::AreEqual<int>(expected_row, actual.row());
			Assert::AreEqual(expected_string, actual.ToString());
		}

		TEST_METHOD(CoordinateTest_ValidCoordinate_ConstructWithIntegers)
		{
			//Setup
			int expected_column = 8;
			int expected_row = 1;
			std::string expected_string = "H1";

			//Execute
			Coordinate actual(8, 1);

			//Verify
			Assert::AreEqual<int>(expected_column, actual.column());
			Assert::AreEqual<int>(expected_row, actual.row());
			Assert::AreEqual(expected_string, actual.ToString());
		}

		TEST_METHOD(CoordinateTest_InvalidCoordinate_InvalidColume)
		{
			//Setup
			std::string expected_exception_msg = "01 is not an valid coordinate!";

			//Execute
			try
			{
				Coordinate actual("01");
				Assert::Fail();
			}
			catch (InvalidCoordinateException e)
			{
				Assert::AreEqual(expected_exception_msg.c_str(), e.what());
			}
		}

		TEST_METHOD(CoordinateTest_InvalidCoordinate_InvalidColume_OutOfRange)
		{
			//Setup
			std::string expected_exception_msg = "J1 is not an valid coordinate!";

			//Execute
			try
			{
				Coordinate actual("J1");
				Assert::Fail();
			}
			catch (InvalidCoordinateException e)
			{
				Assert::AreEqual(expected_exception_msg.c_str(), e.what());
			}
		}

		TEST_METHOD(CoordinateTest_InvalidCoordinate_TooLong)
		{
			//Setup
			std::string expected_exception_msg = "A10 is not an valid coordinate!";

			//Execute
			try
			{
				Coordinate actual("A10");
				Assert::Fail();
			}
			catch (InvalidCoordinateException e)
			{
				Assert::AreEqual(expected_exception_msg.c_str(), e.what());
			}
		}

		TEST_METHOD(CoordinateTest_InvalidCoordinate_TooShort)
		{
			//Setup
			std::string expected_exception_msg = "A is not an valid coordinate!";

			//Execute
			try
			{
				Coordinate actual("A");
				Assert::Fail();
			}
			catch (InvalidCoordinateException e)
			{
				Assert::AreEqual(expected_exception_msg.c_str(), e.what());
			}
		}

		TEST_METHOD(CoordinateTest_InvalidCoordinate_InvalidRow)
		{
			//Setup
			std::string expected_exception_msg = "A9 is not an valid coordinate!";

			//Execute
			try
			{
				Coordinate actual("A9");
				Assert::Fail();
			}
			catch (InvalidCoordinateException e)
			{
				Assert::AreEqual(expected_exception_msg.c_str(), e.what());
			}
		}

		TEST_METHOD(CoordinateTest_InvalidCoordinate_InversedRowColume)
		{
			//Setup
			std::string expected_exception_msg = "8A is not an valid coordinate!";

			//Execute
			try
			{
				Coordinate actual("8A");
				Assert::Fail();
			}
			catch (InvalidCoordinateException e)
			{
				Assert::AreEqual(expected_exception_msg.c_str(), e.what());
			}
		}

		TEST_METHOD(CoordinateTest_InvalidCoordinate_InvalidRow_NotANumber)
		{
			//Setup
			std::string expected_exception_msg = "AA is not an valid coordinate!";

			//Execute
			try
			{
				Coordinate actual("AA");
				Assert::Fail();
			}
			catch (InvalidCoordinateException e)
			{
				Assert::AreEqual(expected_exception_msg.c_str(), e.what());
			}
		}

		TEST_METHOD(CoordinateTest_InvalidCoordinate_InvalidColume_ConstructWithIntegers)
		{
			//Setup
			std::string expected_exception_msg = "Invalid coordinate!";

			//Execute
			try
			{
				Coordinate actual(0, 8);
				Assert::Fail();
			}
			catch (InvalidCoordinateException e)
			{
				Assert::AreEqual(expected_exception_msg.c_str(), e.what());
			}
		}

		TEST_METHOD(CoordinateTest_InvalidCoordinate_InvalidRow_ConstructWithIntegers)
		{
			//Setup
			std::string expected_exception_msg = "Invalid coordinate!";

			//Execute
			try
			{
				Coordinate actual(8, 9);
				Assert::Fail();
			}
			catch (InvalidCoordinateException e)
			{
				Assert::AreEqual(expected_exception_msg.c_str(), e.what());
			}
		}

		TEST_METHOD(CoordinateTest_Distance)
		{
			//Setup
			Coordinate source("A1");
			Coordinate destination("B2");
			double expected = std::sqrt(2);

			//Execute
			double actual = Coordinate::Distance(source, destination);

			//Verify
			Assert::AreEqual(expected, actual);

		}

	};
}