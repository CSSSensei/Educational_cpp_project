//            _   ___ __         __           __
//           / | / (_) /______  / /__  ____  / /______
//          /  |/ / / //_/ __ \/ / _ \/ __ \/ //_/ __ \
//         / /|  / / ,< / /_/ / /  __/ / / / ,< / /_/ /
//        /_/ |_/_/_/|_|\____/_/\___/_/ /_/_/|_|\____/
//           __ _  ___ ___  / /  (_)   (_)___(_)__
//          /  ' \/ -_) _ \/ _ \/ /   / / __/ (_-<
//         /_/_/_/\__/ .__/_//_/_/   /_/\__/_/___/
//                  /_/


#include "MenuMatrix.h"
#include "../Sequence_menu/MenuSequence.h"

int chooseTypeMatrix(){
    int type;
    wcout << L"Выберете тип, с которым будете работать:\n"
         << L"\t1: int\n"
         << L"\t2: float\n"
         << L"\t3: complex\n"
         << L"Введите число:";
    type = getNumberInput<int>();

    return type;
}
int chooseFunctionMatrix(){
    int func;
    wcout << L"Выберете функцию, которую нужно произвести над матрицами:\n"
         << L"\t1: Суммировать матрицы\n"
         << L"\t2: Вычесть одну матрицу из другой\n"
         << L"\t3: Умножить матрицу на скаляр\n"
         << L"\t4: Элементарное преобразование строк\n"
         << L"\t5: Элементарное преобразование столбцов\n"
         << L"\t6: Норма матрицы\n"
         << L"Введите число:";
    func = getNumberInput<int>();

    return func;
}

template<class T>
bool check_if_exist(ArraySequence<Matrix<T>> *Arr, int index) {
    if (index < 0 || index >= Arr->GetLength()) {
        if (Arr->GetLength() == 0) {
            wcout << L"Вы еще не создали ни одной матрицы!\n";
        } else {
            wcout << L"Максимальный номер вектора: " << Arr->GetLength() << '\n';
        }
        return true;
    }
    return false;
}

template<class T>
void outputTypedMatrix(ArraySequence<Matrix<T>> *Arr, int index){
    if (check_if_exist(Arr, index)){
        return;
    }
    for (int i = 0; i < Arr->GetLength(); i++){
        cout << Arr->Get(i);
    }
}
void menuMatrix(){
    auto *intArr = new ArraySequence<Matrix<int>>;
    auto *floatArr = new ArraySequence<Matrix<float>>;
    auto *complexArr = new ArraySequence<Matrix<complex<float>>>;

    int oper;
    while(true){
        wcout << L"Выберете операцию:\n"
             << L"\t1: Ввести и запомнить матрицу\n"
             << L"\t2: Выполнить операцию над матрицами\n"
             << L"\t3: Вывести матрицу в консоль\n"
             << L"\t4: Закончить выполнение программы\n"
             << L"Введите число:";
        oper = getNumberInput<int>();

        if (oper == 4)
            break;

        switch(oper){
            case 1: inputAndSaveMatrix(intArr, floatArr, complexArr); break;
            case 2: functionWithMatrix(intArr, floatArr, complexArr); break;
            case 3: outputMatrix(intArr, floatArr, complexArr); break;
            default: break;
        }
    }
}

void inputAndSaveMatrix(ArraySequence<Matrix<int>> *intArr,
                        ArraySequence<Matrix<float>> *floatArr,
                        ArraySequence<Matrix<complex<float>>> *complexArr){
    int type = chooseTypeMatrix();
    wcout << L"Введите размерность матрицы:";
    int count = getNumberInput<int>();

    switch(type){
        case 1: inputMatrixTyped(intArr, count); break;
        case 2: inputMatrixTyped(floatArr, count); break;
        case 3: inputMatrixComplex(complexArr, count); break;
        default: break;
    }
}
template <class T>
void inputMatrixTyped(ArraySequence<Matrix<T>> *Arr, int count){
    //T *arr[count];
    T **arr = new T*[count];
    wcout << L"Введем массив -> " << endl;
    for (int i = 0; i < count; i++){
        wcout << L"Введите по порядку элементы \"" << i << L"\" строки матрицы" << endl;
        T *arrcolumn = new T[count];
        for (int j = 0; j < count; j++){
            arrcolumn[j] = getNumberInput<T>();;
        }
        arr[i] = arrcolumn;
    }

    Matrix<T> n_matrix(arr, count);
    Arr->Append(n_matrix);
}

void inputMatrixComplex(ArraySequence<Matrix<complex<float>>> *Arr, int count) {
    auto **arr = new complex<float>*[count];
    wcout << L"Введем массив -> " << endl;
    for (int i = 0; i < count; i++){
        auto *arrcolumn = new complex<float>[count];
        for (int j = 0; j < count; j++){
            float realPart, imagPart;
            wcout << L"Строка [" << i<< L"] колонка ["  <<j <<L"]. Введите действительную часть:";
            realPart = getNumberInput<float>();
            wcout << L"Введите мнимую часть:";
            imagPart = getNumberInput<float>();
            arrcolumn[j] = complex<float>(realPart, imagPart);
        }
        arr[i] = arrcolumn;
    }
    Matrix<complex<float>> n_matrix(arr, count);
    Arr->Append(n_matrix);
}


