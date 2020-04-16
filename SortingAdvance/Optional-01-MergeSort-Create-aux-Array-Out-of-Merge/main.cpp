#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "MergeSort2.h"

using namespace std;

int main() {

    int n = 1000000;

    // ����1 һ���Բ���
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int* arr1 = SortTestHelper::generatorRondomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort:", mergeSort, arr1, n);
    SortTestHelper::testSort("Merge Sort 2:", mergeSort2, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;


    // ����2 ���Խ������������
    int swapTimes = 10;
    assert(swapTimes >= 0);

    cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generatorNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Merge Sort 2", mergeSort2, arr2, n);

    delete[] arr1;
    delete[] arr2;


    return 0;
}