#include "Tests_DA and LL.h"
#include <cassert>
#include "iostream"
#include "../../Base/DynamicArray.h"
#include "../../Base/LinkedList.h"
#include "../../Base/LinkedList.cpp"

using namespace std;

float round_float(float a, int order) {
    for (int i = 0; i < order; i++) {
        a = a * 10;
    }
    a = (float) (int) a / 10;
    for (int i = 0; i < order - 1; i++) {
        a = a / 10;
    }
    return a;
}

void constructor_1_DA() {
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    assert(d.GetLength() == 5);
    assert(d.GetSize() == 10);
    assert(d.Get(3) == 4);
    d.Resize(8);
    assert(d.GetSize() == 10);
    assert(d.GetLength() == 5);
    d.Set(3, 10);
    assert(d.Get(3) == 10);
    d.Resize(0);
    assert(d.GetLength() == 0);
    assert(d.GetSize() == 0);
    d.Resize(2);
    assert(d.GetSize() == 4);
    d.Delete_DynamicArray();
}

void constructor_2_DA() {
    DynamicArray<int> arr(10);
    assert(arr.GetSize() == 20);
    assert(arr.GetLength() == 0);
    arr.Delete_DynamicArray();
}

void constructor_3_DA() {
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    DynamicArray<int> b(d);
    assert(b.GetSize() == 10);
    assert(b.GetLength() == 5);
    assert(b.Get(2) == 3);
    assert(b.Get(1) == 2);
    d.Delete_DynamicArray();
    b.Delete_DynamicArray();
}

void constructor_4_DA() {
    DynamicArray<int> arr;
    assert(arr.GetSize() == 0);
    assert(arr.GetLength() == 0);
    arr.Delete_DynamicArray();
}

void Get_DA() {
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    assert(d.Get(3) == 4);
    assert(d.Get(4) == 5);
    assert(d.Get(0) == 1);
    d.Delete_DynamicArray();
}

void GetSize_DA() {
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    assert(d.GetSize() == 10);
    d.ChangeLength(3);
    assert(d.GetLength() == 3);
    d.Delete_DynamicArray();
}

void GetLength_DA() {
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    assert(d.GetLength() == 5);
    d.Delete_DynamicArray();
}

void Set_DA() {
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    d.Set(3, 100);
    assert(d.Get(3) == 100);
    assert(d.Get(2) == 3);
    d.Delete_DynamicArray();
}

void Resize_DA() {
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    assert(d.GetSize() == 10);
    d.Resize(20);
    assert(d.GetSize() == 40);
    d.Resize(30);
    assert(d.GetSize() == 40);
    assert(d.GetLength() == 5);
    d.Resize(3);
    for (int i = 1; i < 3; i++) {
        assert(d[i - 1] == i);
    }
    assert(d.GetSize() == 6);
    d.Delete_DynamicArray();
}

void constructor_1_LL() {
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list(arr, 5);
    assert(list.GetLength() == 5);
    assert(round_float(list.Get(1), 1) == round_float(6.6, 1));
    list.Delete_LinkedList();
}

void constructor_2_LL() {
    LinkedList<float> list;
    assert(list.GetLength() == 0);
    list.Delete_LinkedList();
}

void constructor_3_LL() {
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list1(arr, 5);
    LinkedList<float> list2(list1);
    assert(list1.GetLength() == list2.GetLength());
    assert(list1.Get(3) == list2.Get(3));
    assert(list1.Get(0) == list2.Get(0));
    assert(list1.Get(2) == list2.Get(2));
    list1.Delete_LinkedList();
    list2.Delete_LinkedList();
}

void GetFirst_LL() {
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list(arr, 5);
    assert(round_float(list.GetFirst(), 2) == round_float(5.5, 2));
    list.Delete_LinkedList();
}

void GetLast_LL() {
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list(arr, 5);
    assert(round_float(list.GetLast(), 2) == round_float(0, 2));
    list.Delete_LinkedList();
}

void Get_LL() {
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list(arr, 5);
    assert(round_float(list.Get(0), 2) == round_float(5.5, 2));
    assert(round_float(list.Get(1), 2) == round_float(6.6, 2));
    assert(round_float(list.Get(3), 2) == round_float(-9.9, 2));
    list.Delete_LinkedList();
}

