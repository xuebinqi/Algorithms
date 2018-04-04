#include <iostream>
#include <vector>

#define MAX 10000;

using namespace std;

void mergeSentinels(int *A, int p, int q, int  r);
void mergeSort(int *A, int p, int q);
void mergeNoSentinels(int *A, int p, int q, int r);

int main() {
	int vec[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	mergeSort(vec, 0, 9);

	for (int i = 0; i < 10; ++i) {
		cout << vec[i] << " ";
	}

	cout << endl;

	system("pause");
	return 0;
}

void mergeSentinels(int* A, int p, int q, int  r) {
	int n1 = q - p + 1;
	int n2 = r - q;

	int *lA = new int[n1 + 1];
	int *rA = new int[n2 + 1];
	for (int i = 0; i < n1; ++i) {
		lA[i] = A[p + i];
	}

	for (int i = 0; i < n2; ++i) {
		rA[i] = A[q + i + 1];
	}

	lA[n1] = MAX;
	rA[n2] = MAX;

	int i = 0, j = 0;

	for (int k = p; k <= r; ++k) {
		if (lA[i] <= rA[j]) {
			A[k] = lA[i];
			i++;
		}
		else {
			A[k] = rA[j];
			j++;
		}
	}


	delete []lA;
	delete []rA;
}
void mergeSort(int* A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);

	//	mergeSeminal(A, p, q, r);
		mergeNoSentinels(A, p, q, r);
	}
}

void mergeNoSentinels(int *A, int p, int q, int r) {
	int n1 = q - p;
	int n2 = r - q - 1;

	int *rA = new int[n1 + 1];
	int *lA = new int[n2 + 1];

	for (int i = 0; i <= n1; ++i) {
		lA[i] = A[p + i];
	}

	for (int i = 0; i <= n2; ++i) {
		rA[i] = A[q + i + 1];
	}

	int i = 0, j = 0;
	for (int k = p; k <= r; ++k) {
		if (lA[i] <= rA[j] && i <= n1 && j <= n2) {
			A[k] = lA[i++];
		}
		else if (lA[i] > rA[j] && i <= n1 && j <= n2) {
			A[k] = rA[j++];
		}
		else if (i > n1) {
			A[k] = rA[j++];
		}
		else if (j > n2) {
			A[k] = lA[i++];
		}
	}
}