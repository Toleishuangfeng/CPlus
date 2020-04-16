#include<iostream>

using namespace std;

template <typename T>
void _merge1(T arr[], int l, int mid, int r) {

	T* aux = new T[r - l + 1];
	for (int i = l; i <= r; i++) {
		aux[i - l] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {
			arr[k] = aux[i - l]; i++;
		}
		else if (aux[i - l] < aux[j - l]) {
			arr[k] = aux[i - l]; i++;
		}
		else {
			arr[k] = aux[j - l]; j++;
		}


	}
	delete[] aux;
}

template<typename T>
void _mergeSort1(T arr[], int l, int r) {

	if (l >= r)return;
	
	int mid = (r - l) / 2 + l;
	_mergeSort1(arr, l, mid);
	_mergeSort1(arr, mid + 1, r);
	if (arr[mid] > arr[mid + 1])
		_merge1(arr, l, mid, r);
	
	}
//自顶向下的归并排序,未优化
template <typename T>
void mergeSort1(T arr[], int n) {

	_mergeSort1(arr, 0, n - 1);
}