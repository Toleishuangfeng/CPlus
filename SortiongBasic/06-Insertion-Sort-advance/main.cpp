#include<iostream>
#include<cassert>
#include<string>
#include"SelectionSort.h"
#include"SortTestHelper.h"

using namespace std;

template <typename T>
void insertionSort(T arr[], int n) {
	for (int i = 1; i < n; i++) {
		//寻找元素arr[i]合适的位置插入
	/*	for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
			swap(arr[j], arr[j - 1]);*/

		//写法三
		T e = arr[i];
		int j;//保存元素e应该输入的位置
		for (j = i; j > 0 && arr[j-1] > e; j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
	return;
}

int main() {
	int n = 2000;
	//一般测试
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRandomArry(n, 0, n);
	int* arr2 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("InsertionSort", insertionSort,arr1, n);
	SortTestHelper::testSort("SelectionSort", selectionSort, arr2, n);
	
	delete[] arr1;
	delete[]arr2;

	////测试有序性更强的
	cout << "Test for more ordered random array, size = " << n << ", random range [0, 3]" << endl;
	arr1 = SortTestHelper::generatorRandomArry(n, 0, 3);
    arr2 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("InsertionSort", insertionSort, arr1, n);
	SortTestHelper::testSort("SelectionSort", selectionSort, arr2, n);

	delete[] arr1;
	delete[]arr2;

	////测试近乎有序的
	int swapTimes = 100;
	cout << "Test for nearly random array, size = " << n << ", random range [0, " << n << "]" << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
	arr2 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("InsertionSort", insertionSort, arr1, n);
	SortTestHelper::testSort("SelectionSort", selectionSort, arr2, n);

	delete[] arr1;
	delete[]arr2;

	return 0;
	
}
