#include<iostream>
#include"InsertionSort.h"
#include"MergeSort1.h"
#include"MergeSort2.h"
#include"QuickSort.h"
#include"QuickSort2Ways.h"
#include"QuickSort3Ways.h"
#include"ShellSort.h"
#include"SortTestHelper.h"

using namespace std;

// �Ƚ� Shell Sort �� Merge Sort �� ���� Quick Sort ������Ч��
// ʹ�ø���ѧ�ıȽϷ�ʽ, ÿ�αȽ϶����ж�β�������, ȡƽ��ֵ
// ���Կ���, Shell Sort��Ȼ���ڸ߼�������ʽ, ����Ȼ�Ƿǳ��о�������һ�������㷨
// �������ѵ�ʱ����ȫ�ڿ������̵ķ�Χ��, Զ����O(n^2)�������㷨, ���������ϴ��ʱ���޷�����
// ͬʱ, Shell Sortʵ�ּ�, ֻʹ��ѭ���ķ�ʽ�����������, ����Ҫʵ�ֵݹ�, ��ռ��ϵͳռ�ռ�, Ҳ�����������
// ����, ����㷨ʵ����ʹ�õĻ���������ʵ�ָ��ӵ������㷨, ��������Ŀ���̵Ĳ��Խ׶�, ��ȫ������ʱʹ��Shell Sort��������������:)



int main() {
	//����T����������,ÿ������������СΪn
	int T = 5;
	int n = 10000;

	//�Ƚ�shell sort��merge sort������QuickSort�����㷨������Ч��
	//����1:������ɵ�����
	double time1 = 0.0, time2 = 0.0, time3 = 0.0, time4 = 0.0, time5 = 0.0;
	for (int i = 0; i < T; i++) {
		int* arr1 = SortTestHelper::generatorRondomArray(n, 0, n);
		int* arr2 = SortTestHelper::copyIntArray(arr1, n);
		int* arr3 = SortTestHelper::copyIntArray(arr1, n);
		int* arr4 = SortTestHelper::copyIntArray(arr1, n);
		int* arr5 = SortTestHelper::copyIntArray(arr1, n);
		time1 += SortTestHelper::testSort(shellSort, arr1, n);
		time2 += SortTestHelper::testSort(mergeSort2, arr2, n);
		time3 += SortTestHelper::testSort(quickSort, arr3, n);
		time4 += SortTestHelper::testSort(quickSort2Ways, arr4, n);
		time5 += SortTestHelper::testSort(QuickSort3Ways, arr5, n);

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		delete[] arr4;
		delete[] arr5;
	}
	cout << "Sorting " << n << " elements " << T << " times. Calculate the average run time." << endl;
	cout << "Shell Sort Average Run Time: " << time1 / T << " s" << endl;
	cout << "Merge Sort Average Run Time: " << time2 / T << " s" << endl;
	cout << "Quick Sort Average Run Time: " << time3 / T << " s" << endl;
	cout << "Quick Sort 2 Ways Average Run Time: " << time4 / T << " s" << endl;
	cout << "Quick Sort 3 Ways Average Run Time: " << time5 / T << " s" << endl;

	//����2:�������������
	time1 = 0.0, time2 = 0.0, time3 = 0.0, time4 = 0.0, time5 = 0.0;
	for (int i = 0; i < T; i++) {
		int* arr1 = SortTestHelper::generatorNearlyOrderedArray(n,10);
		int* arr2 = SortTestHelper::copyIntArray(arr1, n);
		int* arr3 = SortTestHelper::copyIntArray(arr1, n);
		int* arr4 = SortTestHelper::copyIntArray(arr1, n);
		int* arr5 = SortTestHelper::copyIntArray(arr1, n);
		time1 += SortTestHelper::testSort(shellSort, arr1, n);
		time2 += SortTestHelper::testSort(mergeSort2, arr2, n);
		time3 += SortTestHelper::testSort(quickSort, arr3, n);
		time4 += SortTestHelper::testSort(quickSort2Ways, arr4, n);
		time5 += SortTestHelper::testSort(QuickSort3Ways, arr5, n);

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		delete[] arr4;
		delete[] arr5;
	}
	cout << "Nearly Ordered Array Sorting " << n << " elements " << T << " times. Calculate the average run time." << endl;
	cout << "Shell Sort Average Run Time: " << time1 / T << " s" << endl;
	cout << "Merge Sort Average Run Time: " << time2 / T << " s" << endl;
	cout << "Quick Sort Average Run Time: " << time3 / T << " s" << endl;
	cout << "Quick Sort 2 Ways Average Run Time: " << time4 / T << " s" << endl;
	cout << "Quick Sort 3 Ways Average Run Time: " << time5 / T << " s" << endl;



	return 0;
}