#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>

const int MAX_VERTICES = 1023;
const int NO_PARENT = -1;

enum COLOR
{
	UNCOLORED,
	RED,
	BLACK
};

enum EdgeType
{
	CROSS,
	BACK,
	TREE
};

struct EdgeNode
{
	EdgeNode(int y, EdgeNode*& pNext, int nWeight = 0) : m_y(y), m_pNext(pNext), m_nWeight(nWeight) {}
	int m_y; /* end of */
	int m_nWeight;
	EdgeNode* m_pNext;
};

class Graph
{
public:
	Graph();
	void ReadGraph(std::istream& in);
	void PrintGraph();
	
	void DfsTraversal(int nStart);

	void BfsTraversal(int nStart);
	void ShortestPath(int x, int y);
	void ConectedComponents();
	bool IsGraphBipartite();
	COLOR Complement(COLOR x) { if(x == RED) return BLACK; return RED; }

private:
	int InsertEdge(int x, int y, bool bDirected, int nWeight = 0);
	void InitSearch();
	void ResetColor();
	void ProcessingBFSEdge(int x, int y);
	
	void ProcessDFSVertexEarly(int x) { /*std::cout << "Processing early vertex " << x << "\n"; */}
	void ProcessDFSVertexLate(int x) { std::cout << "Processing late vertex " << x << "\n"; }
	void ProcessDFSEdge(int x, int y) { std::cout << "Processing edge " << x << "-" << y << "\n"; }

	bool m_bProcessed[MAX_VERTICES + 1];
	bool m_bDiscovered[MAX_VERTICES + 1];
	int  m_nParent[MAX_VERTICES + 1];

	bool m_bDirected;
	bool m_bBipartite;
	bool m_bWeights;
	int m_nVertices;
	int m_nEdges;
	int m_OutDegree[MAX_VERTICES + 1];
	COLOR m_color[MAX_VERTICES + 1];
	EdgeNode* m_Edges[MAX_VERTICES + 1];
};

#endif