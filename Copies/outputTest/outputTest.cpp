#include "pch.h"
#include "CppUnitTest.h"
#include "../Copies/CopiesHeader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace outputTest
{
	TEST_CLASS(outputTest)
	{
	public:
		
		TEST_METHOD(typicalTest)
		{
			char* file = "..\\..\\Copies\\testFile.txt";
			long long answer = 125;
			ErrorKeeper error = { noError };

			output(file, answer, error);

			string actualOutput;
			ifstream fin;
			fin.open(file);

			if (fin.is_open())
			{
				getline(fin, actualOutput);
			}
			else
			{
				Assert::Fail(L"Не удалось открыть проверяемый файл.");
			}

			fin.close();
			
			string expOutput = "125";

			Assert::AreEqual(expOutput, actualOutput, L"Неверный вывод.");
		}

		TEST_METHOD(maxAnswer)
		{
			char* file = "..\\..\\Copies\\testFile.txt";
			long long answer = 9223372036854775807;
			ErrorKeeper error = { noError };

			output(file, answer, error);

			string actualOutput;
			ifstream fin;
			fin.open(file);

			if (fin.is_open())
			{
				getline(fin, actualOutput);
			}
			else
			{
				Assert::Fail(L"Не удалось открыть проверяемый файл.");
			}

			fin.close();

			string expOutput = "9223372036854775807";

			Assert::AreEqual(expOutput, actualOutput, L"Неверный вывод.");
		}

		TEST_METHOD(minAnswer)
		{
			char* file = "..\\..\\Copies\\testFile.txt";
			long long answer = 1;
			ErrorKeeper error = { noError };

			output(file, answer, error);

			string actualOutput;
			ifstream fin;
			fin.open(file);

			if (fin.is_open())
			{
				getline(fin, actualOutput);
			}
			else
			{
				Assert::Fail(L"Не удалось открыть проверяемый файл.");
			}

			fin.close();

			string expOutput = "1";

			Assert::AreEqual(expOutput, actualOutput, L"Неверный вывод.");
		}

		TEST_METHOD(outputExtensionError)
		{
			char* file = "..\\..\\Copies\\testFile.txt";
			long long answer = -1;
			ErrorKeeper error = { extensionError };

			output(file, answer, error);

			string actualOutput;
			ifstream fin;
			fin.open(file);

			if (fin.is_open())
			{
				getline(fin, actualOutput);
			}
			else
			{
				Assert::Fail(L"Не удалось открыть проверяемый файл.");
			}

			fin.close();

			string expOutput = "Неверно указано расширение файла. Файл должен иметь расширение .txt";

			Assert::AreEqual(expOutput, actualOutput, L"Неверный вывод.");
		}

		TEST_METHOD(outputInputError)
		{
			char* file = "..\\..\\Copies\\testFile.txt";
			long long answer = -1;
			ErrorKeeper error = { inputError };

			output(file, answer, error);

			string actualOutput;
			ifstream fin;
			fin.open(file);

			if (fin.is_open())
			{
				getline(fin, actualOutput);
			}
			else
			{
				Assert::Fail(L"Не удалось открыть проверяемый файл.");
			}

			fin.close();

			string expOutput = "Неверно указан файл с входными данными. Возможно, файл не существует.";

			Assert::AreEqual(expOutput, actualOutput, L"Неверный вывод.");
		}

		TEST_METHOD(outputInvSymbolError)
		{
			char* file = "..\\..\\Copies\\testFile.txt";
			long long answer = -1;
			ErrorKeeper error = { invSymbolError, "*"};

			output(file, answer, error);

			string actualOutput;
			ifstream fin;
			fin.open(file);

			if (fin.is_open())
			{
				getline(fin, actualOutput);
			}
			else
			{
				Assert::Fail(L"Не удалось открыть проверяемый файл.");
			}

			fin.close();

			string expOutput = "Входное значение «*» является недопустимым символом.";

			Assert::AreEqual(expOutput, actualOutput, L"Неверный вывод.");
		}

		TEST_METHOD(outputOutOfRangeError)
		{
			char* file = "..\\..\\Copies\\testFile.txt";
			long long answer = -1;
			ErrorKeeper error = { outOfRangeError, "0"};

			output(file, answer, error);

			string actualOutput;
			ifstream fin;
			fin.open(file);

			if (fin.is_open())
			{
				getline(fin, actualOutput);
			}
			else
			{
				Assert::Fail(L"Не удалось открыть проверяемый файл.");
			}

			fin.close();

			string expOutput = "Входное значение 0 не принадлежит диапазону [1..2147483647].";

			Assert::AreEqual(expOutput, actualOutput, L"Неверный вывод.");
		}

		TEST_METHOD(outputNotEnoughDataError)
		{
			char* file = "..\\..\\Copies\\testFile.txt";
			long long answer = -1;
			ErrorKeeper error = { notEnoughDataError };

			output(file, answer, error);

			string actualOutput;
			ifstream fin;
			fin.open(file);

			if (fin.is_open())
			{
				getline(fin, actualOutput);
			}
			else
			{
				Assert::Fail(L"Не удалось открыть проверяемый файл.");
			}

			fin.close();

			string expOutput = "Не хватает входных значений для решения задачи.";

			Assert::AreEqual(expOutput, actualOutput, L"Неверный вывод.");
		}

		TEST_METHOD(outputTooMuchDataError)
		{
			char* file = "..\\..\\Copies\\testFile.txt";
			long long answer = -1;
			ErrorKeeper error = { tooMuchDataError };

			output(file, answer, error);

			string actualOutput;
			ifstream fin;
			fin.open(file);

			if (fin.is_open())
			{
				getline(fin, actualOutput);
			}
			else
			{
				Assert::Fail(L"Входных данных слишком много. Нужно ввести только три значения.");
			}

			fin.close();

			string expOutput = "Входных данных слишком много. Нужно ввести только три значения.";

			Assert::AreEqual(expOutput, actualOutput, L"Неверный вывод.");
		}
	};
}
