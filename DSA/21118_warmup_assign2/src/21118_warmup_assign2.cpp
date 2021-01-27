//============================================================================
// Name        : 21118_warmup_assign2.cpp
// Author      : Shubham (Roll No: 21118)
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node {
	int data;
	Node* next;
public:
	Node(int x = 0) {
		data = x;
		next = NULL;
	}
	friend class SLL;
};

class SLL {
	int length;
	Node *head;

	void printReverseUtil(Node* temp_head) {
		if (temp_head == NULL)
			return;
		printReverseUtil(temp_head->next);
		cout << temp_head->data << " ";
	}

	void reverseListUtil(Node* temp_head) {
		if (temp_head == NULL)
			return;
		if (temp_head->next == NULL) {
			head = temp_head;
			return;
		}
		reverseListUtil(temp_head->next);
		temp_head->next->next = temp_head;
		temp_head->next = NULL;
	}
public:
	SLL () {
		length = 0;
		head = NULL;
	}
	void InsertAtBegin(int x) {
		Node* newNode = new Node(x);
		if (head == NULL)
			head = newNode;
		else {
			newNode->next = head;
			head = newNode;
		}
	}
	void InsertAtEnd(int x) {
		Node* newNode = new Node(x);
		if (head == NULL)
			head = newNode;
		else {
			Node* temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
		}
	}
	void printList() {
		if (head == NULL) {
			cout << "List is Empty.\n";
			return;
		}
		cout << "List is: ";
		Node* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void printReverse() {
		cout << "Printing list in reverse order: ";
		printReverseUtil(head);
		cout << endl;
	}
	void reverseList() {
		reverseListUtil(head);
	}
	SLL concat(const SLL& list2) {
		SLL newList;
		Node* temp = head;
		while (temp != NULL) {
			newList.InsertAtEnd(temp->data);
			temp = temp->next;
		}
		temp = list2.head;
		while (temp != NULL) {
			newList.InsertAtEnd(temp->data);
			temp = temp->next;
		}
		return newList;
	}
};

int main() {
	SLL mylist;
	for (int i = 5; i >= 1; i--)
		mylist.InsertAtBegin(i);
	mylist.printList();
	mylist.printReverse();
//	mylist.reverseList();
//	mylist.printList();

//	SLL list1, list2;
//	for (int i = 1; i <= 5; i++) {
//		list1.InsertAtEnd(i);
//		list2.InsertAtEnd(i+5);
//	}
//
//	list1.printList();
//	list2.printList();
//	SLL concat_list = list1.concat(list2);
//	concat_list.printList();


	return 0;
}
