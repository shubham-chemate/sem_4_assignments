//============================================================================
// Name        : 21118_DSA_A07.cpp
// Author      : Shubham (Roll No: 21118)
//============================================================================

#include <iostream>

#include "mst.h"
using namespace std;

int main() {
	while (1) {
		int n, m, u, v, wt, opt;
		cout << "\n\nEnter number of vertices and edges.\n";
		cin >> n >> m;
		mst mymst(n, m);
		cout << "Enter edges and weights:\n";
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> wt;
			mymst.addEdge(u, v, wt);
		}

		cout << "How do you want to calculate mst:\n";
		cout << "\t1 for Prim's Algorithm\n";
		cout << "\t2 for Kruskal's Algorithm\n";
		cin >> opt;

		if (opt == 1)
			cout << mymst.prims_mst_wt() << endl;
		else if (opt == 2)
			cout << mymst.kruskals_mst_wt() << endl;
		else
			cout << "INVALID CHOICE.\n";

		cout << "Do you want to calculate again?(0 or 1)\n";
		cin >> opt;
		if (opt == 0)
			break;
	}

	return 0;
}
