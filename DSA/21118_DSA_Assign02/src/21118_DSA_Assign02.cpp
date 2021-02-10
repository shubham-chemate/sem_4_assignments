//============================================================================
// Name        : 21118_DSA_Assign02.cpp
// Author      : Shubham (Roll No: 21118)
//============================================================================

#include <bits/stdc++.h>
#include <string>
using namespace std;

class Node {
private:
	string word, meaning;
	Node *lChild, *rChild;
public:
	Node(string w="", string m="") {
		word = w;
		meaning = m;
		lChild = rChild = NULL;
	}
	void printNode() {
		cout << "Word: " << word << endl;
		cout << "Meaning: " << meaning << endl;
		cout << "-----------\n";
	}
	friend class BST;
};

class BST {
private:
	Node* root;
public:
	BST() {root = NULL;}
	Node* getRoot() {return root;}
	void setRoot(Node* rt) {root = rt;}

//	Recursive Implementations
	Node* Insert(Node* curr_root, string word, string meaning);
	int Search(Node* root, string word); // returns number of comparisons
	void LexoPrint(Node* curr_root);

//	Iterative Implementations
	int SearchIt(string word);
	void InsertIt(string word, string mean);
};

//Recursive Implementations

Node* BST :: Insert(Node* curr_root, string word, string meaning) {
	if (curr_root == NULL)
		return new Node(word, meaning);

	if (word < curr_root->word)
		curr_root->lChild = Insert(curr_root->lChild, word, meaning);
	if (word > curr_root->word)
		curr_root->rChild = Insert(curr_root->rChild, word, meaning);

	return curr_root;
}

int BST :: Search(Node* curr_root, string word) {
	if (curr_root == NULL)
		return -1;

	if (curr_root->word == word)
		return 1;

	int l = -1, r = -1;
	if (word < curr_root->word)
		l = Search(curr_root->lChild, word);
	else
		r = Search(curr_root->rChild, word);

	if (l == -1 && r == -1)
		return -1;
	return 1 + (l != -1) ? l : r;
}

void BST :: LexoPrint(Node* curr_root) {
	if (curr_root != NULL) {
		LexoPrint(curr_root->lChild);
		curr_root->printNode();
		LexoPrint(curr_root->rChild);
	}
}

// Iterative Implementations

int BST :: SearchIt(string word) {
	Node* curr = root;
	int camp = 0;

	while (curr) {
		camp++;
		if (curr->word == word)
			return camp;
		else if (word < curr->word)
			curr = curr->lChild;
		else
			curr = curr->rChild;
	}

	return -1;
}

void BST :: InsertIt(string word, string mean) {
	Node* newNode = new Node(word, mean);
	if (root == NULL)
		root = newNode;
	else {
		Node *curr = root, *parent = NULL;
		while (curr) {
			parent = curr;
			if (word < curr->word)
				curr = curr->lChild;
			else
				curr = curr->rChild;
		}

		if (word < parent->word)
			parent->lChild = newNode;
		else if (word > parent->word)
			parent->rChild = newNode;
	}
}

int main() {
	BST bst;
	int n = 5;
	string words[] = {"Mango", "Apple", "Orange", "Grapes", "Banana"};
	string means[] = {"Green", "Red", "Orange", "Black", "Yellow"};

//	for (int i = 0; i < n; i++) {
//		Node* root = bst.getRoot();
//		root = bst.Insert(root, words[i], means[i]);
//		bst.setRoot(root);
//	}

	for (int i = 0; i < n; i++)
		bst.InsertIt(words[i], means[i]);

	Node* root = bst.getRoot();
	bst.LexoPrint(root);

	cout << bst.SearchIt("Lemon");
	return 0;
}
