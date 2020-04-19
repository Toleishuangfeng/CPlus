#include<iostream>
#include<cassert>
using namespace std;

template <typename Item>
class MaxHeap {

private:
	Item* data;
	int count;
	int capacity;
	void shiftUp(int k) {
		while (k > 1 && data[k / 2] < data[k]) {
			swap(data[k], data[k / 2]);
			k /= 2;
		}
	}
	void shiftDown(int k) {
		while (2 * k <= count) {
			int j = 2 * k;
			if (j + 1 <= count && data[j + 1] > data[j]) j++;
			if (data[k] >= data[j]) break;
			swap(data[k], data[j]);
			k = j;
		}
	}
public:
	//构造函数,构造一个空堆,可容纳capacity个元素
	MaxHeap(int capacity)
	{
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	//构造函数,通过一个给定数组创造一个最大堆
	//构造堆的过程,时间复杂度为O(n)
	MaxHeap(Item arr[], int n) {
		data = new Item[n + 1];
		capacity = n;

		for (int i = 0; i < n; i++) {
			data[i] = arr[i];
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

	void insert(Item item) {
		assert(count + 1 <= capacity);

		data[count + 1] = item;
		count++;
		//插入一个元素后向上调整最大堆
		shiftUp(count);
	}

	//从最大堆中取出堆顶元素
	Item extractMax() {
		assert(count > 0);
		Item ret = data[1];
		swap(data[1], data[count]);
		count--;
		shiftDown(1);
		return ret;
	}

	//获取最大堆中的堆顶元素
	Item getMax() {
		assert(count > 0);
		return data[1];
	}

};
