/* Дан двусвязный линейный список и указатель первый элемент этого
списка. Все элементы списка хранят различные между собой значения. Необходимо
вывести значения элементов списка, которые находятся между наименьшим и
наибольшим элементами списка, в том порядке, в каком они находятся в исходном
списке. Использовать процедуры.

Все динамические структуры данных реализовывать через классы. Не использовать STL.
Для каждой динамической структуры должен быть предусмотрен
стандартный набор методов - добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
*/

#include "Header.h"
#include <iostream>

// using namespace std; FIX_ME: использование глобального пространства времён

// FIX_ME: вся реализация в main

// FIX_ME: использование кириллицы в названиях переменных, функций, классов. 
// (отсутствие префикса F для классов и несоответствие PascalCase)

// FIX_ME: недостаточная проверка вводимых данных

// FIX_ME: отсутствие дружественного интерфейса

// FIX_ME: неправильное расположение скобок

int main()
{
    setlocale(LC_ALL, "Russian");
    FDoublyLinkedList List;
    int Choice = 0;

    while (true)
    {
        std::cout << "\n--- МЕНЮ ДВУСВЯЗНОГО СПИСКА ---" << std::endl;
        std::cout << "1. Добавить элемент" << std::endl;
        std::cout << "2. Удалить элемент" << std::endl;
        std::cout << "3. Вывести список" << std::endl;
        std::cout << "4. Вывести элементы между Min и Max" << std::endl;
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
            std::cout << "Введите значение для удаления: ";
            if (SafeReadIntFromConsole(Val))
            {
                if (List.RemoveValue(Val))
                {
                    std::cout << "Удалено." << std::endl;
                }
                else
                {
                    std::cout << "Не найдено." << std::endl;
                }
            }
            break;
        case 3:
            List.Print();
            break;
        case 4:
            List.PrintBetweenMinMax();
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