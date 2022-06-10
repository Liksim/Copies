#include "CopiesHeader.h"

void input(const char* file, Copier* firstCopier, Copier* secondCopier, int* neededAmountOfCopies)
{
    int* inputDestination[3] = { &firstCopier->copyTime, &secondCopier->copyTime, neededAmountOfCopies };     // Массив назначений для входных данных
    ifstream fin;       // Поток ввода
    string str;         // Строка-буффер

    fin.open(file);     // Открыть файл

    if (fin.is_open())  // Если файл открыт
    {
        int i;          // Счётчик вводимых данных

        for (i = 0; i < 3 && !fin.eof(); i++) // Для каждого назначения для входных данных и пока файл не закончился
        {
            getline(fin, str);  // Занести в строку-буффер входные данные

            if (isCorrectData(&str, &fin))  // Если входные данные корректны
            {
                *(inputDestination[i]) = stoi(str);    // Занести входные данные в текущее назначение для входных данных
            }
        }

        if (!fin.eof())     // Если файл не закончился
        {
            fin.close();                                // Закрыть файл
            ErrorKeeper error = { tooMuchDataError };   // Считать, что произошла ошибка из-за переизбытка входных данных
            throw error;                                // Выбросить исключение
        }

        fin.close();    // Закрыть файл

        if (i < 3)  // Если данных слишком мало
        {
            ErrorKeeper error = { notEnoughDataError };     // Считать, что произошла ошибка из-за нехватки входных данных
            throw error;                                    // Выбросить исключение
        }
    }
    else    // Иначе
    {
        ErrorKeeper error = { inputError };     // Считать, что произошла ошибка ввода
        throw error;                            // Выбросить исключение
    }
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
    ofstream fout;      // Поток вывода

    fout.open(file);    // Открыть файл

    if (fout.is_open()) // Если файл открыт
    {
        if (error.errorCode == noError)   // Если ошибок не было
        {
            // Вывести ответ в выходной файл
            fout << answer;
        }
        else if (error.errorCode == extensionError)   // Иначе если произошла ошибка в расширении входного файла
        {
            // Вывести в выходной файл сообщение об ошибке в расширении файла
            fout << "Неверно указано расширение файла. Файл должен иметь расширение .txt";
        }
        else if (error.errorCode == inputError)       // Иначе если произошла ошибка ввода
        {
            // Вывести в выходной файл сообщение об ошибке ввода
            fout << "Неверно указан файл с входными данными. Возможно, файл не существует.";
        }
        else if (error.errorCode == invSymbolError)   // Иначе если произошла ошибка из-за недопустимого символа во входных данных
        {
            // Вывести в выходной файл сообщение об ошибке из-за недопустимого символа во входных данных
            fout << "Входное значение «" + error.incorrectData + "» является недопустимым символом.";
        }
        else if (error.errorCode == outOfRangeError) // Иначе если произошла ошибка из-за выхода из диапазона допустимых значений
        {
            // Вывести в выходной файл сообщение об ошибке из-за выхода из диапазона допустимых значений
            fout << "Входное значение " + error.incorrectData + " не принадлежит диапазону [1..2147483647].";
        }
        else if (error.errorCode == notEnoughDataError) // Иначе если произошла ошибка из-за нехватки входных данных
        {
            // Вывести в выходной файл сообщение об ошибке из-за нехватки входных данных
            fout << "Не хватает входных значений для решения задачи.";
        }
        else if (error.errorCode == tooMuchDataError) // Иначе если произошла ошибка из-за переизбытка входных данных
        {
            // Вывести в выходной файл сообщение о том, что данных слишком много
            fout << "Входных данных слишком много. Нужно ввести только три значения.";
        }

        fout.close();   // Закрыть файл
    }
    else    // Иначе
    {
        // Вывести в консоль сообщение об ошибке вывода
        cout << "Неверно указан файл для выходных данных. Возможно указанного расположения не существует.";
    }
}