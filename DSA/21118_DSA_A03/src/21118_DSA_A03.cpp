//============================================================================
// Name        : 21118_DSA_A03.cpp
// Author      : Shubham (Roll No: 21118)
//============================================================================

#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node *lChild, *rChild;
	bool lTh, rTh;
public:
	Node(int x = 0) {
		data = x;
		lChild = rChild = NULL;
		lTh = rTh = false;
	}
	friend class TBST;
};

class TBST {
private:
	Node* root;
public:
	TBST() {
		root = NULL;
	}
	Node* getRoot() {return root;}
	Node* InsertNode(Node* curr_root, Node* inorderSucc, int x) {
		if (curr_root == NULL) {
			curr_root = new Node(x);
			curr_root->rChild = inorderSucc;
			if (inorderSucc)
				curr_root->rTh = true;
		}
		else if (curr_root->rTh == true) {
            curr_root->rChild = new Node(x);
            curr_root->rTh = false;
            curr_root->rChild->rChild = inorderSucc;
            curr_root->rChild->rTh = true;
		}
		else if (x < curr_root->data) {
			curr_root->lChild = InsertNode(curr_root->lChild, curr_root, x);
			curr_root->lTh = false;
		}
		else if (x > curr_root->data)
			curr_root->rChild = InsertNode(curr_root->rChild, inorderSucc, x);
		return curr_root;
	}
	void PrintNode(Node* n) {
		if (n) cout << n->data << endl;
		else cout << "Empty\n";
	}
	void CreateTree() {
		cout << "Enter data of node or -1:\n";
		while (true) {
			int x; cin >> x;
			if (x == -1)
				break;

			root = InsertNode(root, NULL, x);
//			ThInorder();
//			ThPreorder();
		}
		PrintNode(root);
		PrintNode(root->lChild);
		PrintNode(root->lChild->lChild);
		PrintNode(root->lChild->rChild);
	}
	void ThInorder() {
		if (root == NULL) {
			cout << "Empty Tree.\n";
			return;
		}
		Node* curr = root;
		bool byThread = false;
		while (curr != NULL) {
			if (byThread) {
				cout << curr->data << " ";
				byThread = curr->rTh;
				curr = curr->rChild;
			}
			else {
				while (curr->lChild)
					curr = curr->lChild;
				cout << curr->data << " ";
                byThread = curr->rTh;
				curr = curr->rChild;
			}
		}
		cout << endl;
	}
	void ThPreorder() {
		if (root == NULL) {
			cout << "Empty Tree.\n";
			return;
		}
		Node* curr = root;
		bool byThread = false;
		while (curr != NULL) {
			if (byThread) {
				byThread = curr->rTh;
				curr = curr->rChild;
			}
			else {
				while (curr->lChild) {
					cout << curr->data << " ";
					curr = curr->lChild;
				}
				cout << curr->data << " ";
                byThread = curr->rTh;
				curr = curr->rChild;
			}
		}
		cout << endl;
	}
};

int main() {
	TBST tbt;
	tbt.CreateTree();
//	tbt.ThInorder();
	cout << "----END-----\n";
	return 0;
}
