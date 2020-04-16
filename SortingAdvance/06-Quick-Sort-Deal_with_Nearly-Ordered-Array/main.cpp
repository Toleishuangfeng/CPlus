#include<iostream>
#include<ctime>
#include<algorithm>
#include"InsertionSort.h"
#include"MergeSort.h"
#include"SortTestHelper.h"

using namespace std;

//��arr[l...r]���ֽ���partition����
//����p,�ǵ�arr[l...p-1]<arr[p];arr[p+1...r]>arr[p]
template<typename T>
int _partition(T arr[], int l, int r) {

	//�����arr[l....r]��Χ��ѡһ����ֵ��Ϊ�궨��pivot
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


//��arr[l...r]���ֽ��п�������
template<typename T>
void _quickSort(T arr[], int l, int r) {

	if (l >= r) return;
	//����С��ģ����,ʹ�ò�����������Ż�,�������
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

	// ����1 һ���Բ���
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRondomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;


	// ����2 ���Խ������������
	// ���������ѡ��궨��Ĳ����, ���ǵĿ�������������ɴ���������������
	// ���Ƕ��ڽ������������, ��Ч�ʱ��Ż���Ĺ鲢����Ҫ��, ����ȫ�����̷�Χ��
	// ˼��һ��Ϊʲô���ڽ������������, ���ŵ����ܱ��Ż���Ĺ鲢�����? :)
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
