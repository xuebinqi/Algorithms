#include <iostream>
#include <vector>

using namespace std;

// 堆排序算法实现
void heapSort(vector<int>& );

// 保持堆一直是最大堆
void maxHeapify(vector<int>&, int, int);

// 建立最大堆
void buildMaxHeap(vector<int>& );

// 获取左子节点
int leftIndex(int);

// 获取右子节点
int rightIndex(int);

int main() {
	vector<int> arr{ 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

	buildMaxHeap(arr);
	heapSort(arr);

	for (auto i : arr) {
		cout << i << " , ";
	}

	cout << endl;

	system("pause");
	return 0;
}

/* 堆排序算法的核心是：最大堆的根节点是最大值，我们将最大值与堆最后面的值交换，
   然后将堆的长度减一，这样形成一个新堆，通过maxHeapify函数，将这个新堆变换成
   新的最大堆，就这样循环，直到最后一个元素*/
void heapSort(vector<int>& arr) {
	int length = arr.size() - 1;
	int temp = 0;

	for (int i = length; i >= 1; --i) {
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		length--;
		maxHeapify(arr, 0, length);
	}
}

/*maxHeapify函数的作用：将以i为根节点的堆变换成最大堆*/
void maxHeapify(vector<int>& arr, int i, int length) {
	int heapSize = length;
	int largest = 0;
	int left = 0, right = 0;
	int temp = 0;
	left = leftIndex(i);
	right = rightIndex(i);

	if (left <= heapSize && arr[i] < arr[left]) {
		largest = left;
	}
	else {
		largest = i;
	}

	if (right <= heapSize && arr[largest] < arr[right]) {
		largest = right;
	}
	
	if (largest != i) {
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;

		maxHeapify(arr, largest, heapSize);
	}
}

/* buildMaxHeap函数就是将初始数组变换成一个最大堆 */
void buildMaxHeap(vector<int>& arr) {
	int length = arr.size() - 1;
	for (int i = length / 2; i >= 0; --i) {
		maxHeapify(arr, i, length);
	}
}

int leftIndex(int i) {
	return 2 * i;
}
int rightIndex(int i) {
	return 2 * i + 1;
}

