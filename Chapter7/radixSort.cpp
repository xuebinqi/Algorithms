#include<iostream>
#include<malloc.h>

using namespace std;

/*
#define   MAXSIZE   10000

int getDigit(int x, int d);
void  printArr(int ar[], int n);
void lsdradixSort(int arr[], int begin, int end, int d);

int  main() {
	int  br[10] = { 20, 80, 90, 589, 998, 965, 852, 123, 456, 789 };
	cout << "ԭ�������£�" << endl;
	printArr(br, 10);

	lsdradixSort(br, 0, 9, 3);

	cout << "������������£�" << endl;
	printArr(br, 10);

	system("pause");
	return 0;
}

int getDigit(int x, int d) {
	int a[] = { 1, 1, 10, 100 };   //�����λ������������ֻҪ��λ�������ˡ�
	return (x / a[d]) % 10;
}

void  printArr(int ar[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << ar[i] << " ";
	}
	cout << endl;
}
void lsdradixSort(int arr[], int begin, int end, int d) {
	const int radix = 10;
	int count[radix], i, j;

	int *bucket = (int*)malloc((end - begin + 1)*sizeof(int));  //����Ͱ�Ŀռ俪��   

																//���շ����׼���ν����������
	for (int k = 1; k <= d; ++k) {
		//�ÿ�
		for (i = 0; i < radix; i++) {
			count[i] = 0;
		}
		//ͳ�Ƹ���Ͱ����ʢ���ݸ���
		for (i = begin; i <= end; i++) {
			count[getDigit(arr[i], k)]++;
		}
		//count[i]��ʾ��i��Ͱ���ұ߽�����
		for (i = 1; i < radix; i++) {
			count[i] = count[i] + count[i - 1];
		}
		//����������װ��Ͱ(ע��װ��ʱ��ķ��似��)
		for (i = end; i >= begin; --i)        //����Ҫ��������ɨ�裬��֤�����ȶ���   
		{
			j = getDigit(arr[i], k);        //����ؼ���ĵ�kλ�����֣� ���磺576�ĵ�3λ��5   
			bucket[count[j] - 1] = arr[i]; //�����Ӧ��Ͱ�У�count[j]-1�ǵ�j��Ͱ���ұ߽����� 
			--count[j];               //��ӦͰ��װ������������һ  
		}

		//ע�⣺��ʱcount[i]Ϊ��i��Ͱ��߽�  

		//�Ӹ���Ͱ���ռ�����
		for (i = begin, j = 0; i <= end; ++i, ++j) {
			arr[i] = bucket[j];
		}
	}

	free(bucket);
}



ԭ�������£�
20 80 90 589 998 965 852 123 456 789
������������£�
20 80 90 123 456 589 789 852 965 998

*/

int getDigital(int arrValue, int digital);
void printArr(int *arr, int size);
void radixSort(int *arr, int begin, int end, int digital);

int main() {
	int arr[] = { 123, 222, 223, 224, 567, 432, 122, 666, 456, 345, 879, 100 };
	int len = sizeof(arr) / sizeof(int);

	radixSort(arr, 0, len - 1, 3);

	printArr(arr, len - 1);

	system("pause");
	return 0;
}

int getDigital(int arrValue, int digital) {
	int arr[] = { 0, 1, 10, 100 };

	return (arrValue / arr[digital]) % 10;
}

void printArr(int *arr, int size) {
	for (int i = 0; i <= size; ++i) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

// ����digital��ʾ��Ҫ������������λ��
void radixSort(int *arr, int begin, int end, int digital) {
	const int num = 10;
	int count[num];
	int *bucket = new int[end - begin + 1];

	for (int d = 1; d <= digital; ++d) {
		memset(count, 0, sizeof(count));
		memset(bucket, 0, sizeof(bucket));

		// ����λ����ͬ�ĸ����������λ��ΪΪ0������������20��80��90��
		for (int i = begin; i <= end; ++i) {
			count[getDigital(arr[i], d)]++;
		}

		// �ۼƺͣ�����ͼ�������һ��
		for (int i = 1; i < num; ++i) {
			count[i] += count[i - 1];
		}

		// ������������Ԫ��װ��Ͱ��
		for (int i = end; i >= begin; --i) {
			int j = getDigital(arr[i], d);
			bucket[count[j] - 1] = arr[i];
			count[j]--;
		}

		// ��Ͱ�е�Ԫ�ظ���ԭ���飬���һ������
		for (int i = begin; i <= end; ++i) {
			arr[i] = bucket[i];
		}
	}

	delete[]bucket;
}