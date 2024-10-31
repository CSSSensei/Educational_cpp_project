#include "Tests_Matrix.h"
#include <iostream>
#include <complex>
#include <cassert>
#include "../../DataStructures/Matrix.h"

void testMatrixInitialization() {
    auto **arr = new float*[2];
    for (int i = 0; i < 2; i++) {
        arr[i] = new float[2];
    }

    arr[0][0] = 1.0; arr[0][1] = 2.0;
    arr[1][0] = 3.0; arr[1][1] = 4.0;

    Matrix<float> matrix(arr, 2);
    assert(matrix.Get(0, 0) == 1.0);
    assert(matrix.Get(0, 1) == 2.0);
    assert(matrix.Get(1, 0) == 3.0);
    assert(matrix.Get(1, 1) == 4.0);

    for (int i = 0; i < 2; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void testNormOfMatrix() {
    auto **arr = new std::complex<float>*[2];
    for (int i = 0; i < 2; i++) {
        arr[i] = new std::complex<float>[2];
    }
    arr[0][0] = std::complex<float>(3.0, 4.0); arr[0][1] = std::complex<float>(5.0, 12.0);
    arr[1][0] = std::complex<float>(8.0, -15.0); arr[1][1] = std::complex<float>(22.72578, 2.11214);
    Matrix<std::complex<float>> complex_matrix(arr, 2);
    float norm = complex_matrix.NormOfMatrix();
    assert(abs(norm - 31.6847) < 1e-4);
}


void testMatrix() {
    testMatrixInitialization();
    testNormOfMatrix();
    std::cout << "Matrix: all tests passed!\n";
}