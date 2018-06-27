 #include "stackWithArray.h"
#include "stackWithList.h"
int main() {
	StackWithList<int> listStack;
	StackWithArray<int> arrayStack(50);
	
	// 测试链表栈
	cout << "************链表栈开始*****************" << endl;
	for (int i = 0; i <= 10; ++i) {
		listStack.push(i);
	}

	cout << "Push之后，栈的大小为：" << listStack.getSize() << endl;

	while (!listStack.isEmpty()) {
		cout << listStack.top() << endl;
		listStack.pop();
	}

	cout << "Pop之后，栈的大小为：" << listStack.getSize() << endl;
	cout << "************链表栈结束*****************" << endl;

	// 测试数组栈
	cout << "************数组栈开始*****************" << endl;
	for (int i = 0; i <= 10; ++i) {
		arrayStack.push(i);
	}

	cout << "Push之后，栈的大小为：" << arrayStack.size() << endl;

	while (!arrayStack.isEmpty()) {
		cout << arrayStack.top() << endl;
		arrayStack.pop();
	}

	cout << "Pop之后，栈的大小为：" << arrayStack.size() << endl;
	cout << "************数组栈结束*****************" << endl;

	system("pause");
	return 0;
}