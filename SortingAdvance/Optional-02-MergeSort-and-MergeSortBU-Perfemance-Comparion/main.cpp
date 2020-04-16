#include<iostream>
#include"MergeSort.h"
#include"SortTestHelper.h"

using namespace std;

int main() {

	//����T������,ÿ�����������������СΪn
	int T = 100;
	int n = 100000;
	
	//�Ƚ�mergeSort��mergeSortBU���������㷨�ڲ��Ż�������µ�����Ч��
	double time1 = 0.0, time2 = 0.0;
	for (int i = 0; i < T; i++) {
		int* arr1 = SortTestHelper::generatorRondomArray(n, 0, n);
		int* arr2 = SortTestHelper::copyIntArray(arr1, n);

		time1 += SortTestHelper::testSort(mergeSort1, arr1, n);
		time2 += SortTestHelper::testSort(mergeSortBU1, arr2, n);

		delete[] arr1;
		delete[] arr2;
	}
	cout << "without Any optimization:" << endl;
	cout << "MergeSort Average Run Time:" << time1 / T << "s" << endl;
	cout << "MergeSortBU Average Run Time��" << time2 / T << "s" << endl;

	

	//�Ƚ�mergeSort��mergeSortBU���������㷨���Ż�������µ�����Ч��
	time1 = 0.0, time2 = 0.0;
	for (int i = 0; i < T; i++) {
		int* arr1 = SortTestHelper::generatorRondomArray(n, 0, n);
		int* arr2 = SortTestHelper::copyIntArray(arr1, n);

		time1 += SortTestHelper::testSort(mergeSort2, arr1, n);
		time2 += SortTestHelper::testSort(mergeSortBU2, arr2, n);

		delete[] arr1;
		delete[] arr2;
	}
	cout << "with optimization:" << endl;
	cout << "MergeSort Average Run Time:" << time1 / T << "s" << endl;
	cout << "MergeSortBU Average Run Time��" << time2 / T << "s" << endl;

	return 0;
}