/*
 * QUEUE.h
 *
 *  Created on: 18-May-2021
 *      Author: Shubham
 */

#ifndef QUEUE_H_
#define QUEUE_H_

const int MAX = 100;

template <typename T>
class QUEUE {
private:
	T a[MAX];
	int front;
public:
	QUEUE() {
		front = -1;
	}
	bool Empty() {
		return front == -1;
	}
	void Push(T x) {
		front++;
		if (front < MAX)
			a[front] = x;
		else front--;
	}
	void Pop() {
		if (!Empty())
			front--;
	}
	T Front() {
		if (!Empty())
			return a[front];
		else return -1;
	}
};



#endif /* QUEUE_H_ */
