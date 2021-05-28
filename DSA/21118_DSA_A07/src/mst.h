/*
 * kruskals_mst.h
 *
 *  Created on: 25-May-2021
 *      Author: Shubham
 */

#ifndef MST_H_
#define MST_H_

class Edge {
private:
	int u, v, wt;
public:
	Edge() {u=0, v=0, wt=0;}
	Edge(int x, int y, int w);
	friend class mst;
};

class mst {
private:
	int vertices, edges;
	int** adj_list;
	int* par; // to keep track of root node of mst in disjoint mst's (kruskal's algo)

	int find_mst(int u);
	void union_mst(int u1, int u2);
public:
	mst(int n, int m);
	void printGraph();
	void addEdge(int u, int v, int w);
	int prims_mst_wt();
	int kruskals_mst_wt();
	~mst();
};



#endif /* MST_H_ */
