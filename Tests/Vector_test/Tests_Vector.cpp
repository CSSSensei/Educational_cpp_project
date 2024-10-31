#include "Tests_Vector.h"

#include <iostream>
#include <complex>
#include <cassert>
#include "../../Sequence/ArraySequence.h"
#include "../../DataStructures/Vector.h"

void testVectorInitialization() {

    ArraySequence<float> arrSeq;
    arrSeq.Append(1.0);
    arrSeq.Append(2.0);
    arrSeq.Append(3.0);

    Vector<float> vector(arrSeq);

    assert(vector.GetCoord(0) == 1.0);
    assert(vector.GetCoord(1) == 2.0);
    assert(vector.GetCoord(2) == 3.0);


}

void testNormalization() {
    ArraySequence<std::complex<float>> arrSeq;
    arrSeq.Append(std::complex<float>(3.0, 4.0));
    arrSeq.Append(std::complex<float>(5.0, 12.0));
    arrSeq.Append(std::complex<float>(8.0, -15.0));
    arrSeq.Append(std::complex<float>(22.72578, 2.11214));

    Vector<std::complex<float>> complex_vector(arrSeq);
    Vector<std::complex<float>> normalized_vector = complex_vector.Normalization();

    //std::cout << "Normalized Vector: " << normalized_vector << std::endl;

    assert(std::abs(std::real(normalized_vector.GetCoord(0)) - 0.0946) < 1e-4);

    assert(std::abs(std::imag(normalized_vector.GetCoord(0)) - 0.1262) < 1e-4);

    assert(std::abs(std::real(normalized_vector.GetCoord(1)) - 0.1578) < 1e-4);

    assert(std::abs(std::imag(normalized_vector.GetCoord(1)) - 0.3787) < 1e-4);

    assert(std::abs(std::real(normalized_vector.GetCoord(2)) - 0.2524) < 1e-4);

    assert(std::abs(std::imag(normalized_vector.GetCoord(2)) - (-0.4734)) < 1e-4);

    assert(std::abs(std::real(normalized_vector.GetCoord(3)) - 0.7172) < 1e-4);

    assert(std::abs(std::imag(normalized_vector.GetCoord(3)) - 0.0666) < 1e-4);

}

void testNorm() {
    // Test for integer type
    {

        int arr[2]{3, 4};
        ArraySequence<int> arrSeq(arr, 2);
        Vector<int> intVector(arrSeq);
        assert(intVector.Norm() == 5);
        intVector.Delete_Vector();
    }

    // Test for double type
    {
        ArraySequence<float> arrSeq2;
        arrSeq2.Append(2.0);
        arrSeq2.Append(3.0);
        Vector<float> floatVector(arrSeq2);
        assert(floatVector.Norm() - 3.60555 < 1e-4);
    }

    // Test for complex<double> type
    {
        ArraySequence<std::complex<float>> arrSeq3;
        arrSeq3.Append({2.0, 3.0});
        arrSeq3.Append({4.0, 1.0});
        Vector<std::complex<float>> complexVector(arrSeq3);
        assert(complexVector.Norm() - 5.4772 < 1e-4);
        complexVector.Delete_Vector();
    }
}

void testSumOfVectors() {
    ArraySequence<float> arrSeq;
    arrSeq.Append(1.0);
    arrSeq.Append(2.0);
    Vector<float> vector1(arrSeq);
    ArraySequence<float> arrSeq2;
    arrSeq2.Append(3.0);
    arrSeq2.Append(4.0);
    Vector<float> vector2(arrSeq2);
    Vector<float> sum_vector = vector1.SumOfVectors(vector2);
    // Test the sum of vectors
    assert(sum_vector.GetCoord(0) == 4.0);
    assert(sum_vector.GetCoord(1) == 6.0);

}

void testVector() {
    testVectorInitialization();
    testNormalization();
    testSumOfVectors();
    testNorm();
    std::cout << "Vector: all tests passed!\n";
}