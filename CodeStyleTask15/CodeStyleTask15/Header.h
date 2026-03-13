#pragma once

#include <deque>
#include <list>
#include <string>

// Способы заполнения контейнера
enum class EInputMode : unsigned short int
{
    Keyboard = 1,
    Random = 2,
    File = 3
};

// Класс для работы с контейнерами
class FContainerProcessor
{
public:
    // Заполнение дека
    static void FillDeque(std::deque<int>& OutDeque, int InSize, EInputMode InMode);

    // Заполнение списка
    static void FillList(std::list<int>& OutList, int InSize, EInputMode InMode);

    // Вставка за ОДИН вызов insert
    static void InsertElements(const std::deque<int>& InDeque, std::list<int>& InOutList);

    // Вывод контейнера через итераторы
    template<typename T>
    static void Print(const T& InContainer, const std::string& InLabel);

    // Вывод в обратном порядке через rbegin/rend
    template<typename T>
    static void PrintReverse(const T& InContainer, const std::string& InLabel);
};

// Вспомогательные функции для безопасного ввода
bool IsNumber(const std::string& Str);
bool SafeReadInt(int& OutValue);