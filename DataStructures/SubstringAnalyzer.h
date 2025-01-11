#ifndef S3_LABORATORY_WORK_2_SUBSTRINGANALYZER_H
#define S3_LABORATORY_WORK_2_SUBSTRINGANALYZER_H
#include <iostream>
#include <string>
#include "../Map/HashMap.h"
#include <vector>
#include <cmath>
#include <algorithm>

class SubstringAnalyzer {
private:
    std::string s; // Входная строка
    int lmin;      // Минимальная длина искомых подстрок
    int lmax;      // Максимальная длина искомых подстрок
    struct StringHash {
        size_t operator()(const std::string& key) const {
            return std::hash<std::string>()(key);
        }
    };
public:
    SubstringAnalyzer(const std::string& input, int minLength, int maxLength)
            : s(input), lmin(minLength), lmax(maxLength) {}

    // Метод для поиска наиболее частых подстрок в диапазоне [lmin, lmax]
    std::vector<std::pair<std::string, int>> findMostFrequentSubstrings() {
        HashMap<std::string, std::vector<int>, StringHash> substringMap;

        // Строим таблицу префиксов
        for (size_t i = 0; i < s.size(); ++i) {
            for (int length = lmin; length <= lmax; ++length) {
                if (i + length <= s.size()) {
                    std::string substring = s.substr(i, length);
                    substringMap[substring].push_back(i);
                }
            }
        }

        int maxOccurrences = 0;
        int cnt = 0;

        for (const auto& node : substringMap) {
            cnt++;
            if (node.second.size() > maxOccurrences) {
                maxOccurrences = node.second.size();
            }
            if (cnt >= substringMap.GetCount()){
                break;
            }
        }

        cnt = 0;
        std::vector<std::pair<std::string, int>> result;
        for (const auto& node : substringMap) {
            cnt++;
            if (node.second.size() == maxOccurrences) {
                result.emplace_back(node.first, node.second.size());
            }
            if (cnt >= substringMap.GetCount()){
                break;
            }
        }

        return result;
    }


    // Метод для оценки частоты подстрок без фиксированных длин
    std::vector<std::pair<std::string, double>> findFrequentSubstrings() {
        HashMap<std::string, int> substringMap;

        // Строим таблицу префиксов
        for (size_t i = 0; i < s.size(); ++i) {
            for (size_t length = 1; length <= s.size() - i; ++length) {
                std::string substring = s.substr(i, length);
                substringMap[substring]++;
            }
        }

        // Определяем относительные величины для каждой подстроки
        std::vector<std::pair<std::string, double>> results;
        size_t s_length = s.size(); // Длина исходной строки

        int cnt = 0;
        for (const auto& node : substringMap) {
            cnt++;
            const std::string& substring = node.first;
            int count = node.second;
            double score = (std::pow(substring.length(), 2) / std::pow(s_length, 2)) * std::pow(count, 4);
            results.emplace_back(substring, score);
            if (cnt >= substringMap.GetCount()){
                break;
            }
        }

        // Сортируем результаты по оценке в порядке убывания
        std::sort(results.begin(), results.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        return results;
    }

    std::string getMostFrequentResultsAsString(const std::vector<std::pair<std::string, int>>& results) const {
        std::string output;
        for (const auto& result : results) {
            output += "Substring: \"" + result.first + "\", Occurrences: " + std::to_string(result.second) + "\n";
        }
        return output;
    }

    std::string getScoreResultsAsString(const std::vector<std::pair<std::string, double>>& results) const {
        std::string output;
        for (const auto& result : results) {
            output += "Substring: \"" + result.first + "\", Score: " + std::to_string(result.second) + "\n";
        }
        return output;
    }

    // Метод для вывода результатов по наиболее частым подстрокам
    void printMostFrequentResults(const std::vector<std::pair<std::string, int>>& results) const {
        for (const auto& result : results) {
            std::cout << "Substring: \"" << result.first << "\", Occurrences: " << result.second << std::endl;
        }
    }

    // Метод для вывода результатов по оценке частоты
    void printScoreResults(const std::vector<std::pair<std::string, double>>& results) const {
        for (const auto& result : results) {
            std::cout << "Substring: \"" << result.first << "\", Score: " << result.second << std::endl;
        }
    }
};
#endif //S3_LABORATORY_WORK_2_SUBSTRINGANALYZER_H