void functionWithMatrix(ArraySequence<Matrix<int>> *intArr,
                        ArraySequence<Matrix<float>> *floatArr,
                        ArraySequence<Matrix<complex<float>>> *complexArr){
    int type = chooseTypeMatrix();

    switch(type){
        case 1: functionMatrixTyped(intArr); break;
        case 2: functionMatrixTyped(floatArr); break;
        case 3: functionMatrixTyped(complexArr); break;
        default: break;
    }
}

template<class T>
void functionMatrixTyped(ArraySequence<Matrix<T>> *Arr){
    int func = chooseFunctionMatrix();
    int len = Arr->GetLength();
    int indexOfArr1 = -1;
    int indexOfArr2 = -1;

    if (func == 3 || func == 4 || func == 5 || func == 6){
        wcout << L"В памяти находится \""<< len << L"\" матриц" << endl;
        wcout <<  L"Выберете индекс матрицы, с которой хотите работать:";
        indexOfArr1 = getNumberInput<int>();
        if (indexOfArr1 >= len || indexOfArr1 < 0){
            wcout <<  L"Матрицы с таким индексом нет в памяти!" << endl;
            func = -1;
        }
    }else{
        wcout << L"В памяти находится \""<< len << L"\" матриц" << endl;
        wcout <<  L"Выберете индексы матриц, с которыми хотите работать:";
        indexOfArr1 = getNumberInput<int>();
        indexOfArr2 = getNumberInput<int>();
        if (indexOfArr1 >= len || indexOfArr1 < 0 || indexOfArr2 >= len || indexOfArr2 < 0){
            wcout <<  L"Матрицы с таким индексом нет в памяти!" << endl;
            func = -1;
        }
    }

    int size = Arr->Get(indexOfArr1).GetSize();

    T scalar;
    int line1, line2, column1, column2, problem = 0;
    switch(func){
        default:
            break;
        case 1:
            if (Arr->Get(indexOfArr1).GetSize() != Arr->Get(indexOfArr2).GetSize()){
                wcout <<  L"Нельзя складывать матрицы разных размерностей!!!" << endl;
                problem = 1;
                break;
            }
            Arr->Append(Arr->Get(indexOfArr1).SumOfMatrix(Arr->Get(indexOfArr2)));
            break;
        case 2:
            if (Arr->Get(indexOfArr1).GetSize() != Arr->Get(indexOfArr2).GetSize()){
                wcout <<  L"Нельзя складывать матрицы разных размерностей!!!" << endl;
                problem = 1;
                break;
            }
            Arr->Append(Arr->Get(indexOfArr1).SubOfMatrix(Arr->Get(indexOfArr2)));
            break;
        case 3:
            wcout <<  L"Введите скаляр, на который будете умножать:";
            scalar = getNumberInput<float>();
            Arr->Append(Arr->Get(indexOfArr1).MultOfMatrix(scalar));
            break;
        case 4:
            wcout <<  L"Введите скаляр, на который будете умножать строку:";
            scalar = getNumberInput<float>();
            wcout <<  L"Матрица состоит из \"" << size << L"\" строк и столбцов" << endl;
            wcout <<  L"Введите индекс строки, которую нужно умножить на скаляр:";
            line2 = getNumberInput<int>();
            wcout <<  L"Введите индекс строки, к которой нужно прибавить другую строку, умноженную на скаляр:";
            line1 = getNumberInput<int>();
            Arr->Get(indexOfArr1).ElemTransformOfLines(line1, line2, scalar);
            Arr->Append(Arr->Get(indexOfArr1));
            break;
        case 5:
            wcout <<  L"Введите скаляр, на который будете умножать столбец:";
            scalar = getNumberInput<float>();
            wcout <<  L"Матрица состоит из \"" << size << L"\" строк и столбцов" << endl;
            wcout <<  L"Введите индекс столбца, который нужно умножить на скаляр:";
            column2 = getNumberInput<int>();
            wcout <<  L"Введите индекс столбца, к которому нужно прибавить другую строку умноженную на скаляр:";
            column1 = getNumberInput<int>();
            Arr->Get(indexOfArr1).ElemTransformOfColumns(column1, column2, scalar);
            Arr->Append(Arr->Get(indexOfArr1));
        case 6:
            wcout << L"Норма матрицы: " << Arr->Get(indexOfArr1).NormOfMatrix() << endl;

    }//результат записывается в последнюю ячейку памяти массива

    if (problem != 1){
        Matrix<T> resultMatrix (Arr->Get(Arr->GetLength() - 1));
        cout << resultMatrix << endl;
    }
}

void outputMatrix(ArraySequence<Matrix<int>> *intArr,
                  ArraySequence<Matrix<float>> *floatArr,
                  ArraySequence<Matrix<complex<float>>> *complexArr){

    int type = chooseTypeMatrix();
    int index;

    switch (type){
        case 1: outputTypedMatrix(intArr, index=0); break;
        case 2: outputTypedMatrix(floatArr, index=0); break;
        case 3: outputTypedMatrix(complexArr, index=0); break;
        default: break;
    }
}

