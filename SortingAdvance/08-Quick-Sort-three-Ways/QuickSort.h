#pragma once
#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

//对arr[l...r]部分进行partition操作
//返回p,是的arr[l...p-1]<arr[p];arr[p+1...r]>arr[p]
template<typename T>
int _partition(T arr[], int l, int r) {

	//随便找一个标定点pivot
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	int j = l;
	for (int i = l + 1; i <= r; i++) {

		if (arr[i] < v) {
			j++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[l], arr[j]);

	return j;
}

//双路快速排序的partition
template<typename T>
int _partition2(T arr[], int l, int r) {

	//1:随机找一个标定点
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	int i=l+1;
	int j = r;
	while (true) {
		while (i <= r && arr[i] < v)
			i++;
		while (j >= l + 1 && arr[j] > v)
			j--;

		if (i > j)break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap(arr[l], arr[j]);
	return j;
}

template<typename T>
void _quickSort(T arr[], int l,int r) {

	if (l >= r)return;

	//调用快速排序的partition
	int p = _partition2(arr, l, r);
	_quickSort(arr, l, p - 1);
	_quickSort(arr, p + 1, r);
}


template<typename T>
void quickSort(T arr[], int n) {

	srand(time(NULL));
	_quickSort(arr, 0, n - 1);
}