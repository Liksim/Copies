#include "pch.h"
#include "CppUnitTest.h"
#include "../Copies/CopiesHeader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace calcMinTimeOfPrintingByTwoCopiersTest
{
	TEST_CLASS(calcMinTimeOfPrintingByTwoCopiersTest)
	{
	public:
		
		TEST_METHOD(typicalTest)
		{
			Copier firstCopier = { 2, 0 }, secondCopier = { 3, 0 };
			int neededAmountCopies = 8;
			long long answer;

			answer = calcMinTimeOfPrintingByTwoCopiers(&firstCopier, &secondCopier, neededAmountCopies);

			long long expAnswer = 11;

			Assert::AreEqual(expAnswer, answer, L"Ответ неверный.");
		}

		TEST_METHOD(timeCountersIsNotEqualToZero)
		{
			Copier firstCopier = { 2, 1 }, secondCopier = { 3, 2 };
			int neededAmountCopies = 8;
			long long answer;

			answer = calcMinTimeOfPrintingByTwoCopiers(&firstCopier, &secondCopier, neededAmountCopies);

			long long expAnswer = 11;

			Assert::AreEqual(expAnswer, answer, L"Ответ неверный.");
		}

		TEST_METHOD(secondCopierIsFaster)
		{
			Copier firstCopier = { 3, 0 }, secondCopier = { 2, 0 };
			int neededAmountCopies = 8;
			long long answer;

			answer = calcMinTimeOfPrintingByTwoCopiers(&firstCopier, &secondCopier, neededAmountCopies);

			long long expAnswer = 11;

			Assert::AreEqual(expAnswer, answer, L"Ответ неверный.");
		}

		TEST_METHOD(copiersAreEqual)
		{
			Copier firstCopier = { 2, 0 }, secondCopier = { 2, 0 };
			int neededAmountCopies = 8;
			long long answer;

			answer = calcMinTimeOfPrintingByTwoCopiers(&firstCopier, &secondCopier, neededAmountCopies);

			long long expAnswer = 10;

			Assert::AreEqual(expAnswer, answer, L"Ответ неверный.");
		}

		TEST_METHOD(inputDataIsMinimal)
		{
			Copier firstCopier = { 1, 0 }, secondCopier = { 1, 0 };
			int neededAmountCopies = 8;
			long long answer;

			answer = calcMinTimeOfPrintingByTwoCopiers(&firstCopier, &secondCopier, neededAmountCopies);

			long long expAnswer = 5;

			Assert::AreEqual(expAnswer, answer, L"Ответ неверный.");
		}

		TEST_METHOD(inputDataIsMaximal)
		{
			Copier firstCopier = { 2147483647, 0 }, secondCopier = { 2147483647, 0 };
			int neededAmountCopies = 2147483647;
			long long answer;

			answer = calcMinTimeOfPrintingByTwoCopiers(&firstCopier, &secondCopier, neededAmountCopies);

			long long expAnswer = 2305843008139952128;

			Assert::AreEqual(expAnswer, answer, L"Ответ неверный.");
		}

		TEST_METHOD(complexTest)
		{
			Copier firstCopier = { 2147483647, 36512 }, secondCopier = { 1, 0 };
			int neededAmountCopies = 2147483647;
			long long answer;

			answer = calcMinTimeOfPrintingByTwoCopiers(&firstCopier, &secondCopier, neededAmountCopies);

			long long expAnswer = 2147483647;

			Assert::AreEqual(expAnswer, answer, L"Ответ неверный.");
		}
	};
}
