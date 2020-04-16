#include<iostream>
#include<cassert>
#include"TestHelper.h"

using namespace std;

//partition ���̺Ϳ��ŵ�partitionһ��
//˼��:˫·���ź���·���ŵ��ܲ�������SelectionSort��
template<typename T>

int _partition(T arr[], int l, int r) {
	int p = rand() % (r - l + 1) + l;
	swap(arr[l], arr[p]);

	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < arr[l]) {
			j++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

//���arr[l...r]��Χ�е�kС����
template <typename T>
int _selection(T arr[],int l,int r,int k){
	
	if (l == r)return arr[l];

	//partition֮��,arr[p]����ȷλ��������p��
	int p = _partition(arr, l, r);
	if (k == p) return arr[p];
	else if (k < p) return _selection(arr, l, p - 1, k);
	else return _selection(arr, p + 1, r, k);
}
// Ѱ��arr�����е�kС��Ԫ��
// ע��: �����ǵ��㷨��, k�Ǵ�0��ʼ������, ����С��Ԫ���ǵ�0СԪ��, �Դ�����
// ���ϣ�����ǵ��㷨��k�������Ǵ�1��ʼ��, ֻ��Ҫ�������߼���ʼ����k--����, ���Բο�selection2
template<typename T>
int selection(T arr[], int n, int k) {
	assert(k >= 0 && k < n);
	srand(time(NULL));
	return _selection(arr, 0, n - 1, k);
}
// Ѱ��arr�����е�kС��Ԫ��, k��1��ʼ����, ����СԪ���ǵ�1СԪ��, �Դ�����
template<typename T>
int selection2(T arr[], int n,int k) {

	return selection(arr , n, k - 1);
}
// ���� selection�㷨
//�����ڲ��ظ����ֵ�
int main() {

    // ����һ����СΪn, ����0...n-1��n��Ԫ�ص��������arr
    int n = 100;
    int* arr = TestHelper::generatorRondomArray(n,0,n);
    TestHelper::shuffleArray(arr, n);

    // ��֤selection�㷨, ��arr�������iСԪ��, Ӧ��Ϊi
    for (int i = 0; i < n; i++) {
        assert(selection(arr, n, i) == i);
        cout << "test " << i << " complete." << endl;
    }
    cout << "Test selection completed." << endl;

    delete[] arr;

    cout << endl;

    // ��֤selection2�㷨
    arr = TestHelper::generateOrderedArray(n);
    TestHelper::shuffleArray(arr, n);

    // ��arr�������iСԪ��, Ӧ��Ϊi - 1 (��selection2��, ��kСԪ�ص�k�Ǵ�1������)
    for (int i = 1; i <= n; i++) {
        assert(selection2(arr, n,i) == i - 1);
        cout << "test " << i << " complete." << endl;
    }
    cout << "Test selection2 completed." << endl;

    delete[] arr;

    return 0;
}