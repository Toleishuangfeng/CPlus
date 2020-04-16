#pragma once
#pragma once
#include<iostream>
#include<cassert>
#include<ctime>

using namespace std;

namespace SortTestHelper {

	//������ɷ�Χ��[l...r]������
	int* generatorRondomArray(int n, int l, int r) {

		int* arr = new int[n];

		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (r - l + 1) + l;
		}
		return arr;
	}

	//���ɽ������������
	int* generatorNearlyOrderedArray(int n, int swapTimes) {
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = i;

		srand(time(NULL));
		for (int i = 0; i < swapTimes; i++) {
			int posx = rand() % n;
			int posy = rand() % n;
			swap(arr[posx], arr[posy]);
		}
		return arr;
	}

	// ������������a�е�����Ԫ�ص�һ���µ�����, �������µ�����
	int* copyIntArray(int a[], int n) {

		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = a[i];
		return arr;
	}

	// ��ӡarr�������������
	template<typename T>
	void printArray(T arr[], int n) {

		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;

		return;
	}

	// �ж�arr�����Ƿ�����
	template<typename T>
	bool isSorted(T arr[], int n) {

		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
				return false;

		return true;
	}

	//����sort�����㷨����arr�������õ��Ľ����ȷ�Ժ��㷨����ʱ��
	template<typename T>
	void testSort(const string& sortName, void(*sort)(T[], int), T arr[], int n) {

		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	//	printArray(arr, n);
		assert(isSorted(arr, n));

		return;
	}
};