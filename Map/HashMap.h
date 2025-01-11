#ifndef S3_LABORATORY_WORK_2_HASHMAP_H
#define S3_LABORATORY_WORK_2_HASHMAP_H
#include <stdexcept>
#include "IDictionary.h"
#include <vector>
#include <list>
#include <utility> // для std::pair
#include <iostream>
#include <functional>

template <typename TKey, typename TElement, typename Hash = std::hash<TKey>>
class HashMap : public IDictionary<TKey, TElement> {
private:
    struct HashNode {
        TKey key;
        TElement value;
        HashNode(const TKey& k, const TElement& v) : key(k), value(v) {}
    };

    std::vector<std::list<HashNode>> table; // Список для обработки коллизий
    int count;
    int capacity;

    int HashFunction(const TKey& key) const {
        return Hash()(key) % capacity;
    }

    void ResizeTable() {
        capacity *= 2;
        std::vector<std::list<HashNode>> newTable(capacity);

        for (const auto& bucket : table) {
            for (const auto& node : bucket) {
                int newIndex = Hash()(node.key) % capacity;
                newTable[newIndex].emplace_back(node.key, node.value);
            }
        }

        table.swap(newTable);
    }

public:
    class Iterator {
    private:
        const HashMap& hashmap;
        typename std::vector<std::list<HashNode>>::const_iterator bucketIter;
        typename std::list<HashNode>::const_iterator nodeIter;

        void AdvanceToNextValid() {
            while (bucketIter != hashmap.table.end()) {
                if (nodeIter != bucketIter->end()) {
                    return; // Действительный элемент найден
                }
                // Переход к следующему
                ++bucketIter;
                if (bucketIter != hashmap.table.end()) {
                    nodeIter = bucketIter->begin(); // Переход к началу нового
                }
            }
        }

    public:
        Iterator(const HashMap& map, bool atEnd = false)
                : hashmap(map),
                  bucketIter(atEnd ? map.table.end() : map.table.begin()) {
            nodeIter = (bucketIter != hashmap.table.end()) ? bucketIter->begin() : typename std::list<HashNode>::const_iterator();
            if (!atEnd) {
                AdvanceToNextValid();
            }
        }

        bool IsValid() const {
            return bucketIter != hashmap.table.end() && nodeIter != bucketIter->end();
        }

        std::pair<TKey, TElement> operator*() const {
            if (!IsValid()) {
                throw std::runtime_error("Iterator out of bounds");
            }
            return {nodeIter->key, nodeIter->value};
        }

        Iterator& operator++() {
            if (IsValid()) {
                ++nodeIter; // Переход к следующему элементу в текущем "ведре"
                AdvanceToNextValid(); // Проверка на наличие валидного элемента
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return bucketIter != other.bucketIter || nodeIter != other.nodeIter;
        }
    };

    Iterator begin() const {
        return Iterator(*this);
    }

    Iterator end() const {
        return Iterator(*this, true);
    }

    HashMap(int initialCapacity = 10) : capacity(initialCapacity), count(0) {
        table.resize(capacity);
    }

    int GetCount() const {
        return count;
    }

    int GetCapacity() const {
        return capacity;
    }

    TElement& operator[](const TKey& key) {
        int index = HashFunction(key);
        for (auto& node : table[index]) {
            if (node.key == key) {
                return node.value;
            }
        }
        Add(key, TElement()); // Создаем новый элемент
        return (*this)[key]; // Возвращаем ссылку на новый элемент
    }

    TElement Get(const TKey& key) const {
        int index = HashFunction(key);
        for (const auto& node : table[index]) {
            if (node.key == key) {
                return node.value;
            }
        }
        throw std::runtime_error("Key not found");
    }

    bool ContainsKey(const TKey& key) const {
        int index = HashFunction(key);
        for (const auto& node : table[index]) {
            if (node.key == key) {
                return true;
            }
        }
        return false;
    }

    void Add(const TKey& key, const TElement& element) {
        if (ContainsKey(key)) {
            throw std::runtime_error("Key already exists");
        }

        if (count >= capacity) {
            ResizeTable();
        }

        int index = HashFunction(key);
        table[index].emplace_back(key, element);
        ++count;
    }

    void Remove(const TKey& key) {
        int index = HashFunction(key);
        auto& bucket = table[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                --count;
                return;
            }
        }
        throw std::runtime_error("Key not found");
    }

    std::vector<std::pair<TKey, TElement>> GetItems() override {
        std::vector<std::pair<TKey, TElement>> items;
        for (const auto& bucket : table) {
            for (const auto& node : bucket) {
                items.emplace_back(node.key, node.value);
            }
        }
        return items;
    }

    // Метод для печати содержимого HashMap
    void Print() const {
        for (int i = 0; i < table.size(); i++) {
            for (const auto& node : table[i]) {
                std::cout << "Bucket " << i << ": (" << node.key << ", " << node.value << ")\n";
            }
        }
    }
};


#endif //S3_LABORATORY_WORK_2_HASHMAP_H