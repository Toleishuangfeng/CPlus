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

		srand(time(NULL));//��֤ÿ�����е�������Ӳ�ͬ
						//���������Ժ�,rand()�������������������ӵ�ֵ�Ƕ��˵�,�����ƻ�ϵͳ
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (rangR - rangL + 1) + rangL;
		}
		return arr;
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
	//��������
	template<typename T>
	T* copyTArray(T a[], int n) {
		T* arr = new T[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			arr[i] = a[i];
		}
		return arr;
	}

	//�ж������Ƿ�����
	template<typename T>
	bool isSorted(T arr[], int n) {
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}
	//���Բ�ͬ��sort�����㷨����arr[]�������õ�����ȷ�Ժ�����ʱ��
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

