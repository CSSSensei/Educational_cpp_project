//
// Created by tomin on 19.10.2024.
//

#ifndef S3_LABORATORY_WORK_2_BATCHERSORT_H
#define S3_LABORATORY_WORK_2_BATCHERSORT_H
#include "../Sequence/Sequence.h"
#include "ISorter.h"

template<typename T>
class BatcherSort : public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T, T)) override {
        size_t n = seq->GetLength();
        for (size_t size = 1; size < n; size *= 2) {
            for (size_t j = 0; j < n; j += 2 * size) {
                size_t left = j;
                size_t mid = std::min(j + size, n);
                size_t right = std::min(j + 2 * size, n);
                this->Merge(seq, left, mid, right, cmp);
            }
        }
        return seq;
    }

private:
    void Merge(Sequence<T>* seq, int left, int mid, int right, int (*cmp)(T, T)) {
        ArraySequence<T> merged;
        int i = left, j = mid;

        while (i < mid && j < right) {
            if (cmp(seq->Get(i), seq->Get(j)) <= 0) {
                merged.Append(seq->Get(i++));
            } else {
                merged.Append(seq->Get(j++));
            }
        }

        // Добавление оставшихся элементов
        while (i < mid) {
            merged.Append(seq->Get(i++));
        }

        while (j < right) {
            merged.Append(seq->Get(j++));
        }

        // Копируем отсортированные элементы обратно в исходную последовательность
        for (int k = 0; k < merged.GetLength(); ++k) {
            seq->Set(left + k, merged.Get(k));
        }
    }

};

#endif //S3_LABORATORY_WORK_2_BATCHERSORT_H
