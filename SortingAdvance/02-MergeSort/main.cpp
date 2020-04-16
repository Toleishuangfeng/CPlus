#include<iostream>
#include<cassert>
#include"InsertionSort.h"
#include"SortTestHelper.h"

//��arr[l...mid]��arr[mid+1....r]�����ֽ��й鲢
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

//�ݹ�ʹ�ù鲢�����arr[l....r]��Χ��������
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

	// ������1��֮�����ɴ���100��������������
	// ע�⣺��Ҫ���׳���ʹ��SelectionSort, InsertionSort����BubbleSort����100�򼶵�����
	// ������ͼ�ʶ��O(n^2)���㷨��O(nlogn)�㷨�ı��ʲ��죺��
	int n = 50000;

	// ����1 һ���Բ���
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generatorRandomArry(n, 0, n);
	int* arr2 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;

	// ����2 ���Խ������������
	// ���ڽ������������, ����Խ����, InsertionSort��ʱ������Խ������O(n)
	// ���Կ��Գ���, ��swapTimes�Ƚϴ�ʱ, MergeSort����
	// ���ǵ�swapTimesС��һ���̶�, InsertionSort��ñ�MergeSort��
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
