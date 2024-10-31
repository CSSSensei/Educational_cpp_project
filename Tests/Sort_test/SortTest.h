//
// Created by tomin on 22.10.2024.
//

#ifndef S3_LABORATORY_WORK_2_SORTTEST_H
#define S3_LABORATORY_WORK_2_SORTTEST_H
#include "../../Sequence/LinkedListSequence.h"
#include "../../Sequence/ArraySequence.h"
#include "../../Sort/BubbleSort.h"
#include "../../Sort/BatcherSort.h"
#include "../../Sort/QuickSort.h"
#include "../../Sort/SelectionSort.h"
#include <cassert>


template<typename T>
void TestSorting(ISorter<T>* sorter) {
    srand(time(0));
    int size = 1000;
    {
        auto arr = new int[size];
        for (int j = 0; j < size; j++) {
            arr[j] = rand();
        }
        LinkedListSequence<T> seq(arr, size);

        auto cmp = [](T a, T b) { return (a >= b) - (a <= b); };
        sorter->Sort(&seq, cmp);

        for (size_t i = 1; i < seq.GetLength(); ++i) {
            assert(seq.Get(i - 1) <= seq.Get(i) && "Sequence is not sorted!");
        }
        delete[] arr;
    }

    {
        ArraySequence<T> seq;
        for (int j = 0; j < size; j++) {
            seq.Append(rand());
        }

        auto cmp = [](T a, T b) { return (a >= b) - (a <= b); };
        sorter->Sort(&seq, cmp);

        for (size_t i = 1; i < seq.GetLength(); ++i) {
            assert(seq.Get(i - 1) <= seq.Get(i) && "Sequence is not sorted!");
        }
    }
}

void test_sort_main() {
    {
        BatcherSort<int> batcherSorter;
        TestSorting(&batcherSorter);
        std::cout << "BatcherSort passed.\n";
    }

    {
        BubbleSorter<int> bubbleSorter;
        TestSorting(&bubbleSorter);
        std::cout << "BubbleSorter passed.\n";
    }

    {
        SelectionSorter<int> selectionSorter;
        TestSorting(&selectionSorter);
        std::cout << "SelectionSorter passed.\n";
    }

    {
        QuickSort<int> quickSorter;
        TestSorting(&quickSorter);
        std::cout << "QuickSort passed.\n";
    }
}

#endif //S3_LABORATORY_WORK_2_SORTTEST_H
