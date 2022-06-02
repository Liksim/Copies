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
    return 0;
}

void swapNumbers(int* firstNumber, int* secondNumber)
{
    int buffer = *secondNumber;     // Сохранить в буфер второе число
    *secondNumber = *firstNumber;   // Записать значение первого числа вместо второго
    *firstNumber = buffer;          // Записать значение второго числа из буфера вместо первого
}

int nod(int largerNumber, int smallerNumber)
{
    return 0;
}

void progressHandlerOfCopier(Copier* copier, int* printedCopies, const int oneStepTime)
{
}

void output(const char* file, const long long answer, const ErrorKeeper error)
{
}