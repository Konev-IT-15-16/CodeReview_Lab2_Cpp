/*Дан односвязный линейный список и указатель на голову списка P1. Необходимо
вставить значение M перед каждым вторым элементом списка, и вывести ссылку на последний
элемент полученного списка P2. При нечетном числе элементов исходного списка в конец
списка вставлять не надо.


Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

*/

#include "Header.h"
#include <iostream>

// using namespace std FIX_ME: использование глобального пространства имён

// FIX_ME: некорректные имена переменных, классов, функций (префикс F, PascalCase)

// FIX_ME: вся реализация в main

// FIX_ME: отсутствие дружественного интерфейса и проверок на вводимые данные

// FIX_ME: неверное расположение скобок

int main()
{
    setlocale(LC_ALL, "Russian");
    FLinkedList List;
    int Choice = 0;

    while (true)
    {
        std::cout << "\n--- МЕНЮ СПИСКА ---" << std::endl;
        std::cout << "1. Добавить элемент (Add)" << std::endl;
        std::cout << "2. Вывести список (Print)" << std::endl;
        std::cout << "3. Вставить M перед каждым вторым" << std::endl;
        std::cout << "4. Показать адрес последнего элемента" << std::endl;
        std::cout << "5. Очистить список" << std::endl;
        std::cout << "6. Выход" << std::endl;
        std::cout << "Ваш выбор: ";

        if (!SafeReadIntFromConsole(Choice))
        {
            continue;
        }

        if (Choice == 6)
        {
            break;
        }

        switch (Choice)
        {
        case 1:
            int Val;
            std::cout << "Введите значение: ";
            if (SafeReadIntFromConsole(Val)) List.Add(Val);
            break;
        case 2:
            List.Print();
            break;
        case 3:
            int M;
            std::cout << "Введите M: ";
            if (SafeReadIntFromConsole(M))
            {
                List.InsertBeforeEverySecond(M);
            }
            break;
        case 4:
        {
            FListNode* Last = List.GetLastNode();
            if (Last)
            {
                std::cout << "Адрес: " << Last << ", Значение: " << Last->Data << std::endl;
            }
            else
            {
                std::cout << "Список пуст." << std::endl;
            }
        }
        break;
        case 5:
            List.Clear();
            std::cout << "Список очищен." << std::endl;
            break;
        default:
            std::cout << "Неверный пункт." << std::endl;
        }
    }
    return 0;
}