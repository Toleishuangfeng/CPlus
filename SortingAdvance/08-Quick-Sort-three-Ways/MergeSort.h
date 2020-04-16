#include<iostream>

//����arr[l...mid]��arr[mid+1....r]���й鲢����
template<typename T>
void _merge(T arr[], int l,int mid,int r) {

	T* aux = new T[r - l + 1];
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {//��벿���ȴ�����
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {//�Ұ벿���ȴ�����
			arr[k] = aux[i - l];
			i++;
		}else if (aux[i - l] < aux[j - l]) {//��벿��<�Ұ벿��
			arr[k] = aux[i - l];
			i++;
		}
		else {//��벿��>�Ұ벿��
			arr[k] = aux[j - l];
			j++;
		}
	}
	delete[] aux;
}

//��arr[l....r]��������
template<typename T>
void _mergeSort(T arr[], int l, int r) {

	if (l >= r)return;

	int mid = (r + l) / 2;
	_mergeSort(arr, l, mid);
	_mergeSort(arr, mid + 1, r);
	if (arr[mid] > arr[mid + 1])
		_merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {

	_mergeSort(arr, 0, n - 1);
}
