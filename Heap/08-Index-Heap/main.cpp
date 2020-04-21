#include<iostream>
#include<cassert>
#include<algorithm>
#include"SortTestHelper.h"

using namespace std;

template<typename T>
class IndexMaxHeap {
private:
	T* data;//最大索引堆中的数据
	int* indexes;//最大索引堆中的索引

	int count;
	int capacity;
	// 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
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
	//向最大索引堆中插入一个新的元素,索引为i,数值为e
	//传入的i对用户而言,是从0开始的
	void insert(int i,T e){
		//要注意边界问题
		assert(count + 1 <= capacity);
		assert(i + 1 >= 1 && i + 1 <= capacity);

		i++;
		data[i] = e;
		
		count++;
		indexes[count] = i;

		shiftUp(count);
	}
	//从最大索引堆中取出堆顶元素
	T extractMax() {
		assert(count > 0);
		T ret = data[indexes[1]];
		swap(indexes[1], indexes[count]);
		count--;
		shiftDown(1);
		return ret;
	}
	//从最大索引堆中取出堆顶元素的索引
	int  extractMaxIndex() {
		assert(count > 0);
		int ret = indexes[1] - 1;
		swap(indexes[1], indexes[count]);
		count--;
		shiftDown(1);
		return ret;
	}
	//获取最大索引堆的堆顶元素
	T getMax() {
		assert(count > 0);
		return data[indexes[1]];
	}
	//获取最大索引堆中的对顶元素的索引
	int getMaxIndex() {
		assert(count > 0);
		return indexes[1] - 1;
	}
	//将最大索引堆中的i的元素改为newItem
	void change(int i, T newItem) {
		i++;
		data[i] = newItem;
		//找到索引indexes[j]=i,j表示data[i]在堆中的位置
		for (int j = 1; j <= count; j++) {
			if (indexes[j] == i) {
				shiftUp(j);
				shiftDown(j);
				return;
			}
		}
	}
	//测试索引堆中的索引数组index
	bool testIndexes() {
		int* copyIndexes = new int[count + 1];

		for (int i = 0; i <= count; i++) {
			copyIndexes[i] = indexes[i];
		}

		copyIndexes[0] = 0;
		std::sort(copyIndexes, copyIndexes + count + 1);

		//在对索引堆中的索引进行[排序后,应该是按顺序排的索引
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
// 使用最大索引堆进行堆排序, 来验证我们的最大索引堆的正确性
// 最大索引堆的主要作用不是用于排序, 我们在这里使用排序只是为了验证我们的最大索引堆实现的正确性
// 在后续的图论中, 无论是最小生成树算法, 还是最短路径算法, 我们都需要使用索引堆进行优化:)
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