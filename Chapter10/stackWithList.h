#pragma once
#include <iostream>

#define MAXSIZE 0xff

using namespace std;

template <class T>
class StackWithList {
private:
	struct MyNode {
		T data;
		MyNode *next;
	};
	
	typedef MyNode Node;
	Node * topNode;
	int maxSize;
	int size;

public:
	StackWithList();
	StackWithList(int max);
	~StackWithList();

public:
	void push(const T& value);
	void pop();
	const T top()const;
	int getSize() const;
	bool isEmpty() const; 

};

template <class T>
StackWithList<T>::StackWithList():topNode(NULL), size(0), maxSize(MAXSIZE) { }

template <class T>
StackWithList<T>::StackWithList(int max):topNode(NULL), size(0) {
	this->maxSize = max;
}

template <class T>
StackWithList<T>::~StackWithList() {
	Node *currentNode = topNode;

	while (currentNode != NULL) {
		Node *nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}

	topNode = NULL;
}

template <class T>
void StackWithList<T>::push(const T& value) {
	if (size == maxSize) {
		cerr << "栈已经满了" << endl;
		exit(1);
		return;
	}

	Node *newNode = new Node();
	newNode->data = value;

	if (topNode == NULL) {
		newNode->next = NULL;
	}
	else {
		newNode->next = topNode;
	}

	topNode = newNode;
	++size;
}

template <class T>
void StackWithList<T>::pop() {
	if (size == 0) {
		cerr << "栈中没有元素了" << endl;
		exit(1);
		return;
	}

	Node *deleNode = topNode;
	topNode = topNode->next;
	--size;

	delete deleNode;
}

template <class T>
int StackWithList<T>::getSize() const {
	return this->size;
}

template <class T>
const T StackWithList<T>::top()const {
	if (topNode == NULL || size == 0) {
		cout << "There have no data, can't get top value." << endl;
		return 0;
	}

	return topNode->data;
}

template <class T>
bool StackWithList<T>::isEmpty() const {
	return this->size == 0;
}