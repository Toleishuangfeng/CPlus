#include<iostream>
#include<cassert>
#include<algorithm>
#include"SortTestHelper.h"

using namespace std;

template <typename Item>
class IndexMaxHeap {
private:
	Item* data;
	int* indexes;
	int* reverse;//最大索引堆中的反向索引,reverse[i]=x表示索引i在x的位置

	int count;
	int capacity;
	void shiftUp(int k) {
		while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
			swap(data[indexes[k / 2]], data[indexes[k]]);
			k /= 2;
		}
	}
	void shiftDown(int k) {
		while (2 * k <= count) {
			int j = 2 * k;
			if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])
				j++;

			if (data[indexes[k]] >= data[indexes[j]])
				break;
			swap(data[indexes[k]], data[indexes[j]]);
			k = j;
		}
	}
public:
	IndexMaxHeap(int capacity)
	{
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		reverse = new int[capacity + 1];
		count = 0;
		this->capacity = capacity;

	}
	~IndexMaxHeap()
	{
		delete[] data;
		delete[]indexes;
		delete[] reverse;
	}

	int size() { return count;}
	bool isEmpty() { return count == 0; }

	void insert(int i, Item item) {
		assert(count + 1 <= capacity );
		assert(i + 1 >= 1 && i + 1 <= capacity);

		i++;
		data[i] = item;

		count++;
		indexes[count] = i;
		reverse[i] = count;
		shiftUp(count);
	}
	Item extractMax() {
		assert(count > 0);
		Item res = data[indexes[1]];
		swap(indexes[1], indexes[count]);
		reverse[indexes[count]] = 0;
		count--;
		if (count) {
			reverse[indexes[1]] = 1;
			shiftDown(1);
		}
		
		return res;
	}
	int extractMaxIndex() {
		assert(count > 0);

		int res = indexes[1] - 1;
		swap(indexes[1], indexes[count]);
		reverse[indexes[count]] = 0;
		count--;
		if (count) {
			reverse[indexes[1]] = 1;
			shiftDown(1);
		}
		
		return res;
	}

	Item getMax() {
		assert(count > 0);
		return data[indexes[1]];
	}
	int getMaxIndex() {
		assert(count > 0);
		return indexes[1] - 1;
	}

	//看索引元素i所在的位置是否有元素
	bool contain(int i) {
		assert(i + 1 > 1 && i + 1 <= capacity);
		return reverse[i + 1] != 0;
	}

	void change(int i, Item newitem) {
		assert(i >= 1 && i <= capacity);
		i++;
		data[i] = newitem;
		// 找到indexes[j] = i, j表示data[i]在堆中的位置
		// 之后shiftUp(j), 再shiftDown(j)
		/*for (int j = 1; j <= count, j++) {
			if (indexes[j] == i) {
				shiftUp(j);
				shiftDown(j);
				return;
			}
		}*/
		// 有了 reverse 之后,
		 // 我们可以非常简单的通过reverse直接定位索引i在indexes中的位置
		shiftUp(reverse[i]);
		shiftDown(reverse[i]);
	}
	// 测试索引堆中的索引数组index和反向数组reverse
	// 这个测试在向堆中插入元素以后, 不进行extract操作有效
	bool testIndexesAndReverseIndexes() {
		int* copyIndexes = new int[count + 1];
		int* copyReverseIndexes = new int[count + 1];

		for (int i = 0; i <= count; i++) {
			copyIndexes[i] = indexes[i];
			copyReverseIndexes[i] = reverse[i];
		}

		copyIndexes[0] = copyReverseIndexes[0] = 0;
		std::sort(copyIndexes, copyIndexes + count + 1);
		std::sort(copyReverseIndexes, copyReverseIndexes + count + 1);

		// 在对索引堆中的索引和反向索引进行排序后,
		// 两个数组都应该正好是1...count这count个索引
		bool res = true;
		for (int i = 1; i <= count; i++) {
			if (copyIndexes[i - 1] + 1 != copyIndexes[i] || copyReverseIndexes[i - 1] + 1 != copyReverseIndexes[i]) {
				res = false;
				break;
			}
		}

		delete[]copyIndexes;
		delete[]copyReverseIndexes;

		if (!res) {
			cout << "ERRO 1!" << endl;
			return false;
		}

		for (int i = 1; i <= count; i++) {
			if (reverse[indexes[i]] != i) {
				cout << "ERROR 21" << endl;
				return false;
			}
		}
		return true;
	}
};

template<typename T>
void heapSortUsingIndexMaxHeap(T arr[], int n) {

	IndexMaxHeap<T> indexMaxHeap = IndexMaxHeap<T>(n);
	for (int i = 0; i < n; i++) {
		indexMaxHeap.insert(i,arr[i]);
	}
	assert(indexMaxHeap.testIndexesAndReverseIndexes());

	for (int i = n - 1; i >= 0; i--) {
		arr[i] = indexMaxHeap.extractMax();
	}
}

int main() {


	int n = 100000;
	int* arr = SortTestHelper::generatorRondomArray(n, 0, n);
	SortTestHelper::testSort("Heap Sort Using Index-Max-Heap", heapSortUsingIndexMaxHeap, arr, n);
	delete[]arr;
	return 0;
}