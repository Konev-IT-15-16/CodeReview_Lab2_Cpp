#pragma once

#include <string>

// Структура узла стека
struct FStackNode
{
    int Data;
    FStackNode* NextNode;

    FStackNode(int InValue)
        : Data(InValue)
        , NextNode(nullptr)
    {}
};

// FIX_ME: некорректный порядок публичной и приватной реализации
/*
class stack {
private:
  struct Node {
    int d;
    Node* next;
    Node(int val) :d(val), next(nullptr) {}
  };
  Node* p1; //вершина
  int cnt;
public:
  stack() : p1(nullptr),cnt(0){}
  void add(int x) {
    Node* newnode = new Node(x);
    newnode->next = p1;
    p1 = newnode;
    cnt++;
  }
 */

// Класс для управления стеком
class FStack
{
public:
    FStack();
    ~FStack();

    // Добавить элемент в стек
    void Push(int InValue);

    // Извлечь верхний элемент, вывести его данные и адрес новой вершины
    void PopAndPrint();

    // Вывести все элементы стека
    void Display() const;

    // Проверка на пустоту
    bool IsEmpty() const
    {
        return TopNode == nullptr; 
    }

private:
    FStackNode* TopNode;
    int ElementCount;
};

// Вспомогательные функции для валидации
bool IsNumber(const std::string& Str);
bool SafeReadIntFromConsole(int& OutValue);