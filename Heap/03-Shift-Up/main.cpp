#include<iostream>
#include<ctime>
#include<algorithm>
#include<cassert>

using namespace std;

template<typename Item>
class MaxHeap {
private:
	Item* data;
	int count;
	int capacity;
	//k为当前插入的索引位置
	void shiftUp(int k) {
		//data[k/2]为父节点位置
		while (k>1&&data[k / 2] < data[k]) {
			swap(data[k / 2], data[k]);
			k /= 2;
		}
	}

public:
	MaxHeap(int capacity)
	{
		//只开了一次空间,要注意数组越界的问题,加入一个capacity
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

	void insert(Item item) {
		assert(count + 1 <= capacity);
		data[count + 1] = item;
		count++;
		//尝试向上移动
		shiftUp(count);
	}

public:
	//实现打印树状的堆结构
	void testPrint() {
		//只打印100及以内的元素个数
		if (size() > 100) {
			cout << "this print function can only work for less than 100 int ";
			return;
		}
		if (typeid(Item) != typeid(int)) {
			cout << "this print function can only work for int item";

			return;
		}
		cout << "The max heap size is:" << size() << endl;
		cout << "data in the max heap:" << endl;
		for (int i = 1; i <=size(); i++) {
			//testPrint要求堆中元素在[0...100]范围内
			assert(data[i] >= 0 && data[i] < 100);
			cout << data[i] << " ";
		}
		cout << endl << endl;
		
		int n = size();
		int max_level = 0;
		int number_per_level = 1;
		while (n > 0) {
			max_level += 1;
			n -= number_per_level;
			number_per_level *= 2;
		}

		int max_level_number = int(pow(2, max_level-1));
		int cur_tree_max_level_number = max_level_number;
		int index = 1;
		for (int level = 0; level < max_level; level++) {
			string line1 = string(max_level_number * 3 - 1, ' ');

			int cur_level_number = min(count - int(pow(2, level)) + 1, int(pow(2, level)));
			bool isLeft = true;
			for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++, index++) {
				putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
				isLeft = !isLeft;
			}
			cout << line1<<endl;

			if (level == max_level - 1)
				break;

			string line2 = string(max_level_number * 3 - 1, ' ');
			for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
				putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
			cout << line2 << endl;

			cur_tree_max_level_number /= 2;
		}	

	}
private:
	void putNumberInLine(int num, string& line, int index_cur_level, int cur_tree_width, bool isLeft) {

		int sub_tree_width = (cur_tree_width - 1) / 2;
		int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
		assert(offset + 1 < line.size());

		if (num >= 10) {
			line[offset + 0] = '0' + num / 10;
			line[offset + 1] = '0' + num % 10;
		}
		else {
			if (isLeft)
				line[offset + 0] = '0' + num;
			else
				line[offset + 1] = '0' + num;
		}
	}
	void putBranchInLine(string& line, int index_cur_level, int cur_tree_width) {

		int sub_tree_width = (cur_tree_width - 1) / 2;
		int sub_sub_tree_width = (sub_tree_width - 1) / 2;
		int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
		assert(offset_left + 1 < line.size());
		int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
		assert(offset_right < line.size());

		line[offset_left + 1] = '/';
		line[offset_right + 0] = '\\';
	}
};
int main() {
	MaxHeap<int> maxHeap = MaxHeap<int>(100);

	srand(time(NULL));
	for (int i = 0; i < 50; i++) {
		maxHeap.insert(rand() % 100);
	}
	maxHeap.testPrint();


	return 0;
}