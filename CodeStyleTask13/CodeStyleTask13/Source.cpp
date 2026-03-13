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
    if (!(std::cin >> Input))
    {
        return false;
    }
    if (!IsNumber(Input))
    {
        std::cout << "Ошибка: '" << Input << "' не число." << std::endl;
        return false;
    }
    OutValue = std::stoi(Input);
    return true;
}

FLinkedList::FLinkedList() 
    : Head(nullptr) {}

FLinkedList::~FLinkedList() 
{ Clear(); }

void FLinkedList::Add(int InValue)
{
    FListNode* NewNode = new FListNode(InValue);
    if (!Head)
    {
        Head = NewNode;
        return;
    }
    FListNode* Current = Head;
    while (Current->NextNode)
    {
        Current = Current->NextNode;
    }
    Current->NextNode = NewNode;
}

void FLinkedList::Clear()
{
    while (Head)
    {
        FListNode* Temp = Head;
        Head = Head->NextNode;
        delete Temp;
    }
}

void FLinkedList::Print() const
{
    if (!Head)
    {
        std::cout << "Список пуст." << std::endl;
        return;
    }
    FListNode* Current = Head;
    while (Current)
    {
        std::cout << "[" << Current->Data << "]" << (Current->NextNode ? " -> " : "");
        Current = Current->NextNode;
    }
    std::cout << std::endl;
}

// FIX_ME: Логика вставки: "перед каждым вторым". (правильнее использовать указатели)
void FLinkedList::InsertBeforeEverySecond(int InM)
{
    if (!Head || !Head->NextNode)
    {
        return;
    }

    FListNode* Prev = Head;
    FListNode* Curr = Head->NextNode;
    int Index = 2;

    while (Curr)
    {
        if (Index % 2 == 0)
        {
            FListNode* NewNode = new FListNode(InM);
            NewNode->NextNode = Curr;
            Prev->NextNode = NewNode;
            Prev = NewNode;
        }
        Prev = Curr;
        Curr = Curr->NextNode;
        Index++;
    }
}

FListNode* FLinkedList::GetLastNode() const
{
    if (!Head)
    {
        return nullptr;
    }
    FListNode* Current = Head;
    while (Current->NextNode) Current = Current->NextNode;
    return Current;
}