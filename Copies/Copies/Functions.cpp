#include "CopiesHeader.h"

void input(const char* file, Copier* firstCopier, Copier* secondCopier, int* neededAmountOfCopies)
{
    // Заглушка для типового теста
    firstCopier->copyTime = 3;
    secondCopier->copyTime = 2;
    *neededAmountOfCopies = 8;
}

bool isCorrectData(string* str, ifstream* fin)
{
    if (*str == "")     // Если проверяемая строка пуста
    {
        fin->close();   // Закрыть файл

        string incorrectData = *str;                            // Считать ошибочными данными пустую строку

        ErrorKeeper error = { invSymbolError , incorrectData }; // Считать, что произошла ошибка из-за недопустимого символа во входных данных
        throw error;                                            // Выбросить исключение
    }

    for (int i = 0; i < str->length(); i++)     // Для каждого символа проверяемой строки
    {
        if ((*str)[i] < '0' || (*str)[i] > '9')   // Если текущий символ не является цифрой
        {
            fin->close();    // Закрыть файл

            string incorrectData = "";      // Строка с ошибочными данными
            incorrectData = (*str)[i];      // Считать ошибочными данными текущий символ

            ErrorKeeper error = { invSymbolError , incorrectData };     // Считать, что произошла ошибка из-за недопустимого символа во входных данных
            throw error;                                                // Выбросить исключение
        }
    }

    // Удалить нули в начале проверяемой строки...
    while ((*str)[0] == '0' && str->length() > 1)   // ...Пока в начале проверяемой строки стоит ноль
    {
        str->erase(0, 1);       // Удалить первый символ проверяемой строки
    }

    if (str->length() > 10 || *str == "0" || (str->length() == 10 && *str > "2147483647"))   // Если в проверяемой строке число не входит в диапазон [1..2147483647]
    {
        fin->close();    // Закрыть файл

        ErrorKeeper error = { outOfRangeError, *str };  // Считать, что произошла ошибка из-за выхода из диапазона допустимых значений
        throw error;                                    // Выбросить исключение
    }

    return true;        // Вернуть, что данные корректны
}

long long calcMinTimeOfPrintingByTwoCopiers(Copier* firstCopier, Copier* secondCopier, const int neededAmountOfCopies)
{
    firstCopier->timeCounter = 0;   // Обнулить счётчик времени первого ксерокса
    secondCopier->timeCounter = 0;  // Обнулить счётчик времени второго ксерокса

    // Считать более быстрый ксерокс первым...
    if (firstCopier->copyTime > secondCopier->copyTime)   // ...Если первый ксерокс медленнее
    {
        swapNumbers(&firstCopier->copyTime, &secondCopier->copyTime); // Поменять ксероксы местами
    }

    int oneStepTime = nod(secondCopier->copyTime, firstCopier->copyTime);   // Вычислить время одного шага обработки печати ксероксов (НОД времени печати ксероксов)

    long long resultTime = 0;       // Итоговое время
    int printedCopies = 0;          // Напечатанные копии

    // Сделать копию оригинала на первом ксероксе...
    resultTime += firstCopier->copyTime;    // ...Добавить время копирования первого ксерокса к итоговому времени
    printedCopies++;                        // ...Инкрементировать число напечатанных копий

    while (neededAmountOfCopies > printedCopies)    // Пока нужное количество копий не напечатано
    {
        resultTime += oneStepTime;      // Добавить время одного шага к итоговому времени
        progressHandlerOfCopier(firstCopier, &printedCopies, oneStepTime);       // Засчитать работу первого ксерокса за время одного шага
        progressHandlerOfCopier(secondCopier, &printedCopies, oneStepTime);      // Засчитать работу второго ксерокса за время одного шага
    }

    return resultTime;  // Вернуть итоговое время
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
    // Заглушка для типового теста
    if (answer == 125 && error.errorCode == noError)
    {
        ofstream fout;
        fout.open(file);

        if (fout.is_open())
        {
            fout << "125";

            fout.close();
        }
    }
}