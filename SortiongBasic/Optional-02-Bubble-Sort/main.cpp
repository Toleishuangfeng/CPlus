#include<iostream>
#include<algorithm>
#include"InsertionSort.h"
#include"SelectionSort.h"
#include"SortTestHelper.h"
using namespace std;

//ð�����򷨣�ֱ��ð��
template<typename T>
void bubbleSort1(T arr[], int n) {

	bool swapped;

	do {
		swapped = false;
		for (int i = 1; i < n; i++) {
			if (arr[i - 1] > arr[i]){
				swap(arr[i - 1],arr[i]);
				swapped=true;
				}
		}
		//�Ż�,ÿһ��ð��֮������Ԫ�ط�������λ��
		//������һ�������ʱ��,���һ��Ԫ�ز�����
		n--;
	} while (swapped);
} 

//�M����ð������,��¼λ����󽻻�ֵ
template<typename T>
void bubbleSort2(T arr[], int n) {

	int newn;//���ڼ�¼����λ�õ�

	do {
		newn = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i - 1] > arr[i])
				swap(arr[i - 1], arr[i]);
			//��¼���һ�ν�����λ��,�ٴ�֮���Ԫ������һ��ɨ���� ��������
			newn = i;
		}
		n = newn;

	} while (newn > 0);
	
}

int main() {

	int n = 20000;
	// ����1 һ�����
	//cout << "Test for random array, size = " << n << ", randome range [0, " << n << "]" << endl;

	int* arr1 = SortTestHelper::generatorRandomArry(n, 0, n);
	int* arr2 = SortTestHelper::copyTArray(arr1, n);
	int* arr3 = SortTestHelper::copyTArray(arr1, n);
	int* arr4 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("Selection Sort",selectionSort , arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
	SortTestHelper::testSort("Bubble Sort1", bubbleSort1, arr3, n);
	SortTestHelper::testSort("Bubble Sort 2", bubbleSort2, arr4, n);
	
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	cout << endl;

	//// ����2 ���Խ������������
	int swapTimes = 100;

	cout << "Test for nNearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;

	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyTArray(arr1, n);
	arr3 = SortTestHelper::copyTArray(arr1, n);
	arr4 = SortTestHelper::copyTArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
	SortTestHelper::testSort("Bubble Sort", bubbleSort1, arr3, n);
	SortTestHelper::testSort("Bubble Sort 2", bubbleSort2, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	cout << endl;


	// ����3 ������ȫ���������
	// ������ȫ��������飬ð������Ҳ����ΪO(n)������㷨
	swapTimes = 0;
	n = 10000000;    // ���ڲ������򷨺�ð����������ȫ���������¶�����ΪO(n)�㷨
					 // �������ǵĲ������ݹ�ģ���Ϊ1000,0000
	cout << "Test for ordered array, size = " << n << endl;

	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyTArray(arr1, n);
	arr3 = SortTestHelper::copyTArray(arr1, n);
	arr4 = SortTestHelper::copyTArray(arr1, n);

	// ����������£����ٲ���ѡ�������㷨
	//SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
	////������ȫ���������,��������ʱð��������㷨ʱ�临�Ӷ�Ϊn(n-1)/2,���������ͱȽϴ�����ֵ,ʱ�临�Ӷ�Ϊ0(n^2)
	//��Ϊ����(��õ����,����n-1�αȽϼ������
	SortTestHelper::testSort("Bubble Sort1", bubbleSort1, arr3, n);
	//���������������˵�ͺܼ���
	SortTestHelper::testSort("Bubble Sort 2", bubbleSort2, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;


}