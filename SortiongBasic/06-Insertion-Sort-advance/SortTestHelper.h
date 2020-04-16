#pragma once
#include <cassert>
#include<iostream>
#include<ctime>
#include<string>

using namespace std;

namespace SortTestHelper {
	//随机生成arr数字,大小范围在[rangeL,rangeR]之间
	int* generatorRandomArry(int n, int rangeL, int rangeR) {
		assert(rangeL <= rangeR);
		int* arr = new int[n];

		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}
	//生成一个近乎有序的数组
	int* generateNearlyOrderedArray(int n, int swapTimes) {
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}
		srand(time(NULL));
		for (int i = 0; i < swapTimes; i++) {
			int posx = rand() % n;
			int posy = rand() % n;
			swap(posx, posy);
		}
		return arr;
	}
	//打印函数
	template<typename T>
	void printArray(T arr[], int n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	//拷贝函数
	template<typename T>
	T* copyTArray(T a[], int n) {
		T* arr = new T[n];

		for (int i = 0; i < n; i++) {
			arr[i] = a[i];
		}
		//copy(n, a + n, arr);
		return arr;
	}

	//判断是否数组是否有序
	template<typename T>
	bool isSorted(T arr[], int n) {
		for (int i = 1; i < n && arr[i] < arr[i - 1]; i++)
			return false;
		return true;
	}
	template<typename T>
	void testSort(const string& sortName, void(*sort)(T[], int), T arr[], int n) {
		clock_t	start_time = clock();
		sort(arr, n);
		clock_t end_time = clock();
		cout << sortName << " :" << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
		//printArray(arr, n);
		assert(isSorted(arr, n));
		return;
	}

};