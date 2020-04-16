#include<iostream>
#include"MergeSort.h"
#include"SortTestHelper.h"
#include"InsertionSort.h"

using namespace std;

template<typename T>
void mergeSortBU(T arr[], int n) {

	//Merge sort Bottom up
	//for (int sz = 1; sz < n; sz += sz) {
	//	for(int i=0;i<n-sz;i+=sz+sz)
	//	//��arr[i...i+sz-1]��arr[i+sz...i+2*sz-1]��������
	//		_merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
	//}

	//merge sort Buttom up�Ż�
	//����С������ֱ��ʹ�ò�������
	for (int i = 0; i < n; i += 16) {
		insertionSort(arr, i, min(i + 15, n - 1));
	}

	for (int sz = 16; sz < n; sz += sz) {
		for (int i = 0; i < n - sz; i += sz + sz) {
			//����arr[mid]<arr[mid+1]�����,������merge
			if (arr[i + sz - 1] > arr[i + sz])
				_merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
		}
	}
	// Merge Sort BU Ҳ��һ��O(nlogn)���Ӷȵ��㷨����Ȼֻʹ������forѭ��
	// ���ԣ�Merge Sort BUҲ������1��֮�����ɴ���100��������������
	// ע�⣺��Ҫ���׸���ѭ���������ж��㷨�ĸ��Ӷȣ�Merge Sort BU����һ������
	
}

int main() {

	int n = 1000000;

	//����1:һ���ԵĲ���
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRandomArry(n, 0, n);
	int* arr2 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Merge Sort Buttom Up", mergeSortBU, arr2, n);
	
	delete[] arr1;
	delete[] arr2;

	//����2:���Խ������������
	int swapTimes = 100;
	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Merge Sort Buttom Up", mergeSortBU, arr2, n);

	delete[] arr1;
	delete[] arr2;

	return 0;
}