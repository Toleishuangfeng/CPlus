#include<iostream>
#include"InsertionSort.h"
#include"MergeSort.h"
#include"SortTestHelper.h"

using namespace std;

//使用优化的归并排序算法,对arr[l...r]进行排序
template<typename T>
void _mergeSort2(T arr[], int l, int r) {

	//对于小规模数组使用插入排序
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	int mid = (r + l) / 2;
	_mergeSort2(arr, l, mid);
	_mergeSort2(arr, mid + 1, r);
	

	//优化1://对于arr[mid]<arr[mid+1]的情况不进行merge操作
	//对于近乎有序的数组有效,对于一般情况,有一定的性能损失
	if (arr[mid] > arr[mid + 1])
		_merge(arr, l, mid, r);
}

template<typename T>
void mergeSort2(T arr[], int n) {
	_mergeSort2(arr, 0, n - 1);
}

int main() {

	int n = 50000;

	//测试1:一般测试
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRandomArry(n, 0, n);
	int* arr2 = SortTestHelper::copyTArray(arr1, n);
	int* arr3 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("InsertionSort", insertionSort, arr1, n);
	SortTestHelper::testSort("MergeSort", mergeSort, arr2, n);
	SortTestHelper::testSort("MergeSort2", mergeSort2, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout << endl;

	//测试2:近乎有序的数组
	int swapTimes = 10;
	assert(swapTimes >= 0);

	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyTArray(arr1, n);
	arr3 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("InsertionSort", insertionSort, arr1, n);
	SortTestHelper::testSort("MergeSort", mergeSort, arr2, n);
	SortTestHelper::testSort("MergeSort2", mergeSort2, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	return 0;
}