#include "Header.h"
#include <iostream>

// Вспомогательная функция для безопасного ввода
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

// Вспомогательная функция для безопасного ввода
bool SafeReadIntFromConsole(int& OutValue)
{
    std::string Input;
    std::cin >> Input;
    if (!IsNumber(Input))
    {
        std::cout << "Ошибка: Введено не число." << std::endl;
        return false;
    }
    OutValue = std::stoi(Input);
    return true;
}

FQueue::FQueue()
    : Head(nullptr)
    , Tail(nullptr)
{}

FQueue::~FQueue()
{
    int Dummy;
    while (Dequeue(Dummy));
}

// void Enqueue(PQueue& Q, int d)
void FQueue::Enqueue(int InValue)
{
    FQueueNode* NewNode = new FQueueNode(InValue);

    if (IsEmpty())
    {
        Head = NewNode;
        Tail = NewNode;
    }
    else
    {
        // Q.last->next = newNode
        Tail->NextNode = NewNode;
        Tail = NewNode;
    }
}

// int Dequeue(PQueue& Q)
int FQueue::Dequeue(int& OutValue)
{
    if (IsEmpty())
    {
        return 0;
    }

    FQueueNode* Temp = Head;
    OutValue = Temp->Data;

    Head = Head->NextNode;

    if (Head == nullptr)
    {
        Tail = nullptr;
    }

    delete Temp;
    return OutValue;
}

void FQueue::Display() const
{
    if (IsEmpty())
    {
        std::cout << "Очередь пуста." << std::endl;
        return;
    }

    FQueueNode* Current = Head;
    std::cout << "Начало -> ";
    while (Current)
    {
        std::cout << "[" << Current->Data << "] ";
        Current = Current->NextNode;
    }
    std::cout << "<- Конец" << std::endl;
    std::cout << "Адрес Head: " << Head << " | Адрес Tail: " << Tail << std::endl;
}