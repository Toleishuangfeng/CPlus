#include<iostream>
#include<algorithm>
#include"Heap.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"QuickSort2Ways.h"
#include"QuickSort3Ways.h"
#include"SortTestHelper.h"

using namespace std;

template<typename T>
void heapSort1(T arr[], int n) {
	MaxHeap<T> maxHeap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++) {
		maxHeap.insert(arr[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		arr[i] = maxHeap.extractMax();
	}
}
template<typename T>
void heapSort2(T arr[], int n) {
	MaxHeap<T>maxHeap = MaxHeap<T>(arr, n);
	for (int i = n - 1; i >= 0; i--) {
		arr[i] = maxHeap.extractMax();
	}
}

int main() {

	int n = 10000;

	//测试1:一般性测试
	cout << "test for random array ,size=" << n << ",random range [0," << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRondomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);
	int* arr3 = SortTestHelper::copyIntArray(arr1, n);
	int* arr4 = SortTestHelper::copyIntArray(arr1, n);
	int* arr5 = SortTestHelper::copyIntArray(arr1, n);
	int* arr6 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 2 ways", quickSort2Ways, arr3, n);
	SortTestHelper::testSort("Quick Sort 3 ways", quickSort3Ways, arr4, n);
	SortTestHelper::testSort("Heap Sort1", heapSort1, arr5, n);
	SortTestHelper::testSort("Heap Sort2", heapSort2, arr6, n);

	delete[] arr1;
	delete[]arr2;
	delete[]arr3;
	delete[]arr4;
	delete[]arr5;
	delete[]arr6;

	cout << endl;
	//测试2:测试近乎有序的数组
	int swapTimes = 100;
	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generatorNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);
	arr6 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 2 ways", quickSort2Ways, arr3, n);
	SortTestHelper::testSort("Quick Sort 3 ways", quickSort3Ways, arr4, n);
	SortTestHelper::testSort("Heap Sort1", heapSort1, arr5, n);
	SortTestHelper::testSort("Heap Sort2", heapSort2, arr6, n);

	delete[] arr1;
	delete[]arr2;
	delete[]arr3;
	delete[]arr4;
	delete[]arr5;
	delete[]arr6;

	cout << endl;

	//测试3:测试包含大量相同元素的数组
	cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
	arr1 = SortTestHelper::generatorRondomArray(n, 0, 10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);
	arr6 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 2 ways", quickSort2Ways, arr3, n);
	SortTestHelper::testSort("Quick Sort 3 ways", quickSort3Ways, arr4, n);
	SortTestHelper::testSort("Heap Sort1", heapSort1, arr5, n);
	SortTestHelper::testSort("Heap Sort2", heapSort2, arr6, n);

	delete[] arr1;
	delete[]arr2;
	delete[]arr3;
	delete[]arr4;
	delete[]arr5;
	delete[]arr6;
	return 0;

}