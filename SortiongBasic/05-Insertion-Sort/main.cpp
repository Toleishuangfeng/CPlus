#include<iostream>
#include"SortTestHelper.h"
#include"SelectionSort.h"


template<typename T>
void insertionSort(T arr[], int n) {
	for (int i = 1; i < n; i++) {
		//寻找元素arr[i]合适的插入位置
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
		}
		//写法2:
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
			swap(arr[j], arr[j - 1]);
	}
	return;
}
int main() {
	int N = 2000;
	cout << "test for random arry ,size = " << N << ",random range[0," << N << "]" << endl;
	int* arr1 = SortTestHelper::generatorRandomArry(N, 0, N);
	int* arr2 = SortTestHelper::copyTArray(arr1, N);

	SortTestHelper::testSort("selectionSort", selectionSort, arr1, N);
	SortTestHelper::testSort("InsertionSort", insertionSort, arr2, N);
	delete[] arr1;
	delete[] arr2;
	return 0;
}