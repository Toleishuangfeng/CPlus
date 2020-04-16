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
	//	//对arr[i...i+sz-1]和arr[i+sz...i+2*sz-1]进行排序
	//		_merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
	//}

	//merge sort Buttom up优化
	//对于小的数组直接使用插入排序
	for (int i = 0; i < n; i += 16) {
		insertionSort(arr, i, min(i + 15, n - 1));
	}

	for (int sz = 16; sz < n; sz += sz) {
		for (int i = 0; i < n - sz; i += sz + sz) {
			//对于arr[mid]<arr[mid+1]的情况,不进行merge
			if (arr[i + sz - 1] > arr[i + sz])
				_merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
		}
	}
	// Merge Sort BU 也是一个O(nlogn)复杂度的算法，虽然只使用两重for循环
	// 所以，Merge Sort BU也可以在1秒之内轻松处理100万数量级的数据
	// 注意：不要轻易根据循环层数来判断算法的复杂度，Merge Sort BU就是一个反例
	
}

int main() {

	int n = 1000000;

	//测试1:一般性的测试
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRandomArry(n, 0, n);
	int* arr2 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Merge Sort Buttom Up", mergeSortBU, arr2, n);
	
	delete[] arr1;
	delete[] arr2;

	//测试2:测试近乎有序的数组
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