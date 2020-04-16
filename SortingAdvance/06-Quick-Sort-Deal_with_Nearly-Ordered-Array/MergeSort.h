#pragma once
#include<iostream>

using namespace std;

template<typename T>
void _merge(T arr[], int l, int mid, int r) {

	T* aux = new T[r - l + 1];
	for (int i = l; i <= r; i++) {
		aux[i - l] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {

		if (i > mid) {//左半边处理完
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {//右半边处理完
			arr[k] = aux[i - l];
			i++;

		}
		else if (aux[i - l] > aux[j - l]) {
			arr[k] = aux[j - l];
			j++;
		}
		else {
			arr[k] = aux[i - l];
			i++;
		}
	}
	delete[] aux;
}
template<typename T>
void _mergeSort(T arr[], int l, int r) {

	if (l >= r) return;

	int mid = (l + r) / 2;
	_mergeSort(arr, l, mid);
	_mergeSort(arr, mid + 1, r);
	
	if (arr[mid] > arr[mid + 1])
		_merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {

	_mergeSort(arr, 0, n - 1);
}