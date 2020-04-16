#include<iostream>
#include<cassert>
#include"InsertionSort.h"
#include"SortTestHelper.h"

//将arr[l...mid]和arr[mid+1....r]两部分进行归并
template<typename T>
void _merge(T arr[], int l, int mid, int r) {

	T* aux = new T[r - l + 1];
	for (int i = l; i <= r; i++) {
		aux[i - l] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {

		if (i > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if(j > r)
		{
			arr[k] = aux[i - l];
			i++;
		}
		else if(aux[i-l]<aux[j-l]){
			arr[k] = aux[i - l];
			i++;
		}
		else {
			arr[k] = aux[j - l];
			j++;
		}
	}
	delete[] aux;
}

//递归使用归并排序对arr[l....r]范围进行排序
template<typename T>
void _mergeSort(T arr[], int l, int r) {

	if (l >= r) return;

	int mid = (r + l) / 2;
	_mergeSort(arr, l, mid);
	_mergeSort(arr, mid + 1, r);
	_merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {

	_mergeSort(arr, 0, n - 1);
}

int main() {

	// 可以在1秒之内轻松处理100万数量级的数据
	// 注意：不要轻易尝试使用SelectionSort, InsertionSort或者BubbleSort处理100万级的数据
	// 否则，你就见识了O(n^2)的算法和O(nlogn)算法的本质差异：）
	int n = 50000;

	// 测试1 一般性测试
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRandomArry(n, 0, n);
	int* arr2 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;

	// 测试2 测试近乎有序的数组
	// 对于近乎有序的数组, 数组越有序, InsertionSort的时间性能越趋近于O(n)
	// 所以可以尝试, 当swapTimes比较大时, MergeSort更快
	// 但是当swapTimes小到一定程度, InsertionSort变得比MergeSort快
	int swapTimes = 10;
	assert(swapTimes >= 0);

	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

	delete[] arr1;
	delete[] arr2;
	return 0;
}
