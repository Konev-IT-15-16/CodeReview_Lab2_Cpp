/*
Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать
разными способами (с клавиатуры, рандом, из файла)

Даны дек D и список L. Каждый исходный контейнер содержит не менее 5
элементов. Вставить перед пятым с конца элементом списка последние 5 элементов дека в
обратном порядке. Использовать один вызов функции-члена insert.
*/

#include "Header.h"
#include <iostream>
#include <ctime>

// using namespace std; FIX_ME: использование глобального пространства имён

// FIX_ME: отсутствие разделения на файлы

// FIX_ME: некорректные названия переменных

// FIX_ME: некорректный дружественный интерфейс

// FIX_ME: недостаточная проверка вводимых данных

int main()
{
    setlocale(LC_ALL, "Russian");
    std::srand(static_cast<unsigned short int>(std::time(nullptr)));

    std::deque<int> D;
    std::list<int> L;

    while (true)
    {
        std::cout << "\n--- ГЛАВНОЕ МЕНЮ ---" << std::endl;
        std::cout << "1. Заполнить Дек и Список" << std::endl;
        std::cout << "2. Выполнить вставку (последние 5 из D в L)" << std::endl;
        std::cout << "3. Вывести контейнеры (обычный + реверс)" << std::endl;
        std::cout << "4. Выход" << std::endl;
        std::cout << "Выбор: ";

        int Choice;
        if (!SafeReadInt(Choice))
        {
            continue;
        }

        if (Choice == 4)
        {
            break;
        }

        switch (Choice)
        {
        case 1:
        {
            int ModeNum;
            std::cout << "Способ: 1. Клавиатура" << std::endl;
            std::cout << "Способ: 2. Рандом" << std::endl;
            std::cout << "Способ: 3. Файл" << std::endl;
            std::cout << "Выбор: ";
            SafeReadInt(ModeNum);
            EInputMode Mode = static_cast<EInputMode>(ModeNum);

            int SizeD, SizeL;
            std::cout << "Размер D (>=5): "; SafeReadInt(SizeD);
            std::cout << "Размер L (>=5): "; SafeReadInt(SizeL);

            if (SizeD < 5 || SizeL < 5)
            {
                std::cout << "Ошибка! Размер должен быть не менее 5." << std::endl;
            }
            else
            {
                FContainerProcessor::FillDeque(D, SizeD, Mode);
                FContainerProcessor::FillList(L, SizeL, Mode);
            }
            break;
        }
        case 2:
            if (D.size() >= 5 && L.size() >= 5)
            {
                FContainerProcessor::InsertElements(D, L);
                std::cout << "Вставка выполнена успешно." << std::endl;
            }
            else
            {
                std::cout << "Ошибка: контейнеры не заполнены или малы." << std::endl;
            }
            break;
        case 3:
            FContainerProcessor::Print(D, "Дек D");
            FContainerProcessor::Print(L, "Список L");
            FContainerProcessor::PrintReverse(L, "Список L");
            break;
        }
    }
    return 0;
}