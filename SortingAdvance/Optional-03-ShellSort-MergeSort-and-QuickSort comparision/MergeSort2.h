#include<iostream>

using namespace std;

template <typename T>
void _merge2(T arr[], T aux[],int l, int mid, int r) {

	
	for (int i = l; i <= r; i++) {
		aux[i ] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = aux[j];
			j++;
		}
		else if (j > r) {
			arr[k] = aux[i]; i++;
		}
		else if (aux[i] < aux[j]) {
			arr[k] = aux[i]; i++;
		}
		else {
			arr[k] = aux[j ]; j++;
		}


	}
}

template<typename T>
void _mergeSort2(T arr[], T aux[],int l, int r) {

	if (l >= r)return;

	int mid = (r - l) / 2 + l;
	_mergeSort2(arr,aux, l, mid);
	_mergeSort2(arr,aux, mid + 1, r);
	if (arr[mid] > arr[mid + 1])
		_merge2(arr, aux,l, mid, r);

}
//自顶向下的归并排序,优化
//一次性申请aux空间,并将这个辅助空间以参数的形式传递给完成归并排序的各个子函数
template <typename T>
void mergeSort2(T arr[], int n) {
	T* aux = new T[n];
	_mergeSort2(arr,aux, 0, n - 1);
	delete[] aux;
}