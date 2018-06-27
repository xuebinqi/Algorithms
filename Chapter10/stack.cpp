 #include "stackWithArray.h"
#include "stackWithList.h"
int main() {
	StackWithList<int> listStack;
	StackWithArray<int> arrayStack(50);
	
	// ��������ջ
	cout << "************����ջ��ʼ*****************" << endl;
	for (int i = 0; i <= 10; ++i) {
		listStack.push(i);
	}

	cout << "Push֮��ջ�Ĵ�СΪ��" << listStack.getSize() << endl;

	while (!listStack.isEmpty()) {
		cout << listStack.top() << endl;
		listStack.pop();
	}

	cout << "Pop֮��ջ�Ĵ�СΪ��" << listStack.getSize() << endl;
	cout << "************����ջ����*****************" << endl;

	// ��������ջ
	cout << "************����ջ��ʼ*****************" << endl;
	for (int i = 0; i <= 10; ++i) {
		arrayStack.push(i);
	}

	cout << "Push֮��ջ�Ĵ�СΪ��" << arrayStack.size() << endl;

	while (!arrayStack.isEmpty()) {
		cout << arrayStack.top() << endl;
		arrayStack.pop();
	}

	cout << "Pop֮��ջ�Ĵ�СΪ��" << arrayStack.size() << endl;
	cout << "************����ջ����*****************" << endl;

	system("pause");
	return 0;
}