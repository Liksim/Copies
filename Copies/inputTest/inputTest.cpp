#include "pch.h"
#include "CppUnitTest.h"
#include "../Copies/CopiesHeader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace inputTest
{
	TEST_CLASS(inputTest)
	{
	public:
		
		TEST_METHOD(typicalTest)
		{
			ofstream fout;

			fout.open("..\\..\\Copies\\testFile.txt");

			if (fout.is_open())
			{
				fout << "3" << endl;
				fout << "2" << endl;
				fout << "8";
				fout.close();
			}
			else
			{
				Assert::Fail(L"Не получилость создать текстовый файл для тестирования.");
			}

			char* file = "..\\..\\Copies\\testFile.txt";
			Copier firstCopier, secondCopier;
			firstCopier.timeCounter = 1;
			secondCopier.timeCounter = 1;
			int neededAmountOfCopies;

			try
			{
				input(file, &firstCopier, &secondCopier, &neededAmountOfCopies);
			}
			catch (ErrorKeeper error)
			{
				Assert::Fail(L"Функция input выбросила ошибку.");
			}

			Copier expFirstCopier = { 3, 1 };
			Copier expSecondCopier = { 2, 1 };
			int expNeededAmountOfCopies = 8;

			Assert::AreEqual(expFirstCopier.copyTime, firstCopier.copyTime, L"Неверное время копирования у первого ксерокса.");
			Assert::AreEqual(expFirstCopier.timeCounter, firstCopier.timeCounter, L"Значение счётчика времени у первого ксерокса изменилось.");

			Assert::AreEqual(expSecondCopier.copyTime, secondCopier.copyTime, L"Неверное время копирования у второго ксерокса.");
			Assert::AreEqual(expSecondCopier.timeCounter, secondCopier.timeCounter, L"Значение счётчика времени у второго ксерокса изменилось.");

			Assert::AreEqual(expNeededAmountOfCopies, neededAmountOfCopies, L"Неверное необходимое кол-во копий.");
		}

		TEST_METHOD(fileNotFound)
		{
			ofstream fout;

			fout.open("..\\..\\Copies\\testFile.txt");

			if (fout.is_open())
			{
				fout.close();
			}
			else
			{
				Assert::Fail(L"Не получилость создать текстовый файл для тестирования.");
			}

			char* file = "..\\..\\Copies\\test.txt";
			Copier firstCopier, secondCopier;
			int neededAmountOfCopies;

			bool isErrorThrown = false;

			try
			{
				input(file, &firstCopier, &secondCopier, &neededAmountOfCopies);
			}
			catch (ErrorKeeper error)
			{
				ErrorKeeper expError = { inputError };

				Assert::AreEqual(expError.errorCode, error.errorCode, L"Неверный код ошибки.");

				isErrorThrown = true;
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция input не выбросила ошибку.");
			}
		}

		TEST_METHOD(tooMuchData)
		{
			ofstream fout;

			fout.open("..\\..\\Copies\\testFile.txt");

			if (fout.is_open())
			{
				fout << "3" << endl;
				fout << "2" << endl;
				fout << "8" << endl;
				fout << "12";
				fout.close();
			}
			else
			{
				Assert::Fail(L"Не получилость создать текстовый файл для тестирования.");
			}

			char* file = "..\\..\\Copies\\testFile.txt";
			Copier firstCopier, secondCopier;
			int neededAmountOfCopies;

			bool isErrorThrown = false;

			try
			{
				input(file, &firstCopier, &secondCopier, &neededAmountOfCopies);
			}
			catch (ErrorKeeper error)
			{
				ErrorKeeper expError = { tooMuchDataError };

				Assert::AreEqual(expError.errorCode, error.errorCode, L"Неверный код ошибки.");

				isErrorThrown = true;
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция input не выбросила ошибку.");
			}
		}

		TEST_METHOD(notEnoughData)
		{
			ofstream fout;

			fout.open("..\\..\\Copies\\testFile.txt");

			if (fout.is_open())
			{
				fout << "3" << endl;
				fout << "2";
				fout.close();
			}
			else
			{
				Assert::Fail(L"Не получилость создать текстовый файл для тестирования.");
			}

			char* file = "..\\..\\Copies\\testFile.txt";
			Copier firstCopier, secondCopier;
			int neededAmountOfCopies;

			bool isErrorThrown = false;

			try
			{
				input(file, &firstCopier, &secondCopier, &neededAmountOfCopies);
			}
			catch (ErrorKeeper error)
			{
				ErrorKeeper expError = { notEnoughDataError };

				Assert::AreEqual(expError.errorCode, error.errorCode, L"Неверный код ошибки.");

				isErrorThrown = true;
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция input не выбросила ошибку.");
			}
		}
	};
}
