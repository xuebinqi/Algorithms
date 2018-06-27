#pragma once
#include <iostream>

using namespace std;

#define MAXSIZE 0xffff

/**************************数组方式实现栈*******************/
template <class T>
class StackWithArray {
private:
	T *myStack;
	int maxSize;
	int topValue;

public:
	StackWithArray():topValue(-1), maxSize(MAXSIZE){
		myStack = new T[maxSize];

		if (myStack == NULL) {
			cerr << "动态内存分配失败" << endl;
			exit(1);
		}
	}

	StackWithArray(int theSize):topValue(-1), maxSize(theSize) {
		myStack = new T[maxSize];

		if (myStack == NULL) {
			cerr << "动态内存分配失败" << endl;
			exit(1);
		}
	}

	~StackWithArray() { delete[] myStack; }

	bool isEmpty();

	void push(T value);
	
	void pop();

	int size();

	T top();

};

template <class T>
bool StackWithArray<T>::isEmpty() {
	if (topValue == -1) {
		return true;
	}

	return false;
}

template <class T>
void StackWithArray<T>::push(T value) {
	if (topValue + 1 < maxSize) {
		myStack[++topValue] = value;
	}
	else {
		cerr << "栈满" << endl;
		exit(1);
	}
}

template <class T>
T StackWithArray<T>::top() {
	if (topValue != -1) {
		return myStack[topValue];
	}
	else {
		cerr << "栈为空" << endl;
		exit(1);
	}
}

template <class T>
int StackWithArray<T>::size() {
	return topValue + 1;
}

template <class T>
void StackWithArray<T>::pop() {
	if (topValue >= 0) {
		topValue--;
	}
	else {
		cerr << "栈为空" << endl;
		exit(1);
	}
}