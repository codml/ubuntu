#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <cstring>
#include <string.h>
#include <fstream>
#include <map>
#include <set>
#include <math.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

class Graph{	
protected:
	bool m_Type;
	int m_Size;
	bool m_Neg; // m_Neg = true -> graph has negative edge
public:
	Graph(bool type, int size);
	virtual ~Graph();

	bool getType();	
	int getSize();

	bool getNeg(); // return member variables
	void setNeg(bool tf);

	virtual int getWeight(int from_v, int to_v, char option) = 0; // pure virtual function: abstract data type
	virtual void getAdjacentEdges(int vertex, map<int, int>* m) = 0;	
	virtual void getIncomingEdges(int vertex, map<int, int>* m) = 0;	
	virtual void getAdjacentEdgesDirect(int vertex, map<int, int>* m) = 0;	
	virtual void insertEdge(int from, int to, int weight) = 0;				
	virtual	bool printGraph(ofstream *fout) = 0;

	virtual void setKw_graph() = 0;
	virtual int getKw_graph_size(int i) = 0;
	virtual int getKw_graph_node(int i, int idx) = 0;
};

#endif
