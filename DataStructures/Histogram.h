#ifndef S3_LABORATORY_WORK_2_HISTOGRAM_H
#define S3_LABORATORY_WORK_2_HISTOGRAM_H
#include <memory>
#include "../Map/IDictionary.h"
#include "../Map/HashMap.h"
#include "../pointers/UnqPtr.h"
#include "../Sequence/Sequence.h"
#include <vector>

template <typename T, typename KeyFunc>
class Histogram {
private:
    IDictionary<std::pair<double, double>, int>& histogramMap; // Ключ - диапазон, значение - количество
    KeyFunc keyExtractor; // Функция для извлечения ключа из элемента
    std::vector<std::pair<double, double>> ranges; // Диапазоны для гистограммы

public:
    // Конструктор принимает словарь и диапазоны
    Histogram(IDictionary<std::pair<double, double>, int>& map, const std::vector<std::pair<double, double>>& r, KeyFunc extractor)
            : histogramMap(map), ranges(r), keyExtractor(extractor) {}

    void BuildHistogram(const Sequence<T>& sequence) {
        for (int i = 0; i < sequence.GetLength(); ++i) {
            T element = sequence.Get(i);
            double key = keyExtractor(element); // Извлекаем ключ из элемента

            // Находим подходящий диапазон
            for (const auto& range : ranges) {
                if (key >= range.first && key < range.second) {
                    if (histogramMap.ContainsKey(range)) {
                        int value = histogramMap.Get(range);
                        histogramMap.Remove(range);
                        histogramMap.Add(range, value + 1);
                    } else {
                        histogramMap.Add(range, 1); // Первый элемент в диапазоне
                    }
                    break; // Выходим из цикла после нахождения диапазона
                }
            }
        }
    }

    void PrintHistogram() const {
        auto items = histogramMap.GetItems();
        for (const auto& pair : items) {
            std::cout << "Range(" << pair.first.first << ", " << pair.first.second << "): " << pair.second << std::endl;
        }
    }
};
#endif //S3_LABORATORY_WORK_2_HISTOGRAM_H
