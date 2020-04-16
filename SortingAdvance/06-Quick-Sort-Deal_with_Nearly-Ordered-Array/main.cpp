#include<iostream>
#include<ctime>
#include<algorithm>
#include"InsertionSort.h"
#include"MergeSort.h"
#include"SortTestHelper.h"

using namespace std;

//对arr[l...r]部分进行partition操作
//返回p,是的arr[l...p-1]<arr[p];arr[p+1...r]>arr[p]
template<typename T>
int _partition(T arr[], int l, int r) {

	//随机在arr[l....r]范围内选一个数值作为标定点pivot
	srand(time(NULL));
	swap(arr[l], arr[rand() % (r - l + 1) + l]);

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


//对arr[l...r]部分进行快速排序
template<typename T>
void _quickSort(T arr[], int l, int r) {

	if (l >= r) return;
	//对于小规模数组,使用插入排序进行优化,会出问题
	/*if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}*/

	int p = _partition(arr, l, r);
	_quickSort(arr, l, p-1);
	_quickSort(arr, p + 1, r);
}

template<typename T>
void quickSort(T arr[], int n) {

	srand(time(NULL));
	_quickSort(arr, 0, n - 1);
}
int main() {

	int n = 1000000;

	// 测试1 一般性测试
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRondomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;


	// 测试2 测试近乎有序的数组
	// 加入了随机选择标定点的步骤后, 我们的快速排序可以轻松处理近乎有序的数组
	// 但是对于近乎有序的数组, 其效率比优化后的归并排序要低, 但完全再容忍范围里
	// 思考一下为什么对于近乎有序的数组, 快排的性能比优化后的归并排序低? :)
	int swapTimes = 100;
	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generatorNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;
	
	return 0;
}
