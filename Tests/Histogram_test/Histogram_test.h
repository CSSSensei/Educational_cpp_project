#ifndef S3_LABORATORY_WORK_2_HISTOGRAM_TEST_H
#define S3_LABORATORY_WORK_2_HISTOGRAM_TEST_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <random>


class Human {
public:
    std::string name;
    int age;

    Human() : name(""), age(0) {}

    Human(const std::string& n, int a) : name(n), age(a) {}

    const std::string& GetName() const { return name; }
    int GetAge() const { return age; }
};

struct PairHash {
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U>& pair) const {
        auto hash1 = std::hash<T>{}(pair.first);
        auto hash2 = std::hash<U>{}(pair.second);
        return hash1 ^ (hash2 << 1); // Применение XOR и побитового сдвига для комбинирования хешей
    }
};

double AgeExtractor(const Human& p) {
    return static_cast<double>(p.GetAge());
}

std::string GenerateRandomName() {
    const std::vector<std::string> names = {
            "Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Helen"
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, names.size() - 1);

    return names[dis(gen)];
}

int GenerateRandomAge(int min_age, int max_age) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min_age, max_age);

    return dis(gen);
}

void GenerateData(const std::string& filename, int numberOfEntries) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Ошибка открытия файла для записи!" << std::endl;
        return;
    }

    for (int i = 0; i < numberOfEntries; ++i) {
        std::string name = GenerateRandomName();
        int age = GenerateRandomAge(0, 100);
        outFile << name << " " << age << std::endl;
    }

    outFile.close();
}

std::vector<Human> ReadData(const std::string& filename) {
    std::ifstream inFile(filename);
    std::vector<Human> people;
    std::string name;
    int age;

    if (!inFile) {
        std::cerr << "Ошибка открытия файла для чтения!" << std::endl;
        return people;
    }

    while (inFile >> name >> age) {
        people.emplace_back(name, age);
    }
    inFile.close();
    return people;
}

#endif //S3_LABORATORY_WORK_2_HISTOGRAM_TEST_H
