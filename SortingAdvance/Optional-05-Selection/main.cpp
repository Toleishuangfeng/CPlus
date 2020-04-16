#include<iostream>
#include<cassert>
#include"TestHelper.h"

using namespace std;

//partition 过程和快排的partition一样
//思考:双路快排和三路快排的能不能用在SelectionSort里
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

//求出arr[l...r]范围中第k小的数
template <typename T>
int _selection(T arr[],int l,int r,int k){
	
	if (l == r)return arr[l];

	//partition之后,arr[p]的正确位置在索引p上
	int p = _partition(arr, l, r);
	if (k == p) return arr[p];
	else if (k < p) return _selection(arr, l, p - 1, k);
	else return _selection(arr, p + 1, r, k);
}
// 寻找arr数组中第k小的元素
// 注意: 在我们的算法中, k是从0开始索引的, 即最小的元素是第0小元素, 以此类推
// 如果希望我们的算法中k的语意是从1开始的, 只需要在整个逻辑开始进行k--即可, 可以参考selection2
template<typename T>
int selection(T arr[], int n, int k) {
	assert(k >= 0 && k < n);
	srand(time(NULL));
	return _selection(arr, 0, n - 1, k);
}
// 寻找arr数组中第k小的元素, k从1开始索引, 即最小元素是第1小元素, 以此类推
template<typename T>
int selection2(T arr[], int n,int k) {

	return selection(arr , n, k - 1);
}
// 测试 selection算法
//仅限于不重复出现的
int main() {

    // 生成一个大小为n, 包含0...n-1这n个元素的随机数组arr
    int n = 100;
    int* arr = TestHelper::generatorRondomArray(n,0,n);
    TestHelper::shuffleArray(arr, n);

    // 验证selection算法, 对arr数组求第i小元素, 应该为i
    for (int i = 0; i < n; i++) {
        assert(selection(arr, n, i) == i);
        cout << "test " << i << " complete." << endl;
    }
    cout << "Test selection completed." << endl;

    delete[] arr;

    cout << endl;

    // 验证selection2算法
    arr = TestHelper::generateOrderedArray(n);
    TestHelper::shuffleArray(arr, n);

    // 对arr数组求第i小元素, 应该为i - 1 (在selection2中, 第k小元素的k是从1索引的)
    for (int i = 1; i <= n; i++) {
        assert(selection2(arr, n,i) == i - 1);
        cout << "test " << i << " complete." << endl;
    }
    cout << "Test selection2 completed." << endl;

    delete[] arr;

    return 0;
}