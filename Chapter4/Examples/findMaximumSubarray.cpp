#include <iostream>
#include <vector>

using namespace std;

struct SubSum {
	int low;
	int high;
	int maxSum;
};

SubSum findMaxCrossingSubarray(vector<int>, int, int, int);
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
	if (low == high) {
		SubSum crossSum;
		crossSum.low = low;
		crossSum.high = high;
		crossSum.maxSum = A[low];

		return crossSum;
	}
	else {
		int mid = (high + low) / 2;
		SubSum left = findMaximumSubarray(A, low, mid);
		SubSum right = findMaximumSubarray(A, mid + 1, high);
		SubSum cross = findMaxCrossingSubarray(A, low, mid, high);

		if (left.maxSum >= right.maxSum && left.maxSum >= cross.maxSum) {
			return left;
		}
		else if (right.maxSum >= left.maxSum && right.maxSum >= cross.maxSum) {
			return right;
		}
		else {
			return cross;
		}
	}
}

SubSum findMaxCrossingSubarray(vector<int> A, int low, int mid, int high) {
	int leftSum = INT_MIN;
	int sum = 0;
	int maxLeft = 0;
	SubSum crossSum;

	for (int i = mid; i >= low; --i) {
		sum += A[i];

		if (sum > leftSum) {
			leftSum = sum;
			maxLeft = i;
		}
	}

	int rightSum = INT_MIN;
	sum = 0;
	int maxRight = 0;

	for (int i = mid + 1; i <= high; ++i) {
		sum += A[i];

		if (sum > rightSum) {
			rightSum = sum;
			maxRight = i;
		}
	}

	crossSum.low = maxLeft;
	crossSum.high = maxRight;
	crossSum.maxSum = leftSum + rightSum;

	return crossSum;
}
