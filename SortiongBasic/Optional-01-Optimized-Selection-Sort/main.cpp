#include<iostream>
#include<cassert>
#include<string>
#include"InsertionSort.h"
#include"SelectionSort.h"
#include"SortTestHelper.h"

using namespace std;
//��ѡ����������Ż�,ͬʱ�ҵ���ĺ�С��
template <typename T>
void selectionSort2(T arr[], int n) {
	int left = 0;
	int right = n - 1;
	while (left < right) {
		int minIndex = left;
		int maxIndex = right;
		//��ÿһ�ֲ���ʱ,��֤arr[minIndex]<=arr[maxIndex]
		if (arr[minIndex] > arr[maxIndex])
			swap(arr[minIndex], arr[maxIndex]);
		for (int i = left + 1; i < right; i++) {
			if (arr[i] < arr[minIndex])
				minIndex = i;
			else if (arr[i] > arr[maxIndex])
				maxIndex = i;
		}
		swap(arr[left], arr[minIndex]);
		swap(arr[right], arr[maxIndex]);
		left++;
		right--;
	}
	return;
}

int main() {
	int n = 2000;
	//һ�����
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRandomArry(n, 0, n);
	int* arr2 = SortTestHelper::copyTArray(arr1, n);
	int* arr3 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("InsertionSort", insertionSort,arr1, n);
	SortTestHelper::testSort("SelectionSort", selectionSort, arr2, n);
	SortTestHelper::testSort("selectionSort2", selectionSort2, arr3, n);
	
	delete[] arr1;
	delete[]arr2;
	delete[]arr3;

	////���������Ը�ǿ��
	cout << "Test for more ordered random array, size = " << n << ", random range [0, 3]" << endl;
	arr1 = SortTestHelper::generatorRandomArry(n, 0, 3);
    arr2 = SortTestHelper::copyTArray(arr1, n);
	arr3 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("InsertionSort", insertionSort, arr1, n);
	SortTestHelper::testSort("SelectionSort", selectionSort, arr2, n);
	SortTestHelper::testSort("selectionSort2", selectionSort2, arr3, n);

	delete[] arr1;
	delete[]arr2;
	delete[]arr3;

	////���Խ��������
	int swapTimes = 100;
	cout << "Test for nearly random array, size = " << n << ", random range [0, " << n << "]" << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
	arr2 = SortTestHelper::copyTArray(arr1, n);
	arr3 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("InsertionSort", insertionSort, arr1, n);
	SortTestHelper::testSort("SelectionSort", selectionSort, arr2, n);
	SortTestHelper::testSort("selectionSort2", selectionSort2, arr3, n);

	delete[] arr1;
	delete[]arr2;
	delete[]arr3;

	return 0;
	
}
