#include<iostream>
#include<ctime>
#include<algorithm>
#include"InsertionSort.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"SortTestHelper.h"

template<typename T>
void _quickSort3Ways(T arr[], int l, int r) {
	if (l >= r)return;

	swap(arr[l], arr[rand() % (r - l + 1) + l]);

	T v = arr[l];

	int lt = l;//arr[l+1...lt]<v
	int gt = r + 1;//arr[gt...r]>v
	int i = l + 1;//arr[lt+1...i]==v

	while (i < gt) {
		if (arr[i] < v) {
			swap(arr[i], arr[lt+1]);
			lt++;
			i++;
		}
		else if (arr[i] > v) {
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else {
			i++;
		}
	}

	swap(arr[l], arr[lt]);

	_quickSort3Ways(arr, l, lt - 1);
	_quickSort3Ways(arr, gt, r);
}

template<typename T>
void quickSort3Ways(T arr[], int n) {
	srand(time(NULL));
	_quickSort3Ways(arr, 0, n - 1);
}
int main() {

    int n = 1000000;

    // ����1 һ���Բ���
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int* arr1 = SortTestHelper::generatorRondomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout << endl;


    // ����2 ���Խ������������
    int swapTimes = 100;
    cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generatorNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout << endl;


    // ����3 ���Դ��ڰ���������ͬԪ�ص�����
    cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
    arr1 = SortTestHelper::generatorRondomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;


    return 0;
}