//============================================================================
// Name        : 21118_DSA_A05.cpp
// Author      : Shubham (Roll No: 21118)
//============================================================================

#include <iostream>
using namespace std;

class Node {
private:
	int key;
	string val;
	Node *next;
public:
	Node(int k = -1, string v = "$") {
		key = k;
		val = v;
		next = NULL;
	}
	void PrintNode() {
		cout << key << " -> " << val << endl;
	}
	friend class LinkedList;
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() {
		head = NULL;
	}
	void Insert(int key, string val) {
		Node* newNode = new Node(key, val);
		newNode->next = head;
		head->next = newNode;
	}
	bool Search(int key) {
		Node* temp = head;
		while (temp) {
			if (temp->key == key) {
				cout << "Entry is found.\n";
				temp->PrintNode();
				return true;
			}
		}
		cout << "Entry not found\n";
		return false;
	}
	void Delete(int key) {
		if (head == NULL)
			return;
		Node *curr, *prev;
		curr = prev = head;

		while (curr && curr->key != key) {
			prev = curr;
			curr = curr->next;
		}


		if (curr != NULL) {
			prev->next = curr->next;
			delete curr;
		}
	}
};

class HashTable {

};

int main() {
	cout << "Hello" << endl; // prints
	return 0;
}
