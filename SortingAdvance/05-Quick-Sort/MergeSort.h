#pragma once
#include<iostream>
#include<algorithm>
#include"InsertionSort.h"

//对arr[l...mid]和arr[mid+1...r]进行归并
template<typename T>
void _merge(T arr[], int l, int mid, int r) {

	T* aux = new T[r - l + 1];
	//归并时备份
	for (int i = l; i <= r; i++) {
		aux[i - l] = arr[i];
	}

	//开始处理,初始化,i指向左半部分开始位置,j指向右半部分开始位置
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {//左半部分处理完
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {//右半部分处理完
			arr[k] = aux[i - l];
			i++;
		}else if (aux[i - l] < aux[j - l])//左半部分<右半部分
		{
			arr[k] = aux[i - l];
			i++;
		}
		else {
			arr[k] = aux[j - l];
			j++;
		}
	}
	delete[] aux;
}

template<typename T>
void _mergeSort(T arr[], int l, int r) {

	if (l >= r) return;

	//对于小规模的数组,使用插入排序
	/*if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}*/
	int mid = (l + r) / 2;
	_mergeSort(arr, l, mid);
	_mergeSort(arr, mid + 1, r);

	//对于arr[mid]<=arr[mid+1]的情况下,不使用merge
	if(arr[mid]>arr[mid+1])
		_merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {
	
	_mergeSort(arr, 0, n - 1);
}
