#include<iostream>
#include<cassert>
#include<algorithm>
#include"SortTestHelper.h"

using namespace std;

template<typename T>
class IndexMaxHeap {
private:
	T* data;//����������е�����
	int* indexes;//����������е�����

	int count;
	int capacity;
	// ��������, ����֮��ıȽϸ���data�Ĵ�С���бȽ�, ��ʵ�ʲ�����������
	void shiftUp(int k) {
		while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
			swap(indexes[k / 2], indexes[k]);
			k /= 2;
		}
	}

	void shiftDown(int k) {
		while (2*k<count)
		{
			int j = 2 * k;
			if (j + 1 < count && data[indexes[j + 1]] > data[indexes[j]]) j++;
			if (data[indexes[k]] >= data[indexes[j]]) break;

			swap(indexes[j], indexes[k]);
			k = j;

		}
	}
public: 
	IndexMaxHeap(int capacity)
	{
		count = 0;
		data = new T[capacity + 1];
		indexes = new int[capacity + 1];
		this->capacity = capacity;
	}

	~IndexMaxHeap()
	{
		delete[]data;
		delete[]indexes;
	}

	int size() { return count; }
	bool isEmpty() { return count == 0; }
	//������������в���һ���µ�Ԫ��,����Ϊi,��ֵΪe
	//�����i���û�����,�Ǵ�0��ʼ��
	void insert(int i,T e){
		//Ҫע��߽�����
		assert(count + 1 <= capacity);
		assert(i + 1 >= 1 && i + 1 <= capacity);

		i++;
		data[i] = e;
		
		count++;
		indexes[count] = i;

		shiftUp(count);
	}
	//�������������ȡ���Ѷ�Ԫ��
	T extractMax() {
		assert(count > 0);
		T ret = data[indexes[1]];
		swap(indexes[1], indexes[count]);
		count--;
		shiftDown(1);
		return ret;
	}
	//�������������ȡ���Ѷ�Ԫ�ص�����
	int  extractMaxIndex() {
		assert(count > 0);
		int ret = indexes[1] - 1;
		swap(indexes[1], indexes[count]);
		count--;
		shiftDown(1);
		return ret;
	}
	//��ȡ��������ѵĶѶ�Ԫ��
	T getMax() {
		assert(count > 0);
		return data[indexes[1]];
	}
	//��ȡ����������еĶԶ�Ԫ�ص�����
	int getMaxIndex() {
		assert(count > 0);
		return indexes[1] - 1;
	}
	//������������е�i��Ԫ�ظ�ΪnewItem
	void change(int i, T newItem) {
		i++;
		data[i] = newItem;
		//�ҵ�����indexes[j]=i,j��ʾdata[i]�ڶ��е�λ��
		for (int j = 1; j <= count; j++) {
			if (indexes[j] == i) {
				shiftUp(j);
				shiftDown(j);
				return;
			}
		}
	}
	//�����������е���������index
	bool testIndexes() {
		int* copyIndexes = new int[count + 1];

		for (int i = 0; i <= count; i++) {
			copyIndexes[i] = indexes[i];
		}

		copyIndexes[0] = 0;
		std::sort(copyIndexes, copyIndexes + count + 1);

		//�ڶ��������е���������[�����,Ӧ���ǰ�˳���ŵ�����
		bool res = true;
		for (int i = 1; i <= count; i++) {
			if (copyIndexes[i - 1] + 1 != copyIndexes[i]) {
				res = false;
				break;
			}
		}
		delete[] copyIndexes;
		if (!res) {
			cout << "ERROE!" << endl;
			return false;
		}
		return true;
	}
};
// ʹ����������ѽ��ж�����, ����֤���ǵ���������ѵ���ȷ��
// ��������ѵ���Ҫ���ò�����������, ����������ʹ������ֻ��Ϊ����֤���ǵ����������ʵ�ֵ���ȷ��
// �ں�����ͼ����, ��������С�������㷨, �������·���㷨, ���Ƕ���Ҫʹ�������ѽ����Ż�:)
template <typename T>
void heapSortUsingIndexMaxHeap(T arr[], int n) {
	IndexMaxHeap<T> indexMaxHeap = IndexMaxHeap<T>(n);
	for (int i = 0; i < n; i++) {
		indexMaxHeap.insert(i, arr[i]);
	}
	assert(indexMaxHeap.testIndexes());

	for (int i = n - 1; i >= 0; i--)
		arr[i] = indexMaxHeap.extractMax();
}
int main() {
	int n = 10000;
	int* arr = SortTestHelper::generatorRondomArray(n, 0, n);
	SortTestHelper::testSort("Heap Sort Using Index-Max-Heap", heapSortUsingIndexMaxHeap, arr, n);
	delete[] arr;

	return 0;
}