#include<iostream>
#include<ctime>
#include<algorithm>

using namespace std;

template<typename T>
void _quickSort3Ways(T arr[], int l, int r) {

	if (l >= r) return;
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	int lt = l;//arr[l+1....lt]<v
	int gt = r + 1;//arr[gt....r]>v
	int i = l + 1;//arr[lt+1....i]==v
	while (i < gt) {
		if (arr[i] < v) {
			swap(arr[i], arr[lt + 1]);
			i++; lt++;
		}
		else if (arr[i] > v) {
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else {//arr[i]==v
			i++;
		}
	}
	swap(arr[l], arr[lt]);
	_quickSort3Ways(arr, l, lt - 1);
	_quickSort3Ways(arr, gt, r);
}

template<typename T>
void QuickSort3Ways(T arr[], int n) {

	srand(time(NULL));
	_quickSort3Ways(arr, 0, n - 1);
}