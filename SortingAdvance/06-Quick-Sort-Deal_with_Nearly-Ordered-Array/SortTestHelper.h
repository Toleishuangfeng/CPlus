#pragma once
#pragma once
#include<iostream>
#include<cassert>
#include<ctime>

using namespace std;

namespace SortTestHelper {

	//随机生成范围在[l...r]的数组
	int* generatorRondomArray(int n, int l, int r) {

		int* arr = new int[n];

		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (r - l + 1) + l;
		}
		return arr;
	}

	//生成近乎有序的数组
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

	// 拷贝整型数组a中的所有元素到一个新的数组, 并返回新的数组
	int* copyIntArray(int a[], int n) {

		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = a[i];
		return arr;
	}

	// 打印arr数组的所有内容
	template<typename T>
	void printArray(T arr[], int n) {

		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;

		return;
	}

	// 判断arr数组是否有序
	template<typename T>
	bool isSorted(T arr[], int n) {

		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
				return false;

		return true;
	}

	//测试sort排序算法排序arr数组所得到的结果正确性和算法运行时间
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