void GetSubList_LL() {
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list1(arr, 5);
    LinkedList<float> list2(list1.GetSubList(1, 3));
    assert(round_float(list2.Get(0), 2) == round_float(6.6, 2));
    assert(round_float(list2.Get(1), 2) == round_float(-7.8, 2));
    assert(round_float(list2.Get(2), 2) == round_float(-9.9, 2));
    assert(list2.GetLength() == 3);
    list1.Delete_LinkedList();
    list2.Delete_LinkedList();
}

void GetLength_LL() {
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list1(arr, 5);
    assert(list1.GetLength() == 5);
    list1.Delete_LinkedList();
}

void Append_LL() {
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list1(arr, 5);
    list1.Append(-10.5);
    assert(list1.GetLength() == 6);
    assert(round_float(list1.Get(5), 2) == round_float(-10.5, 2));
    assert(round_float(list1.Get(4), 2) == round_float(0, 2));
    LinkedList<int> list2;
    list2.Append(5);
    assert(list2.GetLength() == 1);
    assert(list2.Get(0) == 5);
    list1.Delete_LinkedList();
    list2.Delete_LinkedList();
}

void Prepend_LL() {
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list1(arr, 5);
    list1.Prepend(3.5);
    assert(list1.GetLength() == 6);
    assert(round_float(list1.Get(0), 2) == round_float(3.5, 2));
    assert(round_float(list1.Get(1), 2) == round_float(5.5, 2));
    LinkedList<int> list2;
    list2.Prepend(5);
    assert(list2.GetLength() == 1);
    assert(list2.Get(0) == 5);
    list1.Delete_LinkedList();
    list2.Delete_LinkedList();
}

void InsertAt() {
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list1(arr, 5);
    list1.InsertAt(4, 3);
    assert(list1.GetLength() == 6);
    assert(round_float(list1.Get(3), 2) == round_float(4, 2));
    assert(round_float(list1.Get(2), 2) == round_float(-7.8, 2));
    assert(round_float(list1.Get(4), 2) == round_float(-9.9, 2));
    list1.Delete_LinkedList();
}

void Concat() {
    float arr1[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list1(arr1, 5);
    float arr2[] = {5.5, 6.6, -7.8, -9.9, 0};
    LinkedList<float> list2(arr2, 5);
    LinkedList<float> list3(list1.Concat(&list2));
    assert(list3.GetLength() == 10);
    assert(round_float(list3.Get(5), 2) == round_float(5.5, 2));
    list1.Delete_LinkedList();
    list2.Delete_LinkedList();
    list3.Delete_LinkedList();
}

void TestsForImmutableDynArray() {

    ImmutableDynArray<int> dar11;
    dar11 = dar11.push_back(1);
    dar11 = dar11.push_back(2);
    dar11 = dar11.push_forward(0);
    assert(dar11.get_length() == 3);
    assert(dar11.get(0) == 0);
    assert(dar11.get(1) == 1);
    assert(dar11.get(2) == 2);

    ImmutableDynArray<int> dar22 = dar11.push_back(3);
    assert(dar11.get_length() == 3);
    assert(dar22.get_length() == 4);
    assert(dar22.get(0) == 0);
    assert(dar22.get(1) == 1);
    assert(dar22.get(2) == 2);
    assert(dar22.get(3) == 3);
}

void Tests_DA_LL() {
    constructor_1_DA();
    constructor_2_DA();
    constructor_3_DA();
    constructor_4_DA();
    Get_DA();
    GetSize_DA();
    GetLength_DA();
    Set_DA();
    Resize_DA();
    cout << "DynamicArray: all tests passed" << endl;

    constructor_1_LL();
    constructor_2_LL();
    constructor_3_LL();
    GetFirst_LL();
    GetLast_LL();
    Get_LL();
    GetSubList_LL();
    GetLength_LL();
    Append_LL();
    Prepend_LL();
    InsertAt();
    Concat();
    cout << "LinkedList: all tests passed" << endl;
    TestsForImmutableDynArray();
    cout << "ImmutableArray: all tests passed" << endl;
}