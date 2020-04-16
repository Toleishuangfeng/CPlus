#include<iostream>
#include"SortTestHelper.h"

template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		int mixIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[mixIndex])
				mixIndex = j;
		}
		swap(arr[i], arr[mixIndex]);
	}
}
int main() {
	int N = 2000;
	int* arr = SortTestHelper::generatorRandomArry(N, 0, N);
	SortTestHelper::testSort("selectionSort", selectionSort, arr, N);
	delete[] arr;
	return 0;
}