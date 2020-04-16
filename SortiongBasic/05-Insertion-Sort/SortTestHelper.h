#pragma once
#include<iostream>
#include<cassert>
#include<string>s
#include <time.h>
using namespace std;
#pragma once
#include<iostream>
#include<cassert>
#include<string>s
#include <time.h>
using namespace std;

namespace SortTestHelper {

	int* generatorRandomArry(int n, int rangL, int rangR) {
		assert(rangL <= rangR);

		int* arr = new int[n];

		srand(time(NULL));//保证每次运行的随机种子不同
						//正常开机以后,rand()函数产生的这个随机种子的值是定了的,除非破坏系统
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (rangR - rangL + 1) + rangL;
		}
		return arr;
	}
	//打印输出数组
	template<typename T>
	void printArray(T arr[], int n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	//复制数组
	template<typename T>
	T* copyTArray(T a[], int n) {
		T* arr = new T[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			arr[i] = a[i];
		}
		return arr;
	}

	//判断数组是否有序
	template<typename T>
	bool isSorted(T arr[], int n) {
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}
	//测试不同的sort排序算法排序arr[]数组所得到的正确性和运行时间
	template<typename T>
	void testSort(const string& sortName, void (*sort)(T[], int), T arr[], int n) {
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		assert(isSorted(arr, n));
		cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

		return;
	}


}

