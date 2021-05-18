//============================================================================
// Name        : 21118_DSA_A06.cpp
// Author      : Shubham (Roll No: 21118)
// Copyright   : Use it freely!!!
//============================================================================

#include <iostream>
#include "QUEUE.h"

using namespace std;

class Node {
private:
	int data;
	Node *next;
public:
	Node(int x = 0) {
		data = x;
		next = NULL;
	}
	friend ostream& operator <<(ostream &dout, Node);
	friend class Graph;
};

ostream& operator <<(ostream &dout, Node n) {
	cout << n.data;
	return dout;
}

class Graph {
private:
	int vertices, edges;
	Node **adj_list;

	Node* Insert(Node *&head, int x) {
		Node *newNode = new Node(x);
		if (head == NULL)
			head = newNode;
		else {
			Node *tmp = head;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = newNode;
		}
		return head;
	}
public:
	Graph(int n, int m) {
		vertices = n, edges = m;
		adj_list = new Node*[n + 1];
		for (int i = 0; i <= n; i++)
			adj_list[i] = NULL;
	}
	void addEdge(int u, int v) {
		adj_list[u] = Insert(adj_list[u], v); // inserting at the end of list
		adj_list[v] = Insert(adj_list[v], u);
	}
	void PrintGraph() {
		for (int i = 1; i <= vertices; i++) {
			cout << i << " -> ";
			for (Node *head = adj_list[i]; head; head = head->next)
				cout << (*head) << " ";
			cout << endl;
		}
	}
	void bfs(int src) {
		QUEUE<int> qu;
		bool vis[vertices + 1] = { 0 };

		qu.Push(src);
		vis[src] = 1;
		while (!qu.Empty()) {
			int u = qu.Front();
			qu.Pop();
			cout << u << " ";

			for (Node *head = adj_list[u]; head; head = head->next)
				if (!vis[head->data]) {
					vis[head->data] = 1;
					qu.Push(head->data);
				}
		}
	}
	void dfs_ut(int u, bool vis[]) {
		vis[u] = 1;
		cout << u << " ";

		for (Node *head = adj_list[u]; head; head = head->next)
			if (!vis[head->data])
				dfs_ut(head->data, vis);
	}
	void dfs(int src) {
		bool vis[vertices + 1] = { 0 };
		dfs_ut(src, vis);
	}
};

int main() {
	Graph g(4, 4);
	g.addEdge(1, 4);
	g.addEdge(1, 3);
	g.addEdge(4, 2);
	g.addEdge(3, 4);
	g.PrintGraph();
	g.bfs(1);
	cout << endl;
	g.dfs(1);
	cout << endl;
	return 0;
}
