#include<iostream>
#include<ctime>
#include<cassert>
#include<algorithm>

using namespace std;
template<typename T>
int _partition2(T arr[], int l, int r) {

	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	int i = l + 1;
	int j = r;
	while (true) {
		while (i <= r && arr[i] < v) { i++; }
		while (j >= l + 1 && arr[j] > v) { j--; }
		if (i > j) break;
		swap(arr[i], arr[j]);
		i++;
		j--;
		
	}
	swap(arr[l], arr[j]);
	return j;
}
template<typename T>
void _quickSort2Ways(T arr[], int l, int r) {
	if (l >= r)return;

	int p = _partition2(arr, l, r);
	_quickSort2Ways(arr, l, p - 1);
	_quickSort2Ways(arr, p + 1, r);

}

template<typename T>
void quickSort2Way(T arr[], int n) {

	srand(time(NULL));
	_quickSort2Ways(arr, 0, n - 1);

}
