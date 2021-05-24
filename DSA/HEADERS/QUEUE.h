/*
 * QUEUE.h
 *
 *  Created on: 18-May-2021
 *      Author: Shubham
 */

#ifndef QUEUE_H_
#define QUEUE_H_

template <typename T>
class QUEUE {
private:
	T* a;
	int front, size, rear;
public:
	QUEUE(int size) {
		front = 0, rear = 0;
		this->size = size;
		a = new T[size];
	}
	bool Empty() {
		return front == rear;
	}
	bool isFull() {
		int temp = (rear + 1) % size;
		return (temp == front);
	};
	void Push(T x) {
		if (!isFull()) {
			rear = (rear + 1) % size;
			a[rear] = x;
		}
	}
	void Pop() {
		if (Empty()) return;
		front = (front + 1) % size;
	}
	T Front() {
		return a[front+1];
	}
	~QUEUE() {
		delete[] a;
	}
};

#endif /* QUEUE_H_ */
