#include<iostream>
#include<ctime>
#include<algorithm>
#include"InsertionSort.h"
#include"SortTestHelper.h"
#include"MergeSort.h"

using namespace std;
//对arr[l....r]部分进行partition操作
template<typename T>
int _partition(T arr[], int l, int r) {

	//随机在arr[l....r]中选择一个数值作为标定点pivot
	
	swap(arr[l], arr[rand() % (r - l+1)+l]);

	T v = arr[l];
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			j++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

//双路快排的partition
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int _partition2(T arr[], int l, int r) {
	
	swap(arr[l], arr[ rand() % (r - l + 1 ) + l]);
	T v = arr[l];
	
	int i = l + 1;
	int j = r;
	while (true) {

		while (i <= r && arr[i] < v)
			i++;

		while (j >= l + 1 && arr[j] > v)
			j--;
		
		if ( i > j )
			break;

		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	swap(arr[l], arr[j]);

	return j;
}
template<typename T>
void _quickSort(T arr, int l, int r) {

	if (l >= r) return;

	int p = _partition2(arr, l, r);
	_quickSort(arr, l, p - 1);
	_quickSort(arr, p + 1, r);
}

template<typename T>
void quickSort(T arr[], int n) {

	srand(time(NULL));
	_quickSort(arr, 0, n - 1);
}

// 比较Merge Sort和双路快速排序两种排序算法的性能效率
int main() {

	int n = 1000000;

	// 测试1 一般性测试
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRondomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	//SortTestHelper::printArray(arr2, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;


	// 测试2 测试近乎有序的数组
	// 双路快速排序算法也可以轻松处理近乎有序的数组
	int swapTimes = 100;
	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generatorNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;


	// 测试3 测试存在包含大量相同元素的数组
	// 使用双快速排序后, 我们的快速排序算法可以轻松的处理包含大量元素的数组
	cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
	arr1 = SortTestHelper::generatorRondomArray(n, 0, 10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;


	return 0;
}