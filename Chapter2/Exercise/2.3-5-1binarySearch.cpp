#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &a, int value);

int main() {
	vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int value = 0;
	cout << "Please inout the number you want to search: ";
	cin >> value;

	int index = binarySearch(a, value);

	if (index == -1) {
		cout << "the number you research is not exit" << endl;
	}
	else {
		cout << "the number you research is in the " 
			 << index << "'th position" << endl;
	}
	system("pause");
	return 0;
}

int binarySearch(vector<int> &a, int value) {
	int high = a.size() - 1;
	int low = 0;

	int middle = 0;
	while (low <= high) {
		middle = (low + high) / 2;
		if (a[middle] < value) {
			low = middle + 1;
		}
		else if (a[middle] > value) {
			high = middle - 1;
		}
		else {
			return middle;
		}
	}

	return -1;
}