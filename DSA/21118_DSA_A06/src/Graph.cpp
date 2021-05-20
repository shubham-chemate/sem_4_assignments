/*
 * Graph.cpp
 *
 *  Created on: 18-May-2021
 *      Author: Shubham
 */

#include <iostream>
#include "QUEUE.h"
#include "Graph.h"

using namespace std;

// Node class

Node :: Node(int x) {
	data = x;
	next = NULL;
}

ostream& operator <<(ostream &dout, Node n) {
	cout << n.data;
	return dout;
}

// Graph Class

Graph :: Graph(int n, int m) {
	vertices = n, edges = m;
	adj_list = new Node*[n + 1];
	for (int i = 0; i <= n; i++)
	adj_list[i] = NULL;
}

Node* Graph::Insert(Node *&head, int x) {
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

void Graph :: addEdge(int u, int v) {
	adj_list[u] = Insert(adj_list[u], v); // inserting at the end of list
	adj_list[v] = Insert(adj_list[v], u);
}

void Graph :: PrintGraph() {
	for (int i = 1; i <= vertices; i++) {
		cout << i << " -> ";
		for (Node *head = adj_list[i]; head; head = head->next)
			cout << (*head) << " ";
		cout << endl;
	}
}

void Graph :: bfs(int src) {
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

void Graph :: dfs_ut(int u, bool vis[]) {
	vis[u] = 1;
	cout << u << " ";

	for (Node *head = adj_list[u]; head; head = head->next)
		if (!vis[head->data])
			dfs_ut(head->data, vis);
}

void Graph :: dfs(int src) {
	bool vis[vertices + 1] = { 0 };
	dfs_ut(src, vis);
}

