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
	vector<int> A{ 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
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
	int tempSum;
	int sum;
	int tempi;
	int tempj;
	for (int i = low - 1; i < high; ++i) {    // 这里i从-1开始是为了方便后面和的相加
		sum = 0;        // 用来存储从第i个元素开始的和
		tempSum = INT_MIN;     // 用来存储从第i个元素开始的和的最大值
		tempj = 0;     // 用来标记取得最大值范围的右区间
		tempi = 0;     // 用来标记取得最大值范围的左区间

		for (int j = i + 1; j <= high; ++j) {
			sum += A[j];

			if (sum > tempSum) {  // 判断当前和是否为最大值
				tempSum = sum;
				tempi = i + 1;
				tempj = j;
			}
		}

		if (maxSubarray.maxSum < tempSum) {  // 用来判断最终的最大值
			maxSubarray.low = tempi;
			maxSubarray.high = tempj;
			maxSubarray.maxSum = tempSum;
		}
	}

	return maxSubarray;
}