#pragma once

#include <string>

/** * FIX_ME: Структура PNode переименована в FQueueNode.
 * Поля d и next заменены на Data и NextNode.
 */
struct FQueueNode
{
    int Data;
    FQueueNode* NextNode;

    FQueueNode(int InValue)
        : Data(InValue)
        , NextNode(nullptr)
    {}
};

/** * FIX_ME: Класс PQueue заменен на полноценный класс FQueue.
 * Вместо передачи параметров по ссылке в функции Enqueue/Dequeue,
 * теперь используются методы объекта.
 */
class FQueue
{
public:
    FQueue();
    ~FQueue();

    // Добавить элемент в конец
    void Enqueue(int InValue);

    // Извлечь элемент из начала
    int Dequeue(int& OutValue);

    // Вывести состояние очереди
    void Display() const;
    
    bool IsEmpty() const
    {
        return Head == nullptr;
    }

    // Геттеры для вывода адресов
    FQueueNode* GetHead() const
    {
        return Head;
    }
    FQueueNode* GetTail() const
    {
        return Tail;
    }

private:
    FQueueNode* Head;
    FQueueNode* Tail;
};

// Вспомогательные функции для безопасного ввода
bool IsNumber(const std::string& Str);
bool SafeReadIntFromConsole(int& OutValue);