//============================================================================
// Name        : 21118_DSA_A06.cpp
// Author      : Shubham (Roll No: 21118)
//============================================================================

#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
	while (1) {
		cout << "\n\n**NOTE: 1-based INDEXING**\n";

		int n, m, u, v, opt, src;
		cout << "Enter number of vertices and edges:\n";
		cin >> n >> m;
		Graph g(n, m);
		cout << "Enter edges (input format: vertex1 <space> vertex2)\n";
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			g.addEdge(u, v);
		}

		cout << "Printing Graph:\n";
		g.PrintGraph();

		cout << "Enter\n";
		cout << "\t1 for Breadth-first-traversal.\n";
		cout << "\t2 for Depth-first-traversal.\n";
		cout << "\t0 to exit.\n";
		cout << ": ";
		cin >> opt;

		if (opt != 0) {
			cout << "Enter Source vertex: ";
			cin >> src;
		}

		switch (opt) {
		case 0: {
			break;
		}
		case 1: {
			cout << "Breadth-first-traversal: ";
			g.bfs(src);
			cout << endl;
			break;
		}
		case 2: {
			cout << "Depth-first-traversal: ";
			g.dfs(src);
			cout << endl;
			break;
		}
		default:
			cout << "INVALID CHOICE.\n";
		}
	}
	return 0;
}
