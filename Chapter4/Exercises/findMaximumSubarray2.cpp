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

	cout << "������������������Ϊ" << result.maxSum << endl;
	cout << "�������" << result.low + 1 << "��ʼ����"
		<< result.high + 1 << "����" << endl;


	system("pause");
	return 0;
}

SubSum findMaximumSubarray(vector<int> A, int low, int high) {
	SubSum maxSubarray;  // �������ȡ�����ֵ����Ϣ�����䣬���ֵ��
	maxSubarray.low = 0;
	maxSubarray.high = 0;
	maxSubarray.maxSum = INT_MIN;

	int maxSum = INT_MIN;
	int sum = 0;
	int leftIndex = low;
	int rightIndex = low;
	int flag = 0;

	// �����ж������е�Ԫ���Ƿ���ȫΪ����
	for (int i = low; i <= high; ++i) {
		if (A[i] < 0) {
			flag++;
		}
	}

	for (int i = low; i <= high; ++i) {
		sum += A[i];

		if (sum > maxSum) {  // �жϵ�ǰ���Ƿ�Ϊ���ֵ
			maxSum = sum;
			rightIndex = i;

		}

		if (sum < 0) {
			sum = 0;
			leftIndex = i + 1;
		}
	}


	// �����Ľ����ֵ
	maxSubarray.high = rightIndex;

	// �������flag == high�� ��ʾ������Ԫ�ض�Ϊ������ �������±����
	if (flag == high + 1) {    
		maxSubarray.low = rightIndex;
	}
	else {
		maxSubarray.low = leftIndex;
	}	
	maxSubarray.maxSum = maxSum;

	return maxSubarray;
}
