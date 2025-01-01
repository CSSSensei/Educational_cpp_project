//            _   ___ __         __           __
//           / | / (_) /______  / /__  ____  / /______
//          /  |/ / / //_/ __ \/ / _ \/ __ \/ //_/ __ \
//         / /|  / / ,< / /_/ / /  __/ / / / ,< / /_/ /
//        /_/ |_/_/_/|_|\____/_/\___/_/ /_/_/|_|\____/
//           __ _  ___ ___  / /  (_)   (_)___(_)__
//          /  ' \/ -_) _ \/ _ \/ /   / / __/ (_-<
//         /_/_/_/\__/ .__/_//_/_/   /_/\__/_/___/
//                  /_/

#include "string"
#include "vector"
#include "interface_menu/MenuAll.h"
#include "DataStructures/SubstringAnalyzer.h"
#include "Map/HashMap.h"

int main() {
    setlocale(LC_ALL, "");
//    //menuAll();
//    HashMap<std::string, std::vector<int>> myMap;
//
//    myMap.Add("54325", std::vector<int>({1,2,3}));
//    myMap.Add("2",  std::vector<int>({1,2,3,5}));
//    myMap.Add("3",  std::vector<int>({1,2,7,8,9, 3}));
////    for (int i = 1000; i < 1020; i++){
////        myMap.Add(std::to_string(i), std::to_string(i + i * i*i));
////    }
//
//    std::cout << "Count: " << myMap.GetCount() << std::endl;
//    std::cout << "Element with key 2: " << myMap.Get("2")[3] << std::endl;
////    myMap.Print();
//
//    myMap.Remove("2");
//    std::cout << "Count after removing key 2: " << myMap.GetCount() << std::endl;

    std::string input;
    int lmin, lmax;

    // Считываем входные данные
    std::cout << "Enter the string: ";
    std::getline(std::cin, input);
    std::cout << "Enter minimum length for fixed substring search: ";
    std::cin >> lmin;
    std::cout << "Enter maximum length for fixed substring search: ";
    std::cin >> lmax;

    // Создаем экземпляр класса
    SubstringAnalyzer analyzer(input, lmin, lmax);

    // Ищем наиболее частые подстроки и выводим результаты
    auto mostFrequentResults = analyzer.findMostFrequentSubstrings();
    std::cout << "\nMost Frequent Substrings:\n";
    analyzer.printMostFrequentResults(mostFrequentResults);

    // Ищем подстроки и выводим их оценки
    auto scoreResults = analyzer.findFrequentSubstrings();
    std::cout << "\nScores of Substrings:\n";
    analyzer.printScoreResults(scoreResults);
    return 0;
}
