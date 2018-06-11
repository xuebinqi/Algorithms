#include <iostream>
#include <algorithm>

using namespace std;

int a[12] = { 13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11 };

void quickSort(int *a, int p, int r);
int partition(int *a, int p, int q);


int main() {
	int len = sizeof(a) / sizeof(int);

	quickSort(a, 0, len - 1);

	for (int i = 0; i < len; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

void quickSort(int *a, int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);

		quickSort(a, p, q - 1);
		quickSort(a, q + 1, r);
	}
}

int partition(int *a, int p, int r) {
	int elem = a[r];
	int i = p - 1;

	for (int j = p; j < r; ++j) {
		if (a[j] <= elem) {
			i = i + 1;
			swap(a[i], a[j]);
		}
	}

	swap(a[i + 1], a[r]);

	return (i + 1);
}