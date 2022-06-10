#include "pch.h"
#include "CppUnitTest.h"
#include "../Copies/CopiesHeader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isCorrectDataTest
{
	TEST_CLASS(isCorrectDataTest)
	{
	public:
		
		TEST_METHOD(typicalTest)
		{
			string str = "125";
			ifstream fin;

			fin.open("..\\..\\Copies\\testFile.txt");
			bool actual = false;

			try
			{
				actual = isCorrectData(&str, &fin);
			}
			catch (ErrorKeeper error)
			{
				if (fin.is_open())
				{
					fin.close();
				}

				Assert::Fail(L"Функция isCorrectData выбросила ошибку.");
			}

			if (fin.is_open())
			{
				fin.close();
			}
			else
			{
				Assert::Fail(L"Функция isCorrectData закрыла файл.");
			}

			Assert::IsTrue(actual, L"Функция isCorrectData вернула false.");
		}

		TEST_METHOD(fractionalNumber)
		{
			string str = "1,25";
			ifstream fin;

			fin.open("..\\..\\Copies\\testFile.txt");
			bool actual = false;

			int expErrorCode = 3;
			string expIncorrectData = ",";

			bool isErrorThrown = false;

			try
			{
				actual = isCorrectData(&str, &fin);
			}
			catch (ErrorKeeper error)
			{
				isErrorThrown = true;

				if (fin.is_open())
				{
					fin.close();
					Assert::Fail(L"Функция isCorrectData не закрыла файл.");
				}

				Assert::AreEqual(expErrorCode, error.errorCode, L"Неверный код ошибки.");
				Assert::AreEqual(expIncorrectData, error.incorrectData, L"Неверный недопустимый символ.");
			}

			if (fin.is_open())
			{
				fin.close();
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция isCorrectData не выбросила ошибку.");
			}
		}

		TEST_METHOD(zerosAtBeginning)
		{
			string str = "00125";
			ifstream fin;

			fin.open("..\\..\\Copies\\testFile.txt");
			bool actual = false;

			try
			{
				actual = isCorrectData(&str, &fin);
			}
			catch (ErrorKeeper error)
			{
				if (fin.is_open())
				{
					fin.close();
				}

				Assert::Fail(L"Функция isCorrectData выбросила ошибку.");
			}

			if (fin.is_open())
			{
				fin.close();
			}
			else
			{
				Assert::Fail(L"Функция isCorrectData закрыла файл.");
			}

			Assert::IsTrue(actual, L"Функция isCorrectData вернула false.");
		}

		TEST_METHOD(lessRange)
		{
			string str = "0";
			ifstream fin;

			fin.open("..\\..\\Copies\\testFile.txt");
			bool actual = false;

			int expErrorCode = 4;
			string expIncorrectData = "0";
			
			bool isErrorThrown = false;

			try
			{
				actual = isCorrectData(&str, &fin);
			}
			catch (ErrorKeeper error)
			{
				isErrorThrown = true;

				if (fin.is_open())
				{
					fin.close();
					Assert::Fail(L"Функция isCorrectData не закрыла файл.");
				}

				Assert::AreEqual(expErrorCode, error.errorCode, L"Неверный код ошибки.");
				Assert::AreEqual(expIncorrectData, error.incorrectData, L"Неверный недопустимый символ.");
			}

			if (fin.is_open())
			{
				fin.close();
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция isCorrectData не выбросила ошибку.");
			}
		}

		TEST_METHOD(moreRange)
		{
			string str = "2147483648";
			ifstream fin;

			fin.open("..\\..\\Copies\\testFile.txt");
			bool actual = false;

			int expErrorCode = 4;
			string expIncorrectData = "2147483648";

			bool isErrorThrown = false;

			try
			{
				actual = isCorrectData(&str, &fin);
			}
			catch (ErrorKeeper error)
			{
				isErrorThrown = true;

				if (fin.is_open())
				{
					fin.close();
					Assert::Fail(L"Функция isCorrectData не закрыла файл.");
				}

				Assert::AreEqual(expErrorCode, error.errorCode, L"Неверный код ошибки.");
				Assert::AreEqual(expIncorrectData, error.incorrectData, L"Неверный недопустимый символ.");
			}

			if (fin.is_open())
			{
				fin.close();
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция isCorrectData не выбросила ошибку.");
			}
		}

		TEST_METHOD(oneInvalidCharacter)
		{
			string str = "1*5";
			ifstream fin;

			fin.open("..\\..\\Copies\\testFile.txt");
			bool actual = false;

			int expErrorCode = 3;
			string expIncorrectData = "*";

			bool isErrorThrown = false;

			try
			{
				actual = isCorrectData(&str, &fin);
			}
			catch (ErrorKeeper error)
			{
				isErrorThrown = true;

				if (fin.is_open())
				{
					fin.close();
					Assert::Fail(L"Функция isCorrectData не закрыла файл.");
				}

				Assert::AreEqual(expErrorCode, error.errorCode, L"Неверный код ошибки.");
				Assert::AreEqual(expIncorrectData, error.incorrectData, L"Неверный недопустимый символ.");
			}

			if (fin.is_open())
			{
				fin.close();
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция isCorrectData не выбросила ошибку.");
			}
		}

		TEST_METHOD(severalInvalidCharacters)
		{
			string str = "1* +5";
			ifstream fin;

			fin.open("..\\..\\Copies\\testFile.txt");
			bool actual = false;

			int expErrorCode = 3;
			string expIncorrectData = "*";

			bool isErrorThrown = false;

			try
			{
				actual = isCorrectData(&str, &fin);
			}
			catch (ErrorKeeper error)
			{
				isErrorThrown = true;

				if (fin.is_open())
				{
					fin.close();
					Assert::Fail(L"Функция isCorrectData не закрыла файл.");
				}

				Assert::AreEqual(expErrorCode, error.errorCode, L"Неверный код ошибки.");
				Assert::AreEqual(expIncorrectData, error.incorrectData, L"Неверный недопустимый символ.");
			}

			if (fin.is_open())
			{
				fin.close();
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция isCorrectData не выбросила ошибку.");
			}
		}

		TEST_METHOD(entireStringOfInvalidCharacters)
		{
			string str = "* +";
			ifstream fin;

			fin.open("..\\..\\Copies\\testFile.txt");
			bool actual = false;

			int expErrorCode = 3;
			string expIncorrectData = "*";

			bool isErrorThrown = false;

			try
			{
				actual = isCorrectData(&str, &fin);
			}
			catch (ErrorKeeper error)
			{
				isErrorThrown = true;

				if (fin.is_open())
				{
					fin.close();
					Assert::Fail(L"Функция isCorrectData не закрыла файл.");
				}

				Assert::AreEqual(expErrorCode, error.errorCode, L"Неверный код ошибки.");
				Assert::AreEqual(expIncorrectData, error.incorrectData, L"Неверный недопустимый символ.");
			}

			if (fin.is_open())
			{
				fin.close();
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция isCorrectData не выбросила ошибку.");
			}
		}

		TEST_METHOD(emptyString)
		{
			string str = "";
			ifstream fin;

			fin.open("..\\..\\Copies\\testFile.txt");
			bool actual = false;

			int expErrorCode = 3;
			string expIncorrectData = "";

			bool isErrorThrown = false;

			try
			{
				actual = isCorrectData(&str, &fin);
			}
			catch (ErrorKeeper error)
			{
				isErrorThrown = true;

				if (fin.is_open())
				{
					fin.close();
					Assert::Fail(L"Функция isCorrectData не закрыла файл.");
				}

				Assert::AreEqual(expErrorCode, error.errorCode, L"Неверный код ошибки.");
				Assert::AreEqual(expIncorrectData, error.incorrectData, L"Неверный недопустимый символ.");
			}

			if (fin.is_open())
			{
				fin.close();
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция isCorrectData не выбросила ошибку.");
			}
		}

		TEST_METHOD(invalidCharacterAtBeginningOfString)
		{
			string str = "*25";
			ifstream fin;

			fin.open("..\\..\\Copies\\testFile.txt");
			bool actual = false;

			int expErrorCode = 3;
			string expIncorrectData = "*";

			bool isErrorThrown = false;

			try
			{
				actual = isCorrectData(&str, &fin);
			}
			catch (ErrorKeeper error)
			{
				isErrorThrown = true;

				if (fin.is_open())
				{
					fin.close();
					Assert::Fail(L"Функция isCorrectData не закрыла файл.");
				}

				Assert::AreEqual(expErrorCode, error.errorCode, L"Неверный код ошибки.");
				Assert::AreEqual(expIncorrectData, error.incorrectData, L"Неверный недопустимый символ.");
			}

			if (fin.is_open())
			{
				fin.close();
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция isCorrectData не выбросила ошибку.");
			}
		}

		TEST_METHOD(invalidCharacterAtEndOfString)
		{
			string str = "12*";
			ifstream fin;

			fin.open("..\\..\\Copies\\testFile.txt");
			bool actual = false;

			int expErrorCode = 3;
			string expIncorrectData = "*";

			bool isErrorThrown = false;

			try
			{
				actual = isCorrectData(&str, &fin);
			}
			catch (ErrorKeeper error)
			{
				isErrorThrown = true;

				if (fin.is_open())
				{
					fin.close();
					Assert::Fail(L"Функция isCorrectData не закрыла файл.");
				}

				Assert::AreEqual(expErrorCode, error.errorCode, L"Неверный код ошибки.");
				Assert::AreEqual(expIncorrectData, error.incorrectData, L"Неверный недопустимый символ.");
			}

			if (fin.is_open())
			{
				fin.close();
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция isCorrectData не выбросила ошибку.");
			}
		}

		TEST_METHOD(invalidCharacterInMultiplePlaces)
		{
			string str = "*1 5+";
			ifstream fin;

			fin.open("..\\..\\Copies\\testFile.txt");
			bool actual = false;

			int expErrorCode = 3;
			string expIncorrectData = "*";

			bool isErrorThrown = false;

			try
			{
				actual = isCorrectData(&str, &fin);
			}
			catch (ErrorKeeper error)
			{
				isErrorThrown = true;

				if (fin.is_open())
				{
					fin.close();
					Assert::Fail(L"Функция isCorrectData не закрыла файл.");
				}

				Assert::AreEqual(expErrorCode, error.errorCode, L"Неверный код ошибки.");
				Assert::AreEqual(expIncorrectData, error.incorrectData, L"Неверный недопустимый символ.");
			}

			if (fin.is_open())
			{
				fin.close();
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция isCorrectData не выбросила ошибку.");
			}
		}

		TEST_METHOD(complexTest)
		{
			string str = "0*01,2 5+%";
			ifstream fin;

			fin.open("..\\..\\Copies\\testFile.txt");
			bool actual = false;

			int expErrorCode = 3;
			string expIncorrectData = "*";

			bool isErrorThrown = false;

			try
			{
				actual = isCorrectData(&str, &fin);
			}
			catch (ErrorKeeper error)
			{
				isErrorThrown = true;

				if (fin.is_open())
				{
					fin.close();
					Assert::Fail(L"Функция isCorrectData не закрыла файл.");
				}

				Assert::AreEqual(expErrorCode, error.errorCode, L"Неверный код ошибки.");
				Assert::AreEqual(expIncorrectData, error.incorrectData, L"Неверный недопустимый символ.");
			}

			if (fin.is_open())
			{
				fin.close();
			}

			if (!isErrorThrown)
			{
				Assert::Fail(L"Функция isCorrectData не выбросила ошибку.");
			}
		}
	};
}
