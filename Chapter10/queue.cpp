#include "queueWithArray.h"
#include "queueWithList.h"
int main() {
	QueueWithArray<int> queueWithArray(100);
	QueueWithList<int> queueWithList;

 	cout << queueWithArray.size() << endl;
	cout << queueWithList.size() << endl;


	for (int i = 1; i <= 10; ++i) {
		queueWithArray.push(i * 10);
		queueWithList.push(i * 10);
	}

//	queueWithArray.pop();
//	queueWithArray.pop();
//	queueWithArray.pop();

	cout << "queueWithArray.size() = "<< queueWithArray.size() << endl;
	cout << "queueWithArray.front() = "<< queueWithArray.heapFront() << endl;
	cout << "queueWithArray.back() = "<< queueWithArray.back() << endl;

	cout << "queueWithlist.size() = " << queueWithList.size() << endl;
	cout << "queueWithList.front() = " << queueWithList.front() << endl;
	cout << "queueWithList.back() = " << queueWithList.back() << endl;


	system("pause");
	return 0;
}