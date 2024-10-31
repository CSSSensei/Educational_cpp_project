#include "MenuVector.h"
#include "../Sequence_menu/MenuSequence.h"

int chooseType() {
    int type = 0;
    while (type < 1 || type > 3) {

        wcout << L"Выберете тип, с которым будете работать:\n"
              << L"\t1: int\n"
              << L"\t2: float\n"
              << L"\t3: complex\n"
              << L"Введите число:";
        type = getNumberInput<int>();
    }
    return type;
}

int chooseFunctionVector() {
    int func;
    wcout << L"Выберете функцию, которую нужно произвести над векторами:\n"
          << L"\t1: Суммировать вектора\n"
          << L"\t2: Вычесть один вектор из другого\n"
          << L"\t3: Умножить вектор на скаляр\n"
          << L"\t4: Нормализовать вектор\n"//
          << L"\t5: Скалярное умножение векторов\n"
          << L"\t6: Норма вектора\n"
          << L"Введите число:";
    func = getNumberInput<int>();

    return func;
}

template<class T>
void saveVector(ArraySequence<Vector<T>> *Arr, Vector<T> *n_vector) {
    Arr->Append(n_vector);
}

template<class T>
bool check_if_exist(ArraySequence<Vector<T>> *Arr, int index){
    if (index < 0 || index >= Arr->GetLength()) {
        //wcout << L"Такого вектора нет в списке\n";
        if (Arr->GetLength() == 0) {
            wcout << L"Вы еще не создали ни одного вектора!\n";
        } else {
            wcout << L"Максимальный номер вектора:" << Arr->GetLength() << '\n';
        }
        return true;
    }
    return false;
}

template<class T>
void outputTypedVector(ArraySequence<Vector<T>> *Arr, int index) {
    if (check_if_exist(Arr, index)){
        return;
    }
    for (int i = 0; i < Arr->GetLength(); i++){
        std::cout << Arr->Get(i) << '\n';
    }
    std::cout << '\n';
}

void menuVector() {
    auto *intArr = new ArraySequence<Vector<int>>;
    auto *floatArr = new ArraySequence<Vector<float>>;
    auto *complexArr = new ArraySequence<Vector<complex<float>>>;

    int oper;
    while (true) {
        wcout << L"Выберете операцию:\n"
              << L"\t1: Ввести и запомнить вектор\n"
              << L"\t2: Выполнить операцию над векторами\n"
              << L"\t3: Вывести вектор в консоль\n"
              << L"\t4: Закончить выполнение программы\n"
              << L"Введите число:";
        oper = getNumberInput<int>();

        if (oper == 4)
            break;

        switch (oper) {
            case 1:
                inputAndSaveVector(intArr, floatArr, complexArr);
                break;
            case 2:
                functionWithVector(intArr, floatArr, complexArr);
                break;
            case 3:
                outputVector(intArr, floatArr, complexArr);
                break;
            default:
                break;
        }
    }
}

void inputAndSaveVector(ArraySequence<Vector<int>> *intArr,
                        ArraySequence<Vector<float>> *floatArr,
                        ArraySequence<Vector<complex<float>>> *complexArr) {

    int type = chooseType();
    int count;
    wcout << L"Введите размерность вектора:";
    count = getNumberInput<int>();

    switch (type) {
        case 1:
            inputVectorTyped(intArr, count);
            break;
        case 2:
            inputVectorTyped(floatArr, count);
            break;
        case 3:
            inputComplexNumber(complexArr, count);
            break;
        default:
            break;
    }
}


void inputComplexNumber(ArraySequence<Vector<complex<float>>> *Arr, int count) {
    wcout << L"Введите координаты вектора по порядку ";
    ArraySequence<complex<float>> n_arr;
    for (int i = 0; i < count; i++) {

        float realPart, imagPart;
        wcout << L"Координата " << i <<L". Введите действительную часть ";
        realPart = getNumberInput<float>();
        wcout << L"Координата " << i << L" Введите мнимую часть";
        imagPart = getNumberInput<float>();

        complex<float> complexNum = complex<float>(realPart, imagPart);
        n_arr.Append(complexNum);
    }
    Vector<complex<float>> n_vector(n_arr);
    Arr->Append(n_vector);
}

