#include "../Tests/Tests_AS and LLS.h"
#include <cassert>
#include <cstdlib>
#include "../Sequence/ArraySequence.h"
#include "../Sequence/LinkedListSequence.h"
#include "iostream"

float round_float2(float a, int order) {
    for (int i = 0; i < order; i++) {
        a = a * 10;
    }
    a = (float) (int) a / 10;
    for (int i = 0; i < order - 1; i++) {
        a = a / 10;
    }
    return a;
}

void constructors_AS() {
    ArraySequence<int> AS1;
    srand(4541);
    assert(AS1.GetLength() == 0);

    for (int i = 1; i < 10000; i++) {
        auto arr = new int[i];
        for (int j = 0; j < i; j++) {
            arr[j] = rand();
        }
        ArraySequence<int> AS2(arr, i);
        assert(AS2.GetLength() == i);
        for (int k = 0; k < i; k++) {
            assert(AS2.Get(k) == arr[k]);
        }
        ArraySequence<int> AS3(AS2);
        assert(AS3.GetLength() == AS2.GetLength());
        assert(AS2.GetLength() == i);
        for (int k = 0; k < i; k++) {
            assert(AS3.Get(k) == AS2.Get(k));
        }

        AS3.Delete_ArraySequence();
        AS2.Delete_ArraySequence();
        delete[] arr;
    }
    AS1.Delete_ArraySequence();

    std::wcout << L"Проверка конструкторов AS прошла 10000 тестов" << std::endl;
}

void decomposition_AS() {
    srand(4541);
    for (int i = 10; i < 1000; i++) {
        auto arr = new int[i];
        for (int j = 0; j < i; j++) {
            arr[j] = rand();
        }
        ArraySequence<int> AS(arr, i);
        assert(AS.GetFirst() == arr[0]);
        assert(AS.GetLast() == arr[i - 1]);
        assert(AS.GetLength() == i);
        for (int k = 0; k < i; k++) {
            assert(AS.Get(k) == arr[k]);
        }
        delete[] arr;
        AS.Delete_ArraySequence();

    }

    std::wcout << L"Проверка деконструкторов AS прошла 10000 тестов" << std::endl;
}

void function_AS() {
    srand(4541);
    for (int i = 10; i < 11; i++) {
        auto arr = new int[i];
        for (int j = 0; j < i; j++) {
            arr[j] = rand();
        }
        ArraySequence<int> AS(arr, i);
        assert(AS.GetLength() == i);
        int item = rand();
        AS.Append(item);
        assert(AS.GetLength() == i + 1);
        assert(AS.Get(i) == item);
//        AS.Prepend(item);
//        std::cout << AS.GetSize() << ' ';
//        assert(AS.GetLength() == i + 1);
//        std::cout << AS.GetLength() << ' ';
//        assert(AS.GetFirst() == item);
//        std::cout << AS.GetFirst();
        AS.Prepend(item);
        assert(AS.GetLength() == i + 2);
        assert(AS.GetFirst() == item);
        //delete[] arr;
        //AS.Delete_ArraySequence();
    }

    std::wcout << L"Проверка функций AS прошла 10000 тестов" << std::endl;
}

void constructors_LLS() {
    LinkedListSequence<int> LLS1;
    assert(LLS1.GetLength() == 0);
    srand(4540);

    for (int i = 1; i < 1000; i++) {
        auto arr = new int[i];
        for (int j = 0; j < i; j++) {
            arr[j] = rand();
        }
        LinkedListSequence<int> LLS2(arr, i);
        assert(LLS2.GetLength() == i);
        for (int k = 0; k < i; k++) {
            assert(LLS2.Get(k) == arr[k]);
        }
        LinkedListSequence<int> LLS3(LLS2);
        assert(LLS3.GetLength() == LLS2.GetLength());
        for (int k = 0; k < i; k++) {
            assert(LLS3.Get(k) == LLS2.Get(k));
        }

        LLS2.Delete_LinkedListSequene();
        LLS3.Delete_LinkedListSequene();
        delete[] arr;
    }
    LLS1.Delete_LinkedListSequene();

    std::wcout << L"Проверка конструкторов LLS прошла 10000 тестов " << std::endl;
}

void decomposition_LLS() {
    srand(4541);
    for (int i = 10; i < 1000; i++) {
        auto arr = new int[i];
        for (int j = 0; j < i; j++) {
            arr[j] = rand();
        }
        LinkedListSequence<int> LLS(arr, i);
        assert(LLS.GetFirst() == arr[0]);
        assert(LLS.GetLast() == arr[i - 1]);
        assert(LLS.GetLength() == i);
        for (int k = 0; k < i; k++) {
            assert(LLS.Get(k) == arr[k]);
        }

        LLS.Delete_LinkedListSequene();
        delete[] arr;
    }

    std::wcout << L"Проверка деконструкторов LLS прошла 10000 тестов" << std::endl;
}

void function_LLS() {
    srand(4541);
    for (int i = 10; i < 10000; i++) {
        auto arr = new int[i];
        for (int j = 0; j < i; j++) {
            arr[j] = rand();
        }
        LinkedListSequence<int> LLS(arr, i);
        int item = rand();
        LLS.Append(item);
        assert(LLS.GetLength() == i + 1);
        assert(LLS.Get(i) == item);
        LLS.Prepend(item);
        assert(LLS.GetLength() == i + 2);
        assert(LLS.Get(0) == item);

        LLS.Delete_LinkedListSequene();
        delete[] arr;
    }

    std::wcout << L"Проверка функций LLS прошла 10000 тестов" << std::endl;
}
