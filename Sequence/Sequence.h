//            _   ___ __         __           __
//           / | / (_) /______  / /__  ____  / /______
//          /  |/ / / //_/ __ \/ / _ \/ __ \/ //_/ __ \
//         / /|  / / ,< / /_/ / /  __/ / / / ,< / /_/ /
//        /_/ |_/_/_/|_|\____/_/\___/_/ /_/_/|_|\____/
//           __ _  ___ ___  / /  (_)   (_)___(_)__
//          /  ' \/ -_) _ \/ _ \/ /   / / __/ (_-<
//         /_/_/_/\__/ .__/_//_/_/   /_/\__/_/___/
//                  /_/


#ifndef S3_LABORATORY_WORK_2_SEQUENCE_H
#define S3_LABORATORY_WORK_2_SEQUENCE_H

#include <iostream>

template<class T>
class Sequence {
public:
    // Декомпозиция
    virtual T GetFirst() const = 0;  // Получение первого элемента
    virtual T GetLast() const = 0;  // Получение последнего элемента
    virtual T &Get(int index) const = 0;  // Получение элемента по индексу
    virtual Sequence<T> *GetSubsequence(int startIndex, int endIndex) const = 0; //Получене списка элемента по индексам
    virtual int GetLength() const = 0;  // Получение длины последовательности
    // Операции
    virtual T Pop() = 0;  // Удаляет последний элемент в последовательности и возвращает его
    virtual void Remove(int, int) = 0;  // Удаляет элементы начиная с первого до второго включительно
    virtual void Append(T item) = 0;  // Добавление элемента в конец последовательности
    virtual void Prepend(T item) = 0;  // Добавление элемента в начало последовательности
    virtual void InsertAt(T item, int index) = 0;  // Вставка элемента в заданную позицию последовательности
    virtual void Set(int index, T item) = 0;

    virtual Sequence<T> *Concat(Sequence<T> *list) = 0; // Сцепление двух последовательностей
};


#endif //S3_LABORATORY_WORK_2_SEQUENCE_H
