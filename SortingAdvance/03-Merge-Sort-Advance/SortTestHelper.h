#pragma once

#include<iostream>
#include<algorithm>
#include<ctime>
#include<cassert>
using namespace std;
namespace SortTestHelper {

	int* generatorRandomArry(int n, int rangeL, int rangeR) {
		assert(rangeL <= rangeR);
		int* arr = new int[n];

		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}
	//���ɽ������������
	int* generateNearlyOrderedArray(int n, int swapTimes) {

		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}
		srand(time(NULL));
		for (int i = 0; i < swapTimes; i++) {
			int posx = rand() % n;
			int posy = rand() % n;
			swap(arr[posx], arr[posy]);
		}

		return arr;
	}

	template<typename T>
	T* copyTArray(T arr[], int n) {

		T* a = new T[n];
		for (int i = 0; i < n; i++) {
			a[i] = arr[i];
		}
		return a;
	}
	//��ӡ�������
	template<typename T>
	void printArray(T arr[], int n) {

		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	//�ж������Ƿ�����
	template<typename T>
	bool isSorted(T arr[], int n) {

		for (int i = 1; i < n && arr[i] < arr[i - 1]; i++)
			return false;
		return true;
	}

	//���������㷨��ʱ���Ժ���ȷ��
	template<typename T>

	void testSort(const string& sortName, void(*sort)(T arr[], int), T arr[], int n) {
		
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
		

		assert(isSorted(arr, n));

		return;
	}

}