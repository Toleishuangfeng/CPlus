#include<iostream>
#include<ctime>
using namespace std;


//对arr[l...r]进行partition操作
//结果返回p,使得arr[l...p-1]<arr[p];arr[p+1....r]>arr[p]
template<typename T>
int _partition(T arr[], int l, int r) {

	swap(arr[l], arr[rand() % (r - l + 1) + l]);

	T v = arr[l];

	int j = l;
	
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			j++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

template<typename T>
void _quickSort(T arr[], int l, int r) {

	if (l >= r)return;

	int p = _partition(arr, l, r);
	_quickSort(arr, l, p - 1);
	_quickSort(arr, p + 1, r);
}

template<typename T>
void quickSort(T arr[], int n) {

	srand(time(NULL));
	_quickSort(arr, 0, n - 1);
}