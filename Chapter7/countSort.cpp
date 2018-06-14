#include <iostream>

using namespace std;

void countSort(int*, int*, int k, int len);
int max(int *, int len);

int a[] = { 6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2 };
int len = sizeof(a) / sizeof(int);
int *b = new int[len];

int main() {
	
	int key = max(a, len);
	countSort(a, b, key, len);

	for (int i = 0; i < len; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;

	delete[]b;

	system("pause");
	return 0;
}

void countSort(int *a, int *b, int k, int len) {
	int *c = new int[k + 1];
	for (int i = 0; i <= k; ++i) {
		c[i] = 0;
	}

	// ������C�м��㽫����A�е�ÿ��Ԫ�صĸ���
	for (int i = 0; i < len; ++i) {
		c[a[i]] += 1;
	}

	// ����C[i]�а���С�ڵ���i��Ԫ�صĸ���
	for (int i = 1; i <= k; ++i) {
		c[i] = c[i] + c[i - 1];
	}

	for (int i = len - 1; i >= 0; --i) {
		b[c[a[i]] - 1] = a[i];
		c[a[i]] -= 1;
	}
	delete[]c;
}

int max(int *a, int len) {
	int key = a[0];
	for (int i = 1; i < len; ++i) {
		if (key < a[i]) {
			key = a[i];
		}
	}

	return key;
}