#pragma once
#include<iostream>
#include<ctime>
#include<cassert>

using namespace std;

namespace SortTestHelper {
	//���ɺ�n��Ԫ�ص��������,ÿ��Ԫ�ص������Χ��[rangL,rangR]֮��

	int* generateRandomArray(int n, int rangL, int rangR) {
		assert(rangL <= rangR);
		int* arr = new int[n];

		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (rangR - rangL + 1) + rangL;
		}
		return arr;
	}

	template<typename T>
	void printArray(T arr[], int n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
};