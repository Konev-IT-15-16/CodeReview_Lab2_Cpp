#pragma once

#include <string>

/*
struct Uzel {
    int Znachenie;         // Значение узла
    Uzel* Predydushiy;      // Указатель на предыдущий узел
    Uzel* Sleduyushiy;      // Указатель на следующий узел
};
*/
struct FDoubleListNode
{
    int Data;
    FDoubleListNode* PrevNode;
    FDoubleListNode* NextNode;

    FDoubleListNode(int InValue)
        : Data(InValue)
        , PrevNode(nullptr)
        , NextNode(nullptr)
    {}
};

// class Spisok {
class FDoublyLinkedList
{
public:

    /* FIX_ME: используется метод для реализации (нужен конструктор)
    // Инициализация списка
    void Initsializatsiya() {
        PerviyElement = nullptr;
    }
    */

    FDoublyLinkedList();
    ~FDoublyLinkedList();

    // Добавить в конец
    void Add(int InValue);

    // FIX_ME: отсутствует стандартный метод удаления элемента
    // Удалить элемент по значению
    bool RemoveValue(int InValue);

    // Вывести все элементы
    void Print() const;

    // Очистить список
    void Clear();

    // Специальный метод по заданию: вывод между Min и Max
    void PrintBetweenMinMax() const;

    bool IsEmpty() const
    {
        return FirstElement == nullptr;
    }

private:
    FDoubleListNode* FirstElement;

    // Вспомогательные методы для поиска
    void FindMinMax(FDoubleListNode*& OutMin, FDoubleListNode*& OutMax) const;
    bool IsNodeBefore(FDoubleListNode* NodeA, FDoubleListNode* NodeB) const;
};

// Вспомогательные функции для безопасного ввода
bool IsNumber(const std::string& Str);
bool SafeReadIntFromConsole(int& OutValue);