//
// Created by tomin on 19.10.2024.
//

#ifndef S3_LABORATORY_WORK_2_QUICKSORT_H
#define S3_LABORATORY_WORK_2_QUICKSORT_H
#include "ISorter.h"

template <typename T>
class QuickSort : public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T, T)) {
        sort_partly(seq, cmp, 0, seq->GetLength() - 1);
        return seq;
    }
private:
    void sort_partly(Sequence<T>* seq, int (*cmp)(T, T), int left, int right) {
        if (left < right) {
            int p = partition(seq, cmp, left, right);
            sort_partly(seq, cmp, left, p - 1);
            sort_partly(seq, cmp, p + 1, right);
        }
    }

    int partition(Sequence<T>* seq, int (*cmp)(T, T), int left, int right) {
        T pivot = seq->Get(right); // Последний элемент опорный
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (cmp(seq->Get(j), pivot) <= 0) {
                i++;
                if (i == j) continue;
                // Swap seq[i] and seq[j]
                T temp = seq->Get(i);
                seq->Set(i, seq->Get(j));
                seq->Set(j, temp);
            }
        }

        // Swap seq[i + 1] and seq[right] (or pivot)
        T temp = seq->Get(i + 1);
        seq->Set(i + 1, seq->Get(right));
        seq->Set(right, temp);
        return i + 1;
    }
};
#endif //S3_LABORATORY_WORK_2_QUICKSORT_H
