#include<iostream>
#include<cassert>
#include<ctime>

using namespace std;
template<typename T>
class MinHeap {

private:
	T* data;
	int count;
	int capacity;

	void shiftUp(int k) {

		while (k > 1 && data[k / 2] > data[k]) {
			swap(data[k / 2], data[k]);
			k /= 2;
		}

	}

	void shiftDown(int k) {
		while (2 * k <= count) {
			int j = 2 * k;
			if (j + 1 <= count && data[j + 1] < data[j])j++;
			if (data[k] <= data[j]) break;
			swap(data[k], data[j]);
			k = j;
		}
	}

public:
	MinHeap(int capacity){
		data = new T[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	~MinHeap()
	{
		delete[] data;
	}

	int size() { return count; }
	bool isEmpty() { return count == 0; }

	void insert(T item) {
		assert(count + 1 <= capacity);
		data[count + 1] = item;
		shiftUp(count + 1);
		count++;
	}

	T extractMin() {
		assert(count > 0);
		T res = data[1];
		swap(data[1], data[count]);
		count--;
		shiftDown(1);
		return res;
	}
	T getMin() {
		assert(count > 0);
		return data[1];
	}
};