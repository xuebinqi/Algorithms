#pragma once
#include <iostream>
#include <cassert>

using namespace std;

template <class T>
struct Node {
	T value;
	Node<T> *next;

	Node() = default;
	Node(T theValue) : value(theValue), next(NULL) { }
};

template <class T>
class QueueWithList {
public:
	QueueWithList();
	~QueueWithList();

public:
	bool isEmpty() const;
	int size() const;
	void push(const T& value);
	void pop();
	T& front() const;
	T& back() const;

private:
	Node<T> *head;
	Node<T> *end;
	int heapSize;
};

template <class T>
QueueWithList<T>::QueueWithList() : head(NULL), end(NULL), heapSize(0) {
	head = new Node<T>();
	end = head;
}

template <class T>
QueueWithList<T>::~QueueWithList() {
	while (head->next != NULL) {
		Node<T> *current = head;
		head = head->next;

		delete current;
	}
}

template <class T>
bool QueueWithList<T>::isEmpty() const {
	return this->heapSize == 0;
}

template <class T>
int QueueWithList<T>::size() const {
	return this->heapSize;
}

template <class T>
void QueueWithList<T>::push(const T& value) {
	Node<T> *current = new Node<T>(value);
	end->next = current;
	end = current;

	++heapSize;
}

template <class T>
void QueueWithList<T>::pop() {
	assert(heapSize);

	Node<T> * current = head->next;
	head = head->next->next;
	--heapSize;

	delete current;
}

template <class T>
T& QueueWithList<T>::front() const {
	assert(heapSize);

	return head->next->value;
}

template <class T>
T& QueueWithList<T>::back() const {
	assert(heapSize);

	return end->value;
}
