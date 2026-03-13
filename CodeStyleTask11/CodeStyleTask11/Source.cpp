#include "Header.h"
#include <iostream>

// Вспомогательая функция для валидации
// bool isNumber(const std::string& Str)
bool IsNumber(const std::string& Str)
{
    if (Str.empty())
    {
        return false;
    }
    size_t Start = (Str[0] == '-') ? 1 : 0;
    for (size_t i = Start; i < Str.length(); i++)
    {
        if (!isdigit(Str[i]))
        {
            return false;
        }
    }
    return true;
}

// Вспомогательая функция для валидации
bool SafeReadIntFromConsole(int& OutValue)
{
    std::string Input;
    std::cin >> Input;
    if (!IsNumber(Input))
    {
        std::cout << "Ошибка: '" << Input << "' не является числом." << std::endl;
        return false;
    }
    OutValue = std::stoi(Input);
    return true;
}

// FIX_ME: Конструктор с инициализацией через двоеточие на новых строках.
// stack() : p1(nullptr),cnt(0){}
FStack::FStack()
    : TopNode(nullptr)
    , ElementCount(0)
{}

FStack::~FStack()
{
    while (!IsEmpty())
    {
        // Внутренняя очистка без вывода в консоль
        FStackNode* Temp = TopNode;
        TopNode = TopNode->NextNode;
        delete Temp;
    }
}

// FIX_ME: Параметры начинаются с In.
// void add(int x)
void FStack::Push(int InValue)
{
    FStackNode* NewNode = new FStackNode(InValue);
    NewNode->NextNode = TopNode;
    TopNode = NewNode;
    ElementCount++;
}

// void topdel()
void FStack::PopAndPrint()
{
    if (IsEmpty())
    {
        std::cout << "Стек пуст, извлечение невозможно." << std::endl;
        return;
    }

    FStackNode* TempNode = TopNode;

    std::cout << "--- Извлечение элемента ---" << std::endl;
    std::cout << "Значение (D): " << TempNode->Data << std::endl;

    TopNode = TopNode->NextNode;

    // Вывод адреса новой вершины (P2)
    if (TopNode)
    {
        std::cout << "Адрес новой вершины (P2): " << TopNode << std::endl;
        std::cout << "Значение новой вершины: " << TopNode->Data << std::endl;
    }
    else
    {
        std::cout << "Стек теперь пуст (P2 = nullptr)." << std::endl;
    }

    delete TempNode;
    ElementCount--;
}

void FStack::Display() const
{
    if (IsEmpty())
    {
        std::cout << "Стек пуст." << std::endl;
        return;
    }

    FStackNode* Current = TopNode;
    std::cout << "Текущий стек (от вершины): ";
    while (Current)
    {
        std::cout << Current->Data << " -> ";
        Current = Current->NextNode;
    }
    std::cout << "null" << std::endl;
}