#include<iostream>
#include<ctime>
#include<algorithm>
#include"InsertionSort.h"
#include"SortTestHelper.h"
#include"MergeSort.h"

using namespace std;
//��arr[l....r]���ֽ���partition����
template<typename T>
int _partition(T arr[], int l, int r) {

	//�����arr[l....r]��ѡ��һ����ֵ��Ϊ�궨��pivot
	
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

//˫·���ŵ�partition
// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
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

// �Ƚ�Merge Sort��˫·�����������������㷨������Ч��
int main() {

	int n = 1000000;

	// ����1 һ���Բ���
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRondomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	//SortTestHelper::printArray(arr2, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;


	// ����2 ���Խ������������
	// ˫·���������㷨Ҳ�������ɴ���������������
	int swapTimes = 100;
	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generatorNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;


	// ����3 ���Դ��ڰ���������ͬԪ�ص�����
	// ʹ��˫���������, ���ǵĿ��������㷨�������ɵĴ����������Ԫ�ص�����
	cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
	arr1 = SortTestHelper::generatorRondomArray(n, 0, 10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;


	return 0;
}