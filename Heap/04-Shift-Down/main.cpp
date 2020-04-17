#include<iostream>
#include<cassert>
#include<ctime>

using namespace std;

template<typename Item>
class MaxHeap {
private:
	Item* data;
	int count;
	int capacity;

	void shiftUp(int k) {
		while (k > 1 && data[k / 2] < data[k]) {
			swap(data[k / 2],data[k]);
			k /= 2;
		}
	}

	void shiftDown(int k) {
		while (k*2<=count)
		{
			int j = 2 * k;//在此轮循环中,data[k]和data[j]交换位置
			if (j + 1 <= count && data[j + 1] > data[j])
				j++;
			//data[j]是data[2*k]和data[2*k+1]中的最大值
			if (data[k] >= data[j]) break;
			swap(data[k], data[j]);
			k = j;
		}
	}
public:
	MaxHeap(int capacity)
	{
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;

	}
	~MaxHeap()
	{
		delete[] data;
	}

	int size() {
		return count;
	}

	bool isEmpty() {
		return count == 0;
	}
	//在最大堆中插入一个元素
	void insert(Item item) {
		assert(count + 1 <= capacity);
		data[count + 1] = item;
		count++;
		//插入元素后,向上进行调整最大堆
		shiftUp(count);
	}
	Item extractMax() {

		assert(count > 0);
		Item ret = data[1];
		swap(data[1], data[count]);
		count--;
		shiftDown(1);
		return ret;
	}

	Item getMax() {
		assert(count > 0);
		return data[1];
	}
};
int main() {

	MaxHeap<int> maxHeap = MaxHeap<int>(100);

	srand(time(NULL));
	int n = 100;
	for (int i = 0; i < n; i++) {
		maxHeap.insert(rand() % n);
	}
	int* arr = new int[n];

	//将maxHeap中的数据逐渐使用extractMax取出
	//取出顺序应该按照从大到小的顺序
	for (int i = 0; i < n; i++) {
		arr[i] = maxHeap.extractMax();
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n-1; i++) {
		assert(arr[i] >= arr[i + 1]);
	}
	delete[] arr;
	return 0;
}