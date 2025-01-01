#ifndef S3_LABORATORY_WORK_2_HISTOGRAM_H
#define S3_LABORATORY_WORK_2_HISTOGRAM_H

#include <memory>
#include "../Map/IDictionary.h"
#include "../Map/HashMap.h"
#include "../pointers/UnqPtr.h"

template <typename KeyType>
class Histogram {
private:
    std::unique_ptr<IDictionary<KeyType, int>> dictionary;

public:
    Histogram(std::unique_ptr<IDictionary<KeyType, int>> dict)
            : dictionary(std::move(dict)) {}

    void add(const KeyType& key) {
        if (dictionary->contains(key)) {
            int currentCount = dictionary->get(key);
            dictionary->insert(key, currentCount + 1);
        } else {
            dictionary->insert(key, 1);
        }
    }

    void print() const {
        for (const auto& pair : dynamic_cast<decltype(dynamic_cast<HashMap<KeyType, int>*>(dictionary.get()))>(dictionary.get())->map) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }

    void clear() {
        dictionary->clear();
    }
};
#endif //S3_LABORATORY_WORK_2_HISTOGRAM_H
