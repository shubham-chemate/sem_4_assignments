//============================================================================
// Name        : 21118_DSA_Assign01.cpp
// Author      : Shubham (Roll No: 21118)
// Problem 	   : Beginning with empty BT, construct BT by inserting the values in the order given.
//					After constructing a binary tree -
//					i.	Insert New Node
//					ii.	Find Number of nodes in longest path from root to leaf
//					iii.Minimum data value found in tree
//					iv.	Change a tree so that the roles of the left and right pointer are swapped at
//						every node
//					v.	Search a value
//============================================================================

#include <iostream>
using namespace std;

const int MAX = 5;

class Node {
private:
	int data;
	Node *lChild, *rChild;
public:
	Node(int x = 0) {
		data = x;
		lChild = rChild = NULL;
	}
	friend class BinaryTree;
};

template<class T>
class Queue {
private:
	T arr[MAX];
	int front, rear;
public:
	Queue() {
		front = rear = 0;
	}
	bool isEmpty() {
		return (front == rear);
	}
	bool isFull() {
		return ((rear + 1) % MAX == front);
	}
	T Front() {
		if (isEmpty())
			return 0;
		else
			return arr[front];
	}
	void Enqueue(T x) {
		if (!isFull()) {
			arr[rear] = x;
			rear = (rear + 1) % MAX;
		}
		else
			cout << "INSERTION FAIL: Queue is Full.\n";
	}
	void Dequeue() {
		if (!isEmpty())
			front = (front + 1) % MAX;
		else
			cout << "Empty Queue.\n";
	}
	void PrintQue() {
		if (!isEmpty()) {
			int i = front;
			do {
				cout << arr[i] << " ";
				i = (i + 1) % MAX;
			} while (i != rear);
			cout << endl;
		}
	}
};

class BinaryTree {
private:
	Node *root;
	int size;
public:
	BinaryTree() {
		root = NULL;
		size = 0;
	}
	Node* getRoot() {
		return root;
	}
	void insertNode(int x) {
		Node *newNode = new Node(x);
		if (root == NULL) {
			root = newNode;
			size++;
		}
		else {
			Queue<Node*> qu;
			qu.Enqueue(root);
			while (!qu.isEmpty()) {
				Node *curr = qu.Front();
				qu.Dequeue();

				char choice;
				if (!curr->lChild) {
					cout << "Do to want to insert to left of " << curr->data << ": ";
					cin >> choice;
					if (choice == 'y' || choice == 'Y') {
						curr->lChild = newNode;
						size++;
						return;
					}
				}

				if (!curr->rChild) {
					cout << "Do to want to insert to right of " << curr->data << ": ";
					cin >> choice;
					if (choice == 'y' || choice == 'Y') {
						curr->rChild = newNode;
						size++;
						return;
					}
				}

				if (curr->lChild)
					qu.Enqueue(curr->lChild);
				if (curr->rChild)
					qu.Enqueue(curr->rChild);
			}
			cout << "No Choice Made.\n";
		}
	}
	void Inorder(Node* curr_root) {
		if (curr_root != NULL) {
			Inorder(curr_root->lChild);
			cout << curr_root->data << " ";
			Inorder(curr_root->rChild);
		}
	}
	void Preorder(Node* curr_root) {
		if (curr_root != NULL) {
			cout << curr_root->data << " ";
			Preorder(curr_root->lChild);
			Preorder(curr_root->rChild);
		}
	}
	void Postorder(Node* curr_root) {
		if (curr_root != NULL) {
			Postorder(curr_root->lChild);
			Postorder(curr_root->rChild);
			cout << curr_root->data << " ";
		}
	}
};

int main() {
	BinaryTree BT;
	for (int i = 1; i <= 5; i++) {
		BT.insertNode(i);
		Node* root = BT.getRoot();
		BT.Inorder(root); cout << endl;
	}

	return 0;
}
