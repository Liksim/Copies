#include "CopiesHeader.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");

    Copier firstCopier;         // Первый ксерокс
    Copier secondCopier;        // Второй ксерокс
    int neededAmountOfCopies;   // Нужное количество копий
    long long answer = -1;      // Ответ

    try     // Блок try
    {
        if (!strstr(&argv[1][strlen(argv[1]) - 4], ".txt"))    // Если расширение входного файла не .txt
        {
            ErrorKeeper error = { extensionError };     // Считать, что произошла ошибка в расширении входного файла
            throw error;                                // Выбросить исключение
        }

        input(argv[1], &firstCopier, &secondCopier, &neededAmountOfCopies);    // Ввести данные из входного файла
    }
    catch (ErrorKeeper error)   // Обработка исключений
    {
        output(argv[2], answer, error);     // Вывести ошибку
        return 0;                           // Прервать выполнение программы
    }

    ErrorKeeper error = { noError };    // Считать, что ошибок нет

    // Рассчитать минимальное время печати заданного кол-ва копий с помощью двух ксероксов
    answer = calcMinTimeOfPrintingByTwoCopiers(&firstCopier, &secondCopier, neededAmountOfCopies);

    output(argv[2], answer, error);     // Вывести ответ
}