#include<iostream>
#include"TestHelper.h"

using namespace std;

long long _merge(int arr[], int l, int mid, int r) {

	int* aux = new int[r - l + 1];
	for (int i = l; i <= r; i++) {
		aux[i - l] = arr[i];
	}

	long long res = 0;

	//初始化
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
		else if (aux[i - l] <= aux[j - l]) {//左半部分<=右半部分
			arr[k] = aux[i - l];
			i++;

		}
		else {
			arr[k] = aux[j - l];
			j++;

			//// 此时, 因为右半部分k所指的元素小
            // 这个元素和左半部分的所有未处理的元素都构成了逆序数对
            // 左半部分此时未处理的元素个数为 mid - i+ 1
			res += (long long)(mid - i + 1);
		}
	}
	delete[]aux;
	return res;
}

long long _inversionCount(int arr[], int l, int r) {
	if (l >= r)return 0;

	int mid = l + (r - l) / 2;
	long long res1 = _inversionCount(arr, l, mid);
	long long res2 = _inversionCount(arr, mid + 1, r);

	return res1 + res2 + _merge(arr, l, mid, r);
}

long long inversionCount(int arr[], int n) {
	return _inversionCount(arr, 0, n - 1);
}

int main() {

	int n = 10000;

	//测试1:测试随机数组
	cout << "Test Inversion Count for Random Array ,n=" << n <<":"<< endl;

	int* arr = TestHelper::generatorRondomArray(n, 0, n);
	cout << inversionCount(arr, n) << endl;
	delete[] arr;
	
	//测试2:测试完全有序的数组
	cout << "Test Inversion Count for Ordered Array ,n=" << n <<" :"<< endl;

	arr = TestHelper::generateOrderedArray(n);
	cout << inversionCount(arr, n) << endl;
	delete[] arr;

	//测试3:测试完全逆序的数组
	//结果应该为N*(N-1)/2
	cout << "Test Inversion Count for Inversed Array,n=" << n << " :" << endl;
	arr = TestHelper::generateInversedArray(n);
	cout << inversionCount(arr, n);
	delete[] arr;
	return 0;
}