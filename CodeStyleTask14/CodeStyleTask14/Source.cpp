#include "Header.h"
#include <iostream>


FDoublyLinkedList::FDoublyLinkedList() 
    : FirstElement(nullptr) {}

FDoublyLinkedList::~FDoublyLinkedList() 
{ Clear(); }

void FDoublyLinkedList::Add(int InValue)
{
    FDoubleListNode* NewNode = new FDoubleListNode(InValue);
    if (!FirstElement)
    {
        FirstElement = NewNode;
        return;
    }

    FDoubleListNode* Current = FirstElement;
    while (Current->NextNode)
    {
        Current = Current->NextNode;
    }
    Current->NextNode = NewNode;
    NewNode->PrevNode = Current;
}

bool FDoublyLinkedList::RemoveValue(int InValue)
{
    FDoubleListNode* Current = FirstElement;
    while (Current)
    {
        if (Current->Data == InValue)
        {
            if (Current->PrevNode)
            {
                Current->PrevNode->NextNode = Current->NextNode;
            }
            if (Current->NextNode)
            {
                Current->NextNode->PrevNode = Current->PrevNode;
            }
            if (Current == FirstElement)
            {
                FirstElement = Current->NextNode;
            }

            delete Current;
            return true;
        }
        Current = Current->NextNode;
    }
    return false;
}

void FDoublyLinkedList::Clear()
{
    while (FirstElement)
    {
        FDoubleListNode* Temp = FirstElement;
        FirstElement = FirstElement->NextNode;
        delete Temp;
    }
}

void FDoublyLinkedList::Print() const
{
    if (IsEmpty()) 
    {
        std::cout << "Список пуст." << std::endl;
        return;
    }

    FDoubleListNode* Current = FirstElement;
    std::cout << "Элементы списка: ";
    while (Current)
    {
        std::cout << Current->Data << " ";
        Current = Current->NextNode;
    }
    std::cout << std::endl;
}

// FIX_ME: Логика поиска Min/Max внутри вывода. 
void FDoublyLinkedList::FindMinMax(FDoubleListNode*& OutMin, FDoubleListNode*& OutMax) const
{
    if (!FirstElement)
    {
        return;
    }

    OutMin = FirstElement;
    OutMax = FirstElement;
    FDoubleListNode* Current = FirstElement->NextNode;

    while (Current)
    {
        if (Current->Data < OutMin->Data)
        {
            OutMin = Current;
        }
        if (Current->Data > OutMax->Data)
        {
            OutMax = Current;
        }
        Current = Current->NextNode;
    }
}

bool FDoublyLinkedList::IsNodeBefore(FDoubleListNode* NodeA, FDoubleListNode* NodeB) const
{
    FDoubleListNode* Current = NodeA;
    while (Current)
    {
        if (Current == NodeB)
        {
            return true;
        }
        Current = Current->NextNode;
    }
    return false;
}

void FDoublyLinkedList::PrintBetweenMinMax() const
{
    FDoubleListNode* MinNode = nullptr, * MaxNode = nullptr;
    FindMinMax(MinNode, MaxNode);

    if (!MinNode || !MaxNode || MinNode == MaxNode)
    {
        std::cout << "Недостаточно различных элементов." << std::endl;
        return;
    }

    // Определяем, кто идет раньше по списку
    bool bIsMinFirst = IsNodeBefore(MinNode, MaxNode);
    FDoubleListNode* Start = bIsMinFirst ? MinNode : MaxNode;
    FDoubleListNode* End = bIsMinFirst ? MaxNode : MinNode;

    std::cout << "Элементы между " << Start->Data << " и " << End->Data << ": ";

    FDoubleListNode* Current = Start->NextNode;
    bool bFound = false;
    while (Current && Current != End)
    {
        std::cout << Current->Data << " ";
        bFound = true;
        Current = Current->NextNode;
    }

    if (!bFound)
    {
        std::cout << "[нет элементов между]";
    }
    std::cout << std::endl;
}

// Вспомогательные функции ввода
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

bool SafeReadIntFromConsole(int& OutValue)
{
    std::string Input;
    if (!(std::cin >> Input))
    {
        return false;
    }
    if (!IsNumber(Input))
    {
        return false;
    }
    OutValue = std::stoi(Input);
    return true;
}