template<class T>
void inputVectorTyped(ArraySequence<Vector<T>> *Arr, int count) {
    wcout << L"Введите координаты вектора по порядку ";
    ArraySequence<T> n_arr;
    T item;
    for (int i = 0; i < count; i++) {
        item = getNumberInput<T>();
        n_arr.Append(item);
    }
    Vector<T> n_vector(n_arr);
    Arr->Append(n_vector);
}

void functionWithVector(ArraySequence<Vector<int>> *intArr,
                        ArraySequence<Vector<float>> *floatArr,
                        ArraySequence<Vector<complex<float>>> *complexArr) {

    int type = chooseType();

    switch (type) {
        case 1:
            functionVectorTyped(intArr);
            break;
        case 2:
            functionVectorTyped(floatArr);
            break;
        case 3:
            functionVectorTyped(complexArr);
            break;
        default:
            break;
    }
}

template<class T>
void functionVectorTyped(ArraySequence<Vector<T>> *Arr) {
    int func = chooseFunctionVector();
    int len = Arr->GetLength();
    if (len == 0){
        wcout << L"В памяти находится \"" << len << L"\" векторов" << endl;
        return;
    }
    int indexOfArr1 = -1;
    int indexOfArr2 = -1;

    if (func == 3 || func == 4 || func == 6) {
        wcout << L"В памяти находится \"" << len << L"\" векторов" << endl;
        wcout << L"Выберете индекс вектора, с которым хотите работать:";
        indexOfArr1 = getNumberInput<int>();
        if (indexOfArr1 >= len || indexOfArr1 < 0) {
            wcout << L"Вектора с таким индексом нет в памяти!" << endl;
            func = -1;
            return;
        }
    } else {
        wcout << L"В памяти находится \"" << len << L"\" векторов" << endl;
        wcout << L"Выберете индексы векторов, с которыми хотите работать:";
        indexOfArr1 = getNumberInput<int>();
        indexOfArr2 = getNumberInput<int>();
        if (indexOfArr1 >= len || indexOfArr1 < 0 || indexOfArr2 >= len || indexOfArr2 < 0) {
            wcout << L"Вектора с таким индексом нет в памяти!" << endl;
            func = -1;
            return;
        }
    }

    T scalar;
    switch (func) {
        default:
            break;
        case 1:
            Arr->Append(Arr->Get(indexOfArr1).SumOfVectors(Arr->Get(indexOfArr2)));
            break;
        case 2:
            Arr->Append(Arr->Get(indexOfArr1).SubOfVectors(Arr->Get(indexOfArr2)));
            break;
        case 3:
            wcout << L"Введите скаляр, на который будете умножать:";
            scalar = getNumberInput<double>();
            Arr->Append(Arr->Get(indexOfArr1).MulOfVectors(scalar));
            break;
        case 4:
            Arr->Append(Arr->Get(indexOfArr1).Normalization());
            break;
        case 5: {
            T result;
            result = Arr->Get(indexOfArr1).ScalarMulOfVectors(Arr->Get(indexOfArr2));
            wcout << L"А вот и результат умножения:" << result << endl;
            break;
        }
        case 6: {
            wcout << L"Норма вектора: " << Arr->Get(indexOfArr1).Norm() << endl;
            break;
        }

    }//результат записывается в последнюю ячейку памяти массива

    if (func != 5 && func != 6) {
        Vector<T> resultVector(Arr->Get(Arr->GetLength() - 1));
        cout << resultVector << endl;
    }
}

void outputVector(ArraySequence<Vector<int>> *intArr,
                  ArraySequence<Vector<float>> *floatArr,
                  ArraySequence<Vector<complex<float>>> *complexArr) {

    int type = chooseType();
    int index;

    switch (type) {
        case 1:
            outputTypedVector(intArr, index = 0);
            break;
        case 2:
            outputTypedVector(floatArr, index = 0);
            break;
        case 3:
            outputTypedVector(complexArr, index = 0);
            break;
        default:
            break;
    }

}

