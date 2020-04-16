#include<iostream>
#include<algorithm>

using namespace std;

/*****************************
* �Զ����µĹ鲢���� ���Ż�*
******************************/

//��arr[l...mid]��arr[mid+1....r]�����ֽ��й鲢
template<typename T>
void _merge1(T arr[], int l, int mid, int r) {

	T* aux = new T[r - l + 1];
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] < aux[j - l]) {
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

//ʹ�õݹ�ķ�ʽ���й鲢����,��arr[l....r]��Χ��������
template<typename T>
void _mergeSort1(T arr[], int l, int r) {

	if (l >= r)return;

	int mid = (r - l) / 2 + l;

	_mergeSort1(arr, l, mid);
	_mergeSort1(arr, mid + 1, r);
	//if (arr[mid] > arr[mid + 1])
	_merge1(arr, l, mid, r);
}
//�Զ����µĹ鲢����
template<typename T>
void mergeSort1(T arr[], int n) {

	_mergeSort1(arr, 0, n - 1);
}

/*****************************
* �Ե����ϵĹ鲢����,���Ż� *
******************************/

template<typename T>
void mergeSortBU1 (T arr[], int n){
	
	for (int sz = 1; sz <= n; sz += sz) {
		for (int i = 0; i < n; i += sz + sz) {
			//��arr[i...i+sz-1]��arr[i+sz....i+sz+sz-1]���й鲢
			_merge1(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
		}
	}

}

/******************************
* �Զ����µĹ鲢����,���Ż� *
********************************/

template<typename T>
void _merge2(T arr[], T aux[], int l, int mid, int r) {

	for (int i = l; i <= r; i++) {
		aux[i] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = aux[j]; j++;
		}
		else if (j > r) {
			arr[k] = aux[i]; i++;
		}
		else if (aux[i] < aux[j]) {
			arr[k] = aux[i]; i++;
		}
		else {
			arr[k] = aux[j]; j++;
		}
	}
}

//ʹ���Ż��Ĺ鲢����,��arr[l....r]��Χ��������
//����aux[]Ϊ���merge��������Ҫ�ĸ����ռ�
template<typename T>
void _mergeSort2(T arr[], T aux[], int l, int r) {

	if (l >= r)return;
	int mid = (r - l) / 2 + l;
	_mergeSort2(arr, aux, l, mid);
	_mergeSort2(arr, aux, mid + 1, r);

	if (arr[mid] > arr[mid + 1])
		_merge2(arr, aux, l, mid, r);
}

//�Զ����µ��Ż��鲢����
template<typename T>
void mergeSort2(T arr[], int n) {

	T* aux = new T[n];
	_mergeSort2(arr, aux, 0, n - 1);
	delete[] aux;
}

/******************************
** �Ե����ϵĹ鲢����,���Ż�**
*******************************/

template<typename T>
void mergeSortBU2(T arr[], int n) {
	T* aux = new T[n];
	for (int sz = 1; sz <= n; sz += sz) {
		for (int i = 0; i < n - sz; i += sz + sz) {
			if (arr[i + sz - 1] > arr[i + sz]) {
				_merge2(arr, aux, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
			}
		}
	}
	delete[]aux;

}