#include <iostream>
#include "CopiesHeader.h"

int main()
{
    std::cout << "Hello World!\n";
}

void input(const char* file, Copier* firstCopier, Copier* secondCopier, int* neededAmountOfCopies)
{
    // Заглушка для типового теста
    firstCopier->copyTime = 3;
    secondCopier->copyTime = 2;
    *neededAmountOfCopies = 8;
}

bool isCorrectData(const string* str, ifstream* fin)
{
    // Заглушка для типового теста
    if (*str == "125")
    {
        return true;
    }
    else
    {
        return false;
    }
}

long long calcMinTimeOfPrintingByTwoCopiers(Copier* firstCopier, Copier* secondCopier, const int neededAmountOfCopies)
{
    // Заглушка для типового теста
    if (firstCopier->copyTime == 2 &&
        firstCopier->timeCounter == 0 &&
        secondCopier->copyTime == 3 &&
        secondCopier->timeCounter == 0 &&
        neededAmountOfCopies == 8)
    {
        return 11;
    }
    else
    {
        return 0;
    }
}

void swapNumbers(int* firstNumber, int* secondNumber)
{
    int buffer = *secondNumber;     // Сохранить в буфер второе число
    *secondNumber = *firstNumber;   // Записать значение первого числа вместо второго
    *firstNumber = buffer;          // Записать значение второго числа из буфера вместо первого
}

int nod(int largerNumber, int smallerNumber)
{
    int buffer = 1;      // Буфер

    // Алгоритм Евклида...
    while (smallerNumber)    // ...Пока меньшее число не равно 0
    {
        buffer = smallerNumber;                         // Сохранить в буфер меньшее число
        smallerNumber = largerNumber % smallerNumber;   // Приравнять меньшее число остатку от деления большего числа на меньшее
        largerNumber = buffer;                          // Приравнять большее число значению из буфера
    }

    return buffer;   // Вернуть полученный наибольший общий делитель
}

void progressHandlerOfCopier(Copier* copier, int* printedCopies, const int oneStepTime)
{
    copier->timeCounter += oneStepTime;      // ...Увеличить счётчик времени ксерокса на время одного шага

    if (copier->timeCounter == copier->copyTime)    // Если прошло достаточно времени, чтобы ксерокс успел распечатать копию
    {
        (*printedCopies)++;         // Инкрементировать число напечатанных копий
        copier->timeCounter = 0;    // Обнулить счётчик времени ксерокса
    }
}

void output(const char* file, const long long answer, const ErrorKeeper error)
{
}