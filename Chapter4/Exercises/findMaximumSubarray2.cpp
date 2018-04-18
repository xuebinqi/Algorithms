#include <iostream>
#include <vector>

using namespace std;

struct SubSum {
	int low;
	int high;
	int maxSum;
};

SubSum findMaximumSubarray(vector<int>, int, int);

int main() {
	vector<int> A{ -13, -3, -25, -20, -3, -16, -23, -18, -20, -7, -12, -5, -22, -15, -4, -7 };
	int low = 0;
	int high = A.size();

	SubSum result = findMaximumSubarray(A, low, high - 1);

	cout << "该数组中子数组最大和为" << result.maxSum << endl;
	cout << "从数组的" << result.low + 1 << "开始，到"
		<< result.high + 1 << "结束" << endl;


	system("pause");
	return 0;
}

SubSum findMaximumSubarray(vector<int> A, int low, int high) {
	SubSum maxSubarray;  // 用来标记取得最大值的信息（区间，最大值）
	maxSubarray.low = 0;
	maxSubarray.high = 0;
	maxSubarray.maxSum = INT_MIN;

	int maxSum = INT_MIN;
	int sum = 0;
	int leftIndex = low;
	int rightIndex = low;
	int flag = 0;

	// 用来判断数组中的元素是否是全为负数
	for (int i = low; i <= high; ++i) {
		if (A[i] < 0) {
			flag++;
		}
	}

	for (int i = low; i <= high; ++i) {
		sum += A[i];

		if (sum > maxSum) {  // 判断当前和是否为最大值
			maxSum = sum;
			rightIndex = i;

		}

		if (sum < 0) {
			sum = 0;
			leftIndex = i + 1;
		}
	}


	// 给最后的结果赋值
	maxSubarray.high = rightIndex;

	// 如果数组flag == high， 表示数组中元素都为负数， 则左右下标相等
	if (flag == high + 1) {    
		maxSubarray.low = rightIndex;
	}
	else {
		maxSubarray.low = leftIndex;
	}	
	maxSubarray.maxSum = maxSum;

	return maxSubarray;
}
