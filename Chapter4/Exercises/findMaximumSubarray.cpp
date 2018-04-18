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
	int tempSum;
	int sum;
	int tempi;
	int tempj;
	for (int i = low - 1; i < high; ++i) {    // ����i��-1��ʼ��Ϊ�˷������͵����
		sum = 0;        // �����洢�ӵ�i��Ԫ�ؿ�ʼ�ĺ�
		tempSum = INT_MIN;     // �����洢�ӵ�i��Ԫ�ؿ�ʼ�ĺ͵����ֵ
		tempj = 0;     // �������ȡ�����ֵ��Χ��������
		tempi = 0;     // �������ȡ�����ֵ��Χ��������

		for (int j = i + 1; j <= high; ++j) {
			sum += A[j];

			if (sum > tempSum) {  // �жϵ�ǰ���Ƿ�Ϊ���ֵ
				tempSum = sum;
				tempi = i + 1;
				tempj = j;
			}
		}

		if (maxSubarray.maxSum < tempSum) {  // �����ж����յ����ֵ
			maxSubarray.low = tempi;
			maxSubarray.high = tempj;
			maxSubarray.maxSum = tempSum;
		}
	}

	return maxSubarray;
}