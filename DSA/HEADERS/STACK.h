/*
 * STACK.h
 *
 *  Created on: 24-May-2021
 *      Author: Shubham
 */

#ifndef STACK_H_
#define STACK_H_

template <typename T>
class STACK {
private:
	T* a;
	int top, size;
public:
	STACK(int size) {
		top=-1, this->size = size;
		a = new T[size];
	}
	bool Empty() {
		return (top==-1);
	}
	void Push(T x) {
		top++;
		if (top < size)
			a[top] = x;
		else top--;
	}
	void Pop() {
		if (!Empty())
			top--;
	}
	T Top() {
		if (!Empty())
			return a[top];
		else return -1;
	}
	~STACK() {
		delete[] a;
	}
};


#endif /* STACK_H_ */
