#include<iostream>
#include<algorithm>
#include"InsertionSort.h"
#include"MergeSort.h"
#include"SortTestHelper.h"
using namespace std;

//��arr[l...r]����patition����
//����p,ʹ��arr[l...p-1]<arr[p];arr[p+1.....r]>arr[p]
template<typename T>
int _partition(T arr[], int l, int r) {

	T v = arr[l];

	int j = l;//arr[l+1....j]<v;arr[j+1...i]>v;
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			j++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

//��arr[l....r]���п�������
template<typename T>
void _quickSort(T arr[], int l, int r) {

	if (l >= r) return;

	int p = _partition(arr, l, r);
	_quickSort(arr, l, p - 1);
	_quickSort(arr, p + 1, r);

}

template<typename T>
void quickSort(T arr[], int n) {

	_quickSort(arr, 0, n - 1);

}
int main() {

	int n = 1000000;

	//����1:һ�����
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRondomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;


	return 0;
}