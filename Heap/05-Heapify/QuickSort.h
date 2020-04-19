#include<iostream>
#include<ctime>
#include<algorithm>



using namespace std;
template<typename T>
int partition(T arr[], int l, int r) {
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	int j = l;
	for (int k = 1+l; k <= r; k++) {
		if (arr[k] < v) {
			j++;
			swap(arr[k], arr[j]);
		}
				
	}
	swap(arr[l], arr[j]);
	return j;
}
template<typename T>
void _quickSort(T arr[], int l, int r) {
	
	if (l > r) return;
	int p = partition(arr, l, r);
	_quickSort(arr, l, p - 1);
	_quickSort(arr, p + 1, r);
}
template<typename T>
void quickSort(T arr[], int n) {
	srand(time(NULL));
	_quickSort(arr, 0, n - 1);
}