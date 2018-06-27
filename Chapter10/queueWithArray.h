#pragma once
#include <iostream>
#include <cassert>

#define MAXSIZE 0xff

using namespace std;

template <class T>
class QueueWithArray {
private:
	T *queue;
	int maxSize;
	int tail;
	int front;

public:
	QueueWithArray();
	QueueWithArray(int maxSize);
	~QueueWithArray();
	bool isEmpty() const;
	int size() const;
	void push(const T& value);
	void pop();
	T& heapFront() const;
	T& back() const;
};

template <class T>
QueueWithArray<T>::QueueWithArray() : maxSize(MAXSIZE) {
	this->front = 0;
	this->tail = 0;
	queue = new T[maxSize];
}

template <class T>
QueueWithArray<T>::QueueWithArray(int theSize) : maxSize(theSize) {
	this->front = 0;
	this->tail = 0;
	queue = new T[maxSize];

}

template <class T>
QueueWithArray<T>::~QueueWithArray() {
	delete[] queue;
}

template <class T>
bool QueueWithArray<T>::isEmpty() const {
	return (front == tail);
}

template <class T>
int QueueWithArray<T>::size() const {
	return (tail - front + maxSize) % maxSize;
}

template <class T>
void QueueWithArray<T>::push(const T& value) {
	assert((tail + 1) % maxSize != front);
	queue[tail] = value;
	tail = (tail + 1) % maxSize;
}

template <class T>
void QueueWithArray<T>::pop() {
	assert(tail != front);
	front = (front + 1) % maxSize;
}

template <class T>
T& QueueWithArray<T>::heapFront() const {
	assert(tail != front);

	return queue[front];
}

template <class T>
T& QueueWithArray<T>::back() const {
	assert(tail != front);

	return queue[tail - 1];
}