//
// Created by tomin on 22.10.2024.
//

#ifndef S3_LABORATORY_WORK_2_MENUSORT_H
#define S3_LABORATORY_WORK_2_MENUSORT_H

#include <string>
#include <unordered_map>
#include "../../Sequence/Sequence.h"
#include "../../Sort/BubbleSort.h"
#include "../../Sort/BatcherSort.h"
#include "../../Sort/QuickSort.h"
#include "../../Sort/SelectionSort.h"
#include <chrono>

int Compare(int a, int b) {
    return (a > b) - (a < b); // Возвращает 1, если a > b; -1, если a < b; 0, если равны
}

enum class SortingMethod {
    Invalid,
    Batcher,
    Bubble,
    Quick,
    Selection
};

SortingMethod hash_sort(const std::string &command) {
    static const std::unordered_map<std::string, SortingMethod> commandMap = {
            {"batcher",   SortingMethod::Batcher},
            {"bubble",    SortingMethod::Bubble},
            {"quick",     SortingMethod::Quick},
            {"selection", SortingMethod::Selection}
    };

    auto it = commandMap.find(command);
    if (it != commandMap.end()) {
        return it->second;
    }

    return SortingMethod::Invalid;
}

template<typename T>
void interactWithSorting(Sequence<T> *sequence) {
    std::string commandStr;
    SortingMethod command;

    while (true) {
        std::cout << "Enter sorting method (batcher, bubble, quick, selection):\n  ";
        std::cin >> commandStr;
        command = hash_sort(commandStr);

        ISorter<T>* sorter = nullptr;

        switch (command) {
            case SortingMethod::Batcher:
                sorter = new BatcherSort<T>();
                break;
            case SortingMethod::Bubble:
                sorter = new BubbleSorter<T>();
                break;
            case SortingMethod::Selection:
                sorter = new SelectionSorter<T>();
                break;
            case SortingMethod::Quick:
                sorter = new QuickSort<T>();
                break;
            default:
                std::cout << "Invalid command." << std::endl;
                continue;
        }

        // Замер времени
        auto start = std::chrono::high_resolution_clock::now();
        sorter->Sort(sequence, Compare);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Sequence was sorted! Time taken: " << elapsed.count() << " seconds.\n";

        return;
    }
}

#endif //S3_LABORATORY_WORK_2_MENUSORT_H
