cmake_minimum_required(VERSION 3.17)
project(S3_laboratory_work_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(S3_laboratory_work_2
        main.cpp
        "Tests/DA_LL_test/Tests_DA and LL.h"
        "Tests/DA_LL_test/Tests_DA and LL.cpp"
        "Tests/AS_LLS_test/Tests_AS and LLS.h"
        DataStructures/Vector.h
        "Tests/AS_LLS_test/Tests_AS and LLS.cpp"
        base/DynamicArray.h
        Sequence/ArraySequence.h
        base/LinkedList.h
        interface_menu/Vector_menu/MenuVector.h
        interface_menu/Vector_menu/MenuVector.cpp
        interface_menu/Matrix_menu/MenuMatrix.h
        interface_menu/Matrix_menu/MenuMatrix.cpp
        interface_menu/MenuAll.h
        Sequence/LinkedListSequence.h
        Base/LinkedList.h
        Base/LinkedList.cpp
        interface_menu/Sequence_menu/MenuSequence.h
        interface_menu/Sequence_menu/MenuSequence.cpp
        Tests/Vector_test/Tests_Vector.h
        Tests/Matrix_test/Tests_Matrix.h
        Tests/Vector_test/Tests_Vector.cpp
        Tests/Matrix_test/Tests_Matrix.cpp
        pointers/ShrdPtr.h
        pointers/Counter.h
        pointers/UnqPtr.h
        Sort/ISorter.h
        Sort/BubbleSort.h
        Sort/BatcherSort.h
        Sort/QuickSort.h
        Sort/SelectionSort.h
        Tests/Sort_test/SortTest.h
        interface_menu/Sort_menu/MenuSort.h
        Tests/Sort_test/LoadTests.h
        Tests/Sort_test/GenerateData.h
        Map/HashMap.h
        Map/IDictionary.h
        DataStructures/SubstringAnalyzer.h
        DataStructures/Histogram.h
        Tests/Histogram_test/Histogram_test.h
)