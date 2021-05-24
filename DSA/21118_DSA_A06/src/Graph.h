/*
 * Graph.h
 *
 *  Created on: 18-May-2021
 *      Author: Shubham
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node *next;
public:
	Node(int x = 0);
	friend class Graph;
};

class Graph {
private:
	int vertices, edges;
	Node **adj_list;

	Node* Insert(Node *&head, int x);
public:
	Graph(int n, int m);
	void addEdge(int u, int v);
	void PrintGraph();
	void bfs(int src);
	void dfs_ut(int u, bool vis[]);
	void dfs(int src);
	void dfs_it(int src);
};



#endif /* GRAPH_H_ */
