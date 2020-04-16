#include<iostream>
#include"TestHelper.h"

using namespace std;

long long _merge(int arr[], int l, int mid, int r) {

	int* aux = new int[r - l + 1];
	for (int i = l; i <= r; i++) {
		aux[i - l] = arr[i];
	}

	long long res = 0;

	//��ʼ��
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
		else if (aux[i - l] <= aux[j - l]) {//��벿��<=�Ұ벿��
			arr[k] = aux[i - l];
			i++;

		}
		else {
			arr[k] = aux[j - l];
			j++;

			//// ��ʱ, ��Ϊ�Ұ벿��k��ָ��Ԫ��С
            // ���Ԫ�غ���벿�ֵ�����δ�����Ԫ�ض���������������
            // ��벿�ִ�ʱδ�����Ԫ�ظ���Ϊ mid - i+ 1
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

	//����1:�����������
	cout << "Test Inversion Count for Random Array ,n=" << n <<":"<< endl;

	int* arr = TestHelper::generatorRondomArray(n, 0, n);
	cout << inversionCount(arr, n) << endl;
	delete[] arr;
	
	//����2:������ȫ���������
	cout << "Test Inversion Count for Ordered Array ,n=" << n <<" :"<< endl;

	arr = TestHelper::generateOrderedArray(n);
	cout << inversionCount(arr, n) << endl;
	delete[] arr;

	//����3:������ȫ���������
	//���Ӧ��ΪN*(N-1)/2
	cout << "Test Inversion Count for Inversed Array,n=" << n << " :" << endl;
	arr = TestHelper::generateInversedArray(n);
	cout << inversionCount(arr, n);
	delete[] arr;
	return 0;
}