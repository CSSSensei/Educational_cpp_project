//
// Created by tomin on 22.10.2024.
//

#ifndef S3_LABORATORY_WORK_2_LOADTESTS_H
#define S3_LABORATORY_WORK_2_LOADTESTS_H
#include <string>
#include <chrono>
#include <utility>
#include <vector>
#include <fstream>
#include "GenerateData.h"
#include "../../Sort/ISorter.h"
#include "../../Sort/BubbleSort.h"
#include "../../Sort/BatcherSort.h"
#include "../../Sort/QuickSort.h"
#include "../../Sort/SelectionSort.h"
#include "sstream"
#include "../../Sequence/ArraySequence.h"

struct Person {
    std::string firstName;
    std::string lastName;
    int birthYear;
    double height; // в сантиметрах
    double weight; // в килограммах
    Person() : firstName(""), lastName(""), birthYear(0), height(0.0), weight(0.0) {}
    Person(std::string  fName, std::string  lName, int bYear, double h, double w)
            : firstName(std::move(fName)), lastName(std::move(lName)), birthYear(bYear), height(h), weight(w) {}
};
int compareByBirthYear(const Person a, const Person b) {
    return (a.weight >= b.weight) - (a.weight <= b.weight); // Общая сортировка по возрастанию
}

ArraySequence<Person> ReadTestData(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    ArraySequence<Person> people;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string firstName, lastName;
        int birthYear;
        double height, weight;

        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        ss >> birthYear;
        ss.ignore();  // Игнорируем запятую
        ss >> height;
        ss.ignore();  // Игнорируем запятую
        ss >> weight;

        people.Append(Person(firstName, lastName, birthYear, height, weight));
    }
    return people;
}//Qt Creator

template<typename T, typename Sorter>
double MeasureSortTime(ArraySequence<T>& data, Sorter& sorter) {
    auto start = std::chrono::high_resolution_clock::now();
    sorter.Sort(&data, compareByBirthYear);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;
    return diff.count();
}

void loadtestsort_main() {
    // Генерация тестовых данных
    std::vector<int> dataSizes = {1000, 10000, 20000, 30000, 50000, 75000, 100000, 200000, 300000};

    // Запись результатов в файл
    std::ofstream resultFile("C:/Users/tomin/PycharmProjects/pythonProject/results.csv");
    if (!resultFile.is_open()) {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;
    }

    resultFile << "Data Size,Sorter Name,Time (seconds)\n";

    for (int size : dataSizes) {
        GenerateTestData("test_data.csv", size);
        ArraySequence<Person> people = ReadTestData("test_data.csv");

        std::vector<std::pair<std::string, ISorter<Person> *>> sorters = {
                {"Quick Sort", new QuickSort<Person>()},
                {"Batcher Sort", new BatcherSort<Person>()},
                {"Bubble Sort", new BubbleSorter<Person>()},
                {"Selection Sort", new SelectionSorter<Person>()}
        };

        std::cout << "___ Size test: " << size << " ___\n";
        for (const auto &[name, sorter]: sorters) { // структурное связывание
            if (( name == "Selection Sort" && size > 30000) || (name == "Bubble Sort" && size > 20000)) continue;

            ArraySequence<Person> dataCopy = people;
            double time = MeasureSortTime(dataCopy, *sorter);
            std::cout << name << " Time: " << time << " seconds\n";

            resultFile << size << "," << name << "," << time << "\n";
            delete sorter;
        }
    }

    resultFile.close();
}

#endif //S3_LABORATORY_WORK_2_LOADTESTS_H
