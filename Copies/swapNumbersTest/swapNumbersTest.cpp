#include "pch.h"
#include "CppUnitTest.h"
#include "../Copies/CopiesHeader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace swapNumbersTest
{
	TEST_CLASS(swapNumbersTest)
	{
	public:
		
		TEST_METHOD(typicalTest)
		{
			int firstNumber = 125, secondNumber = 521;

			swapNumbers(&firstNumber, &secondNumber);

			int expFirstNumber = 521, expSecondNumber = 125;

			Assert::AreEqual(expFirstNumber, firstNumber, L"Значение первого числа неверное.");
			Assert::AreEqual(expSecondNumber, secondNumber, L"Значение вторго числа неверное.");
		}

		TEST_METHOD(equalNumbers)
		{
			int firstNumber = 125, secondNumber = 125;

			swapNumbers(&firstNumber, &secondNumber);

			int expFirstNumber = 125, expSecondNumber = 125;

			Assert::AreEqual(expFirstNumber, firstNumber, L"Значение первого числа неверное.");
			Assert::AreEqual(expSecondNumber, secondNumber, L"Значение вторго числа неверное.");
		}

		TEST_METHOD(maxAndMedian)
		{
			int firstNumber = 2147483647, secondNumber = 125;

			swapNumbers(&firstNumber, &secondNumber);

			int expFirstNumber = 125, expSecondNumber = 2147483647;

			Assert::AreEqual(expFirstNumber, firstNumber, L"Значение первого числа неверное.");
			Assert::AreEqual(expSecondNumber, secondNumber, L"Значение вторго числа неверное.");
		}

		TEST_METHOD(minAndMedian)
		{
			int firstNumber = 125, secondNumber = -2147483647;

			swapNumbers(&firstNumber, &secondNumber);

			int expFirstNumber = -2147483647, expSecondNumber = 125;

			Assert::AreEqual(expFirstNumber, firstNumber, L"Значение первого числа неверное.");
			Assert::AreEqual(expSecondNumber, secondNumber, L"Значение вторго числа неверное.");
		}

		TEST_METHOD(maxAndMin)
		{
			int firstNumber = 2147483647, secondNumber = -2147483647;

			swapNumbers(&firstNumber, &secondNumber);

			int expFirstNumber = -2147483647, expSecondNumber = 2147483647;

			Assert::AreEqual(expFirstNumber, firstNumber, L"Значение первого числа неверное.");
			Assert::AreEqual(expSecondNumber, secondNumber, L"Значение вторго числа неверное.");
		}

		TEST_METHOD(complexTest)
		{
			int firstNumber = 2147483647, secondNumber = 2147483647;

			swapNumbers(&firstNumber, &secondNumber);

			int expFirstNumber = 2147483647, expSecondNumber = 2147483647;

			Assert::AreEqual(expFirstNumber, firstNumber, L"Значение первого числа неверное.");
			Assert::AreEqual(expSecondNumber, secondNumber, L"Значение вторго числа неверное.");
		}
	};
}
