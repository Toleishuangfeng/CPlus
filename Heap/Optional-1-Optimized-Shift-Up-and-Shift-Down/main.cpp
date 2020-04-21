#include<iostream>
#include"MaxHeap.h"
#include"MaxHeapO.h"
#include"SortTestHelper.h"

using namespace std;

template<typename T>
void maxHeapTestBySort(T arr[], int n) {
	MaxHeap<T> maxHeap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++) {
		maxHeap.insert(arr[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		arr[i] = maxHeap.extractMax();
	}
}
template<typename T>
void maxHeapOTestBySort(T arr[], int n) {
	MaxHeapO<T> maxHeap = MaxHeapO<T>(n);
	for (int i = 0; i < n; i++) {
		maxHeap.insert(arr[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		arr[i] = maxHeap.extractMax();
	}
}

int main() {

	int n = 100000;
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRondomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Sort by MaxHeap", maxHeapTestBySort, arr1, n);
	SortTestHelper::testSort("Sort by MaxHeap Optimized", maxHeapOTestBySort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	return 0;
}