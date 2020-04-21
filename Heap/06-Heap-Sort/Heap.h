#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

template<typename T>
class MaxHeap {

private:
	T* data;
	int count;
	int capacity;
	void shiftUp(int k) {
		while (k > 1 && data[k/2]<data[k]) {
			swap(data[k / 2], data[k]);
			k /= 2;
		}
	}
	void shiftDown(int k) {
		while (2 * k <= count) {
			int j = 2 * k;
			if (j + 1 <= count && data[j + 1] > data[j]) j++;
			if (data[k] >= data[j])break;
			swap(data[k], data[j]);
			k = j;
		}
	}
public:
	MaxHeap(int capacity) {
		data = new T[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	MaxHeap(T arr[], int n) {
		data = new T[n + 1];
		capacity = n;
		for (int i = 0; i < n; i++) {
			data[i + 1] = arr[i];
		}
		count = n;
		for (int i = count / 2; i >= 1; i--) {
			shiftDown(i);
		}
	}

	~MaxHeap()
	{
		delete[] data;
	}

	int size() { return count; }
	bool isEmpty() { return count == 0; }
	void insert(T e) {
		assert(count + 1 <= capacity);
		data[count + 1] = e;
		count++;
		//向上调整
		shiftUp(count);
	}
	//取出堆顶元素
	T extractMax() {
		assert(count > 0);
		T ret = data[1];
		swap(data[1], data[count]);
		count--;
		shiftDown(1);
		return ret;
	}
	//获取最大堆中的堆顶元素
	T getMax() {
		assert(count > 0);
		return data[1];
	}

};