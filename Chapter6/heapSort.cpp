#include <iostream>
#include <vector>

using namespace std;

// �������㷨ʵ��
void heapSort(vector<int>& );

// ���ֶ�һֱ������
void maxHeapify(vector<int>&, int, int);

// ��������
void buildMaxHeap(vector<int>& );

// ��ȡ���ӽڵ�
int leftIndex(int);

// ��ȡ���ӽڵ�
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

/* �������㷨�ĺ����ǣ����ѵĸ��ڵ������ֵ�����ǽ����ֵ���������ֵ������
   Ȼ�󽫶ѵĳ��ȼ�һ�������γ�һ���¶ѣ�ͨ��maxHeapify������������¶ѱ任��
   �µ����ѣ�������ѭ����ֱ�����һ��Ԫ��*/
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

/*maxHeapify���������ã�����iΪ���ڵ�Ķѱ任������*/
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

/* buildMaxHeap�������ǽ���ʼ����任��һ������ */
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

