#include"MinHeap.h"
#include"SortTestHelper.h"
#include<iostream>

using namespace std;

template<typename T>
void heapSortUsingMinHeap(T arr[], int n) {
	MinHeap<int> minHeap = MinHeap<int>(n);
	for (int i = 0; i < n; i++) {
		minHeap.insert(arr[i]);
	}

	for (int i = 0; i < n; i++) {
		arr[i] = minHeap.extractMin();
	}
}
int main() {
	int n = 100000;
	int* arr=SortTestHelper::generatorRondomArray(n, 0, n);
	SortTestHelper::testSort("Heap Sort using Min Heap", heapSortUsingMinHeap, arr, n);
	delete[]arr;
	return 0;


}