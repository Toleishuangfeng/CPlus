#include<iostream>
#include"IndexMinHeap.h"
#include"SortTestHelper.h"

using namespace std;

template<typename T>
void heapSortUsingIndexMinHeap(T arr[], int n) {
	IndexMinHeap<int> indexMinHeap = IndexMinHeap<int>(n);
	for (int i = 0; i < n; i++) {
		indexMinHeap.insert(i,arr[i]);
	}

	for (int i = 0; i < n; i++) {
		arr[i] = indexMinHeap.extractMin();
	}
}

int main() {
	int n = 10000;
	int* arr = SortTestHelper::generatorRondomArray(n, 0, n);
	SortTestHelper::testSort("Heap Sort Using Index-Min-Heap", heapSortUsingIndexMinHeap, arr, n);
	delete[] arr;

	return 0;
}