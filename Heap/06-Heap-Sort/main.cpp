#include<iostream>
#include<ctime>
#include<algorithm>
#include"HeapSort.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"QuickSort2Ways.h"
#include"QuickSort3Ways.h"
#include"SortTestHelper.h"

using namespace std;

//ԭʼ��shiftDown����
template<typename T>
void _shiftDown(T arr[], int n, int k) {
	while (2 * k + 1 < n) {
		int j = 2 * k;
		if (j + 1 < n && arr[j + 1] > arr[j]) j += 1;
		if (arr[k] >= arr[j]) break;

		swap(arr[k], arr[j]);
		k = j;
	}
}
// �Ż���shiftDown����, ʹ�ø�ֵ�ķ�ʽȡ�����ϵ�swap,
// ���Ż�˼�������֮ǰ�Բ�����������Ż���˼·��һ�µ�
template<typename T>
void _shiftDown2(T arr[], int n, int k) {
	T e = arr[k];
	while (2 * k + 1 < n) {
		int j = 2 * k;
		if (j + 1 < n && arr[j + 1] > arr[j]) j += 1;
		if (e >= arr[j])break;

		arr[k] = arr[j];
		k = j;
	}
	arr[k] = e;
}

// ��ʹ��һ�����������, ֱ����ԭ�����Ͻ���ԭ�صĶ�����
template<typename T>
void heapSort(T arr[], int n) {
	// ע�⣬��ʱ���ǵĶ��Ǵ�0��ʼ������
   // ��(���һ��Ԫ�ص�����-1)/2��ʼ
   // ���һ��Ԫ�ص����� = n-1
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	_shiftDown2(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		_shiftDown2(arr, i, 0);
	}
}
int main() {
    int n = 1000000;

    // ����1 һ���Բ���
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int* arr1 = SortTestHelper::generatorRondomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    int* arr4 = SortTestHelper::copyIntArray(arr1, n);
    int* arr5 = SortTestHelper::copyIntArray(arr1, n);
    int* arr6 = SortTestHelper::copyIntArray(arr1, n);
    int* arr7 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Way, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Way, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    cout << endl;


    // ����2 ���Խ������������
    int swapTimes = 100;
    cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generatorNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Way, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Way, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    cout << endl;


    // ����3 ���Դ��ڰ���������ͬԪ�ص�����
    cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
    arr1 = SortTestHelper::generatorRondomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    // ���������, ��ͨ��QuickSort�˻�ΪO(n^2)���㷨, ��������
    //SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Way, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Way, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;




	return 0;
}