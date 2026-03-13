#pragma once

#include <string>

/*
class Node {
public:
    int data;       
    Node* next;     
    Node(int value) : data(value), next(nullptr) {}
};
*/

struct FListNode
{
    int Data;
    FListNode* NextNode;

    FListNode(int InValue)
        : Data(InValue)
        , NextNode(nullptr)
    {}
};
// class LinkedList
class FLinkedList
{
public:
    FLinkedList();
    ~FLinkedList();

    // Добавить элемент в конец
    void Add(int InValue);

    // Удалить первый найденный элемент по значению
    bool Remove(int InValue);

    // FIX_ME: отсутствие деструктора
    // Очистить весь список
    void Clear();

    // Вывести список
    void Print() const;

    // Специальный метод по заданию: вставка M перед каждым вторым
    void InsertBeforeEverySecond(int InM);

    // Получить указатель на последний элемент
    FListNode* GetLastNode() const;

    bool IsEmpty() const 
    {
        return Head == nullptr;
    }

private:
    FListNode* Head;
};

// Вспомогательные функции для безопасного ввода
bool IsNumber(const std::string& Str);
bool SafeReadIntFromConsole(int& OutValue);