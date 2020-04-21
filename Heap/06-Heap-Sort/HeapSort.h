#include"Heap.h"

using namespace std;
template<typename T>
void heapSort1(T arr[], int n) {
	MaxHeap<int> maxHeap = MaxHeap<int>(n);
	for (int i = 0; i < n; i++) {
		maxHeap.insert(arr[i]);
	}
	
	for (int i = n - 1; i >= 0; i--) {
		arr[i] = maxHeap.extractMax();
	}
}

template<typename T>
void heapSort2(T arr[], int n) {
	MaxHeap<int> maxHeap = MaxHeap<int>(arr, n);
	for (int i = n - 1; i >= 0; i--) {
		arr[i] = maxHeap.extractMax();
	}
}