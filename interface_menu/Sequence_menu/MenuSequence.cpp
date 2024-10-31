#include <limits>
#include "MenuSequence.h"
#include "../../Sequence/ArraySequence.h"
#include "../../Sequence/LinkedListSequence.h"
#include "../Sort_menu/MenuSort.h"

Command hash_command(const std::string &command) {
    static const std::unordered_map<std::string, Command> commandMap = {
            {"quit",    Command::Quit},
            {"append",  Command::Append},
            {"prepend", Command::Prepend},
            {"pop",     Command::Pop},
            {"remove",  Command::Remove},
            {"insert",  Command::Insert},
            {"subseq",  Command::Subseq},
            {"print",   Command::Print},
            {"getfirst", Command::GetFirst},
            {"getlast", Command::GetLast},
            {"sort", Command::Sort},
            {"randominp", Command::InputRandom}
    };

    auto it = commandMap.find(command);
    if (it != commandMap.end()) {
        return it->second;
    }

    return Command::Invalid;
}

template<typename T>
void print(Sequence<T> *sequence) {
    if (sequence->GetLength() == 0){
        std::cout << "Sequence is empty\n";
    }
    for (int i = 0; i < sequence->GetLength(); i++) {
        std::cout << sequence->Get(i) << ' ';
    }
    std::cout << '\n';
}


template<typename T>
void interactWithSequence(Sequence<T> *sequence) {
    std::string commandStr;
    Sequence<T> *sub;
    Command command;
    T value;
    int index, l, r;
    while (true) {
        std::cout << "Enter command (randominp, append, prepend, pop, remove, insert, subseq, print, getfirst, getlast, sort, quit):\n  ";
        std::cin >> commandStr;
        command = hash_command(commandStr);
        switch (command) {
            case Command::Quit:
                return;

            case Command::Append:
                std::cout << "Enter value to append:\n";
                value = getNumberInput<int>();
                sequence->Append(value);
                break;

            case Command::Prepend:
                std::cout << "Enter value to prepend:\n";
                value = getNumberInput<int>();
                sequence->Prepend(value);
                break;

            case Command::Pop:
                sequence->Pop();
                break;

            case Command::Remove:
                std::cout << "Enter left and right border to delete ";
                l = getNumberInput<int>();
                r = getNumberInput<int>();
                if (l > r || r >= sequence->GetLength() || l < 0) {
                    std::cout << "Wrong borders\n";
                    break;
                }
                sequence->Remove(l, r);
                break;

            case Command::Insert:
                std::cout << "Enter index and value to insert:\n";
                index = getNumberInput<int>();
                value = getNumberInput<int>();
                if (index > sequence->GetLength() || index < 0) {
                    std::cout << "Wrong index\n";
                    break;
                }
                sequence->InsertAt(value, index);
                break;

            case Command::Subseq:
                std::cout << "Enter left and right indices for subsequence:\n";
                l = getNumberInput<int>();
                r = getNumberInput<int>();
                if (l > r || r >= sequence->GetLength() || l < 0) {
                    std::cout << "Wrong borders\n";
                    break;
                }
                sub = sequence->GetSubsequence(l, r);
                print(sub);
                break;

            case Command::GetFirst:
                std::cout << sequence->GetFirst() << std::endl;
                break;

            case Command::GetLast:
                std::cout << sequence->GetLast() << std::endl;
                break;

            case Command::Print:
                print(sequence);
                break;

            case Command::Sort:
                interactWithSorting(sequence);
                break;

            case Command::InputRandom:
                std::cout << "Enter the amount of random items to input\n";
                l = getNumberInput<int>();
                srand(time(0));
                for (int i = 0; i < l; i++) {
                    sequence->Append(rand());
                }
//                print(sequence);
                break;

            default:
                std::cout << "Invalid command." << std::endl;
                break;
        }
    }
}


int menu_sequence() {
    std::cout << "Choose sequence type (list or array):\n";
    std::string type;
    std::cin >> type;

    Sequence<int> *sequence = nullptr;

    if (type == "list") {
        sequence = new LinkedListSequence<int>();
    } else if (type == "array") {
        sequence = new ArraySequence<int>();
    } else {
        std::cout << "Invalid sequence type." << std::endl;
        return 1;
    }
    interactWithSequence(sequence);
}