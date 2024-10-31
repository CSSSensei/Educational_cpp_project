
#ifndef S3_LABORATORY_WORK_2_MENUSEQUENCE_H
#define S3_LABORATORY_WORK_2_MENUSEQUENCE_H

#include <string>
#include <unordered_map>
#include "../../Sequence/Sequence.h"
#include <limits>

enum class Command {
    Quit,
    Append,
    Prepend,
    Pop,
    Remove,
    Insert,
    Subseq,
    Print,
    Invalid,
    GetFirst,
    GetLast,
    Sort,
    InputRandom
};

Command hash_command(const std::string &command);

int menu_sequence();

template <typename T>
T getNumberInput() {
    T value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::wcout << L"Please enter a valid value.\n";
        } else {
            break;
        }
    }
    return value;
}

template<typename T>
void interactWithSequence(Sequence<T> *sequence);


template<typename T>
void print(Sequence<T> *sequence);

#endif //S3_LABORATORY_WORK_2_MENUSEQUENCE_H
