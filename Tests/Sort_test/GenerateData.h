//
// Created by tomin on 22.10.2024.
//

#ifndef S3_LABORATORY_WORK_2_GENERATEDATA_H
#define S3_LABORATORY_WORK_2_GENERATEDATA_H
#include <fstream>
#include <cstdlib>
#include <ctime>

void GenerateTestData(const std::string& filename, int numberOfRecords) {
    std::ofstream file(filename);
    std::srand(std::time(0)); // инициализация генератора случайных чисел

    for (int i = 0; i < numberOfRecords; ++i) {
        std::string firstName = "Name" + std::to_string(i);
        std::string lastName = "Surname" + std::to_string(i);
        int birthYear = 1900 + std::rand() % 123; // Возраст от 0 до 122
        double height = 150.0 + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX/(200.0 - 150.0)));
        double weight = 50.0 + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX/(150.0 - 50.0)));

        file << firstName << "," << lastName << "," << birthYear << "," << height << "," << weight << "\n";
    }
    file.close();
}

#endif //S3_LABORATORY_WORK_2_GENERATEDATA_H
