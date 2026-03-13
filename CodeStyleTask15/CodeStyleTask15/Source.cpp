#include "Header.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <iterator>
#include <algorithm>

void FContainerProcessor::FillDeque(std::deque<int>& OutDeque, int InSize, EInputMode InMode)
{
    OutDeque.clear();
    if (InMode == EInputMode::Keyboard)
    {
        std::cout << "Введите " << InSize << " чисел для Дека: ";
        for (int i = 0; i < InSize; ++i)
        {
            int Val;
            if (SafeReadInt(Val))
            {
                OutDeque.push_back(Val);
            }
        }
    }
    else if (InMode == EInputMode::Random)
    {
        for (int i = 0; i < InSize; ++i)
        {
            OutDeque.push_back(std::rand() % 100);
        }
    }
    else if (InMode == EInputMode::File)
    {
        std::ifstream InFile("input_deque.txt");
        // FIX_ME: Добавлена проверка открытия файла
        if (InFile.is_open())
        {
            int Val;
            for (int i = 0; i < InSize && (InFile >> Val); ++i)
            {
                OutDeque.push_back(Val);
            }
            InFile.close();
        }
        else
        {
            std::cout << "Файл input_deque.txt не найден!" << std::endl;
        }
    }
}

void FContainerProcessor::FillList(std::list<int>& OutList, int InSize, EInputMode InMode)
{
    OutList.clear();
    if (InMode == EInputMode::Keyboard)
    {
        std::cout << "Введите " << InSize << " чисел для Списка: ";
        for (int i = 0; i < InSize; ++i)
        {
            int Val;
            if (SafeReadInt(Val))
            {
                OutList.push_back(Val);
            }
        }
    }
    else if (InMode == EInputMode::Random)
    {
        for (int i = 0; i < InSize; ++i)
        {
            OutList.push_back(std::rand() % 100);
        }
    }
    else if (InMode == EInputMode::File)
    {
        std::ifstream InFile("input_list.txt");
        if (InFile.is_open())
        {
            int Val;
            for (int i = 0; i < InSize && (InFile >> Val); ++i)
            {
                OutList.push_back(Val);
            }
            InFile.close();
        }
    }
}

void FContainerProcessor::InsertElements(const std::deque<int>& InDeque, std::list<int>& InOutList)
{
    if (InDeque.size() < 5 || InOutList.size() < 5)
    {
        return;
    }

    // 1. Находим позицию: 5-й с конца в списке
    auto ItPos = InOutList.end();
    std::advance(ItPos, -5);

    // 2. Берем диапазон: последние 5 элементов дека в обратном порядке
    // Используем обратные итераторы дека rbegin()
    auto RangeStart = InDeque.rbegin();
    auto RangeEnd = std::next(RangeStart, 5);

    // FIX_ME: нарушение условия задачи (многократный вызов insert)
    /*
    for (int i = 0; i < n;i++)
        {
            cout << "Введите " << i + 1 << " элемент: ";
            cin >> x;
            N.insert(N.end(), x);
        }
    */
    InOutList.insert(ItPos, RangeStart, RangeEnd);
}

template<typename T>
void FContainerProcessor::Print(const T& InContainer, const std::string& InLabel)
{
    std::cout << InLabel << ": ";
    for (auto It = InContainer.begin(); It != InContainer.end(); ++It)
    {
        std::cout << *It << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void FContainerProcessor::PrintReverse(const T& InContainer, const std::string& InLabel)
{
    std::cout << InLabel << " (реверс): ";
    // FIX_ME: Использование rbegin/rend по требованию задания
    for (auto It = InContainer.rbegin(); It != InContainer.rend(); ++It)
    {
        std::cout << *It << " ";
    }
    std::cout << std::endl;
}

// Инстанцирование шаблонов
template void FContainerProcessor::Print(const std::deque<int>&, const std::string&);
template void FContainerProcessor::Print(const std::list<int>&, const std::string&);
template void FContainerProcessor::PrintReverse(const std::list<int>&, const std::string&);

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

bool SafeReadInt(int& OutValue)
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