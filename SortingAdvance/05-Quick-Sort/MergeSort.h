#pragma once
#include<iostream>
#include<algorithm>
#include"InsertionSort.h"

//��arr[l...mid]��arr[mid+1...r]���й鲢
template<typename T>
void _merge(T arr[], int l, int mid, int r) {

	T* aux = new T[r - l + 1];
	//�鲢ʱ����
	for (int i = l; i <= r; i++) {
		aux[i - l] = arr[i];
	}

	//��ʼ����,��ʼ��,iָ����벿�ֿ�ʼλ��,jָ���Ұ벿�ֿ�ʼλ��
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {//��벿�ִ�����
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {//�Ұ벿�ִ�����
			arr[k] = aux[i - l];
			i++;
		}else if (aux[i - l] < aux[j - l])//��벿��<�Ұ벿��
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

	//����С��ģ������,ʹ�ò�������
	/*if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}*/
	int mid = (l + r) / 2;
	_mergeSort(arr, l, mid);
	_mergeSort(arr, mid + 1, r);

	//����arr[mid]<=arr[mid+1]�������,��ʹ��merge
	if(arr[mid]>arr[mid+1])
		_merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {
	
	_mergeSort(arr, 0, n - 1);
}
