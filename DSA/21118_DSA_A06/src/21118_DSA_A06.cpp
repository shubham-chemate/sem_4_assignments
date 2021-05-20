//============================================================================
// Name        : 21118_DSA_A06.cpp
// Author      : Shubham (Roll No: 21118)
//============================================================================

#include <iostream>
#include "Graph.h"

using namespace std;

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
