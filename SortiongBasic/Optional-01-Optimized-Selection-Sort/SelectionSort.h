#pragma once
#include<iostream>
#include<algorithm>

using namespace std;
//ѡ�������㷨
template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		//һ��ѭ���ҵ���С���Ǹ�
		for (int j = i + 1; j < n ; j++)
			if(arr[j] < arr[minIndex])
				minIndex = j;
		swap(arr[i], arr[minIndex]);
	}
}