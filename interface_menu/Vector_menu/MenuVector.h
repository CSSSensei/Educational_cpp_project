#ifndef LABORATORY_WORK_2_MENUVECTOR_H
#define LABORATORY_WORK_2_MENUVECTOR_H
#include <iostream>
#include "../../DataStructures/Vector.h"
#include <complex>

using namespace std;

int chooseType();
template<class T>
bool check_if_exist(ArraySequence<Vector<T>> *Arr, int index);
void inputComplexNumber(ArraySequence<Vector<complex<float>>> *Arr, int count);
int chooseFunction();
template<class T>
void saveVector(ArraySequence<Vector<T>> *Arr, Vector<T> *n_vector);

void menuVector();
//1
void inputAndSaveVector(ArraySequence<Vector<int>> *intArr,
                        ArraySequence<Vector<float>> *floatArr,
                        ArraySequence<Vector<complex<float>>> *complexArr);
template <class T>
void inputVectorTyped(ArraySequence<Vector<T>> *Arr, int count);
//2
void functionWithVector(ArraySequence<Vector<int>> *intArr,
                         ArraySequence<Vector<float>> *floatArr,
                         ArraySequence<Vector<complex<float>>> *complexArr);
template<class T>
void functionVectorTyped(ArraySequence<Vector<T>> *Arr);

//3
void outputVector(ArraySequence<Vector<int>> *intArr,
                  ArraySequence<Vector<float>> *floatArr,
                  ArraySequence<Vector<complex<float>>> *complexArr);

template<class T>
void outputTypedVector(ArraySequence<Vector<T>> *Arr, int index);




#endif //LABORATORY_WORK_2_MENUVECTOR_H
