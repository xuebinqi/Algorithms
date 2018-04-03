/**********************************************************************
 * 选择排序：先找出数组中最小元素与数组A[0]，交换，然后找出次小元素，与A[1]*
 *交换，依次类推；                                                     *
 *在写代码时出现了一个bug，即在之前没有用flag标记，导致A[min]中的元素被最后*
 *一个元素代替。                                                       *
***********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <int> A{ 10, 20, 8, 40, 60, 5, 4, 100, 2, 50 };

	int len = A.size();
	int key = 0;
	int min = 0;
	bool flag = false; 
	for (int i = 0; i < len; ++i) {
		key = A[i];
		int j = i + 1;                     

		while (j < len) {   // 找到数组中最小的值
			if (key > A[j]) {
				key = A[j];
				min = j;   // min变量用来标记当找到最小值时，最小值所在位置
				flag = true;  //用于标记min的值是否发生改变
			}
			++j;         
		}
		
		if (flag == true) {
			A[min] = A[i];
			A[i] = key;
			flag = false;
		}
		
	}

	for (auto i = A.cbegin(); i != A.cend(); ++i) {
		cout << *i << endl;
	}

	system("pause");
	return 0;
}