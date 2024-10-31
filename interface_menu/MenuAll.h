//            _   ___ __         __           __
//           / | / (_) /______  / /__  ____  / /______
//          /  |/ / / //_/ __ \/ / _ \/ __ \/ //_/ __ \
//         / /|  / / ,< / /_/ / /  __/ / / / ,< / /_/ /
//        /_/ |_/_/_/|_|\____/_/\___/_/ /_/_/|_|\____/
//           __ _  ___ ___  / /  (_)   (_)___(_)__
//          /  ' \/ -_) _ \/ _ \/ /   / / __/ (_-<
//         /_/_/_/\__/ .__/_//_/_/   /_/\__/_/___/
//                  /_/


#ifndef LABORATORY_WORK_2_MENUALL_H
#define LABORATORY_WORK_2_MENUALL_H
#include "Matrix_menu/MenuMatrix.h"
#include "Vector_menu/MenuVector.h"
#include "../Tests/Matrix_test/Tests_Matrix.h"
#include "../Tests/Vector_test/Tests_Vector.h"
#include "../Tests/DA_LL_test/Tests_DA and LL.h"
#include "../Tests/AS_LLS_test/Tests_AS and LLS.h"
#include "Sequence_menu/MenuSequence.h"
#include "../Tests/Sort_test/SortTest.h"
#include "../Tests/Sort_test/LoadTests.h"

void menuAll() {
    int var;
    wcout << L"Выберете вариант, с которым будете работать\n"
          << L"\t1: Sequences\n"
          << L"\t2: Вектор\n"
          << L"\t3: Матрица\n"
          << L"\t4: Тесты\n"
          << L"\t5: Тесты сортировок\n"
          << L"Введите число:";
    var = getNumberInput<int>();

    switch (var) {
        case 1:
            menu_sequence();
            break;
        case 2: {
            menuVector();
            break;
        }
        case 3: {
            menuMatrix();
            break;
        }
        case 4: {
            constructors_AS();
            decomposition_AS();
            function_AS();
            constructors_LLS();
            decomposition_LLS();
            function_LLS();
            Tests_DA_LL();
            testVector();
            testMatrix();
            menuAll();
            break;
        }
        case 5:
            test_sort_main();
            loadtestsort_main();
            menuAll();
            break;
        default:
            break;
    }
}

#endif //LABORATORY_WORK_2_MENUALL_H
