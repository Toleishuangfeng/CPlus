#pragma once
#include<iostream>

using namespace std;

//将arr[l...mid]和arr[mid+1....r]归并起来
template<typename T>
void _merge(T arr[],int l, int mid, int r) {

	T* aux = new T[r - l + 1];
	   	 
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];

	//初始化,i指向左半部分开始位置,j指向右半部分开始位置
	int i = l, j = mid + 1;

	for (int k = l; k <= r; k++) {
		if (i > mid) {//左半部分处理完
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {//右半部分处理完
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] < aux[j - l]) {//左半部分<右半部分
			arr[k] = aux[i - l];
			i++;
		}
		else {//左半部分元素>右半部分元素
			arr[k] = aux[j - l];
			j++;
		}
	}
	delete[] aux;
}

//递归使用归并排序,对arr[l...r]进行排序
template<typename T>
void _mergeSort(T arr[], int l, int r) {

	if (l >= r)return;
	int mid = (r + l) / 2;
	_mergeSort(arr, l, mid);
	_mergeSort(arr, mid + 1, r);
	_merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr, int n) {

	_mergeSort(arr, 0, n - 1);
}

