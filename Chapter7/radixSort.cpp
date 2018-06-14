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
	cout << "原数据如下：" << endl;
	printArr(br, 10);

	lsdradixSort(br, 0, 9, 3);

	cout << "排序后数据如下：" << endl;
	printArr(br, 10);

	system("pause");
	return 0;
}

int getDigit(int x, int d) {
	int a[] = { 1, 1, 10, 100 };   //最大三位数，所以这里只要百位就满足了。
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

	int *bucket = (int*)malloc((end - begin + 1)*sizeof(int));  //所有桶的空间开辟   

																//按照分配标准依次进行排序过程
	for (int k = 1; k <= d; ++k) {
		//置空
		for (i = 0; i < radix; i++) {
			count[i] = 0;
		}
		//统计各个桶中所盛数据个数
		for (i = begin; i <= end; i++) {
			count[getDigit(arr[i], k)]++;
		}
		//count[i]表示第i个桶的右边界索引
		for (i = 1; i < radix; i++) {
			count[i] = count[i] + count[i - 1];
		}
		//把数据依次装入桶(注意装入时候的分配技巧)
		for (i = end; i >= begin; --i)        //这里要从右向左扫描，保证排序稳定性   
		{
			j = getDigit(arr[i], k);        //求出关键码的第k位的数字， 例如：576的第3位是5   
			bucket[count[j] - 1] = arr[i]; //放入对应的桶中，count[j]-1是第j个桶的右边界索引 
			--count[j];               //对应桶的装入数据索引减一  
		}

		//注意：此时count[i]为第i个桶左边界  

		//从各个桶中收集数据
		for (i = begin, j = 0; i <= end; ++i, ++j) {
			arr[i] = bucket[j];
		}
	}

	free(bucket);
}



原数据如下：
20 80 90 589 998 965 852 123 456 789
排序后数据如下：
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

// 这里digital表示所要排序的数的最大位数
void radixSort(int *arr, int begin, int end, int digital) {
	const int num = 10;
	int count[num];
	int *bucket = new int[end - begin + 1];

	for (int d = 1; d <= digital; ++d) {
		memset(count, 0, sizeof(count));
		memset(bucket, 0, sizeof(bucket));

		// 计算位数相同的个数，比如个位数为为0的数有三个（20，80，90）
		for (int i = begin; i <= end; ++i) {
			count[getDigital(arr[i], d)]++;
		}

		// 累计和，这里和计数排序一样
		for (int i = 1; i < num; ++i) {
			count[i] += count[i - 1];
		}

		// 将数组中所有元素装入桶中
		for (int i = end; i >= begin; --i) {
			int j = getDigital(arr[i], d);
			bucket[count[j] - 1] = arr[i];
			count[j]--;
		}

		// 将桶中的元素赋给原数组，完成一次排列
		for (int i = begin; i <= end; ++i) {
			arr[i] = bucket[i];
		}
	}

	delete[]bucket;
}