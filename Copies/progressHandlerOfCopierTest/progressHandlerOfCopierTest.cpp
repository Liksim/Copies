#include "pch.h"
#include "CppUnitTest.h"
#include "../Copies/CopiesHeader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace progressHandlerOfCopierTest
{
	TEST_CLASS(progressHandlerOfCopierTest)
	{
	public:
		
		TEST_METHOD(typicalTest)
		{
			Copier copier = { 6, 2 };
			int printedCopies = 0, oneStepTime = 2;

			progressHandlerOfCopier(&copier, &printedCopies, oneStepTime);

			Copier expCopier = { 6, 4 };
			int expPrintedCopies = 0;

			Assert::AreEqual(expCopier.copyTime, copier.copyTime, L"Функция progressHandlerOfCopier изменила время копирования ксерокса.");
			Assert::AreEqual(expCopier.timeCounter, copier.timeCounter, L"Значение счётчика времени неверное.");
			Assert::AreEqual(expPrintedCopies, printedCopies, L"Кол-во напечатанных копий неверное.");
		}

		TEST_METHOD(newCopyWillBePrinted)
		{
			Copier copier = { 6, 4 };
			int printedCopies = 0, oneStepTime = 2;

			progressHandlerOfCopier(&copier, &printedCopies, oneStepTime);

			Copier expCopier = { 6, 0 };
			int expPrintedCopies = 1;

			Assert::AreEqual(expCopier.copyTime, copier.copyTime, L"Функция progressHandlerOfCopier изменила время копирования ксерокса.");
			Assert::AreEqual(expCopier.timeCounter, copier.timeCounter, L"Значение счётчика времени неверное.");
			Assert::AreEqual(expPrintedCopies, printedCopies, L"Кол-во напечатанных копий неверное.");
		}

		TEST_METHOD(timeCounterIsZero)
		{
			Copier copier = { 6, 0 };
			int printedCopies = 0, oneStepTime = 2;

			progressHandlerOfCopier(&copier, &printedCopies, oneStepTime);

			Copier expCopier = { 6, 2 };
			int expPrintedCopies = 0;

			Assert::AreEqual(expCopier.copyTime, copier.copyTime, L"Функция progressHandlerOfCopier изменила время копирования ксерокса.");
			Assert::AreEqual(expCopier.timeCounter, copier.timeCounter, L"Значение счётчика времени неверное.");
			Assert::AreEqual(expPrintedCopies, printedCopies, L"Кол-во напечатанных копий неверное.");
		}

		TEST_METHOD(oneStepTimeIsEqualCopyTime)
		{
			Copier copier = { 6, 0 };
			int printedCopies = 0, oneStepTime = 6;

			progressHandlerOfCopier(&copier, &printedCopies, oneStepTime);

			Copier expCopier = { 6, 0 };
			int expPrintedCopies = 1;

			Assert::AreEqual(expCopier.copyTime, copier.copyTime, L"Функция progressHandlerOfCopier изменила время копирования ксерокса.");
			Assert::AreEqual(expCopier.timeCounter, copier.timeCounter, L"Значение счётчика времени неверное.");
			Assert::AreEqual(expPrintedCopies, printedCopies, L"Кол-во напечатанных копий неверное.");
		}

		TEST_METHOD(complexTest)
		{
			Copier copier = { 2147483647, 0 };
			int printedCopies = 125, oneStepTime = 2147483647;

			progressHandlerOfCopier(&copier, &printedCopies, oneStepTime);

			Copier expCopier = { 2147483647, 0 };
			int expPrintedCopies = 126;

			Assert::AreEqual(expCopier.copyTime, copier.copyTime, L"Функция progressHandlerOfCopier изменила время копирования ксерокса.");
			Assert::AreEqual(expCopier.timeCounter, copier.timeCounter, L"Значение счётчика времени неверное.");
			Assert::AreEqual(expPrintedCopies, printedCopies, L"Кол-во напечатанных копий неверное.");
		}
	};
}
