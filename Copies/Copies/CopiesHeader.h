/*!\mainpage Copies
* Программа даёт ответ на задачу «Ксерокопии» при разных значениях N, x и y.\n
* Текст задачи «Ксерокопии»:\n
* «Секретарю нужно срочно успеть сделать N копий одного документа.\n
* В его распоряжении имеются два ксерокса, один из которых копирует лист за х секунд, а другой – за y секунд.\n
* (Разрешается использовать как один ксерокс, так и оба одновременно. Можно копировать не только с оригинала, но и с копии.)\n
* Нужно выяснить, какое минимальное время для этого потребуется.»
*/

#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//! Коды ошибок
const enum ErrorCodes { noError, extensionError, inputError, invSymbolError, outOfRangeError, notEnoughDataError, tooMuchDataError };	

//! Носитель ошибок
struct ErrorKeeper
{
	//! Код ошибки
	int errorCode;

	//! Ошибочные данные
	string incorrectData;	
};

//! Ксерокс
struct Copier
{
	//! Время копирования (сек.)
	int copyTime;	

	//! Счётчик времени работы ксерокса (сек.)
	int timeCounter = 0;	
};

/*! Ввести данные из файла
*	\param[in] file файл с вводимыми данными
*	\param[out] firstCopier первый ксерокс
*	\param[out] secondCopier второй ксерокс
*	\param[out] neededAmountOfCopies необходимое количество копий
*	\exception error ошибка ввода/из-за переизбытка входных данных/из-за нехватки входных данных
*/
void input(const char* file, Copier* firstCopier, Copier* secondCopier, int* neededAmountOfCopies);

/*! Проверить корректны ли данные (числа от 1 до 2147483647)
*	\param[in,out] str проверяемая строка
*	\param[in] fin поток ввода
*	\return корректны ли данные
*	\exception error ошибка из-за недопустимого символа/из-за выхода из диапазона допустимых значений
*/
bool isCorrectData(string* str, ifstream* fin);

/*! Рассчитать минимальное время печати заданного кол-ва копий с помощью двух ксероксов
*	\param[in] firstCopier первый ксерокс
*	\param[in] secondCopier второй ксерокс
*	\param[in] neededAmountOfCopies заданное кол-во копий
*	\return итоговое время
*/
long long calcMinTimeOfPrintingByTwoCopiers(Copier* firstCopier, Copier* secondCopier, const int neededAmountOfCopies);

/*! Поменять числа местами
*	\param[in,out] firstNumber первое число
*	\param[in,out] secondNumber второе число
*/
void swapNumbers(int* firstNumber, int* secondNumber);

/*! Получить НОД двух чисел (алгоритм Евклида)
*	\param[in] largerNumber большее число
*	\param[in] smallerNumber меньшее число
*	\return наибольший общий делитель
*/
int nod(int largerNumber, int smallerNumber);

/*! Засчитать работу ксерокса за время одного шага
*	\param[in,out] copier ксерокс
*	\param[in,out] printedCopies напечатанные копии
*	\param[in] oneStepTime время одного шага обработки печати ксероксов
*/
void progressHandlerOfCopier(Copier* copier, int* printedCopies, const int oneStepTime);

/*! Вывести ответ или ошибку
*	\param[in] file файл для вывода данных
*	\param[in] answer ответ
*	\param[in] error ошибка
*/
void output(const char* file, const long long answer, const ErrorKeeper error);
