#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <stack>

const int MAX_VERTICES = 1023;
const int NO_PARENT = -1;
const int INIFITE = 99999;

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
	TREE,
	FORWARD,
	UNKNOWN
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

	bool HasChilds(int x);
	int GetMinimumDepth(int x);
	void BfsTraversal(int nStart);
	void ShortestPath(int x, int y);
	void ConectedComponents();
	bool IsGraphBipartite();
	COLOR Complement(COLOR x) { if(x == RED) return BLACK; return RED; }
	void DfsDiscoverTime();
	EdgeType GetEdgeType(int x, int y);
	void FindPath(int x, int y);
	void TopologicalSort();
	void InitStack(std::stack<int>& st);
	void PrimAlgorithm(int nStartIndex); // for minimum spaning tree
	void DijkstraAlgorithm(int nStartIndex); // shortest path --> mlg n performance using a heap instead of a distance vector
	void ConstructAllPaths(int nStartNode, int nEndNode);


private:
	int InsertEdge(int x, int y, bool bDirected, int nWeight = 0);
	void InitSearch();
	void ResetColor();
	void ProcessingBFSEdge(int x, int y);
	
	void ProcessDFSVertexEarly(int x, int nTime); 
	void ProcessDFSVertexLate(int x, int nTime);
	void ProcessDFSEdge(int x, int y);
	void ConstructCandidate(int*&a, int k, int n, int*& candidates, int& nCandidates);
	void backtrack(int*& a, int k, int n); 

	bool m_bProcessed[MAX_VERTICES + 1];
	bool m_bDiscovered[MAX_VERTICES + 1];
	int  m_nParent[MAX_VERTICES + 1];
	bool m_bDirected;
	bool m_bBipartite;
	bool m_bWeights;
	int m_nVertices;
	int m_nEdges;
	int m_OutDegree[MAX_VERTICES + 1];
	int m_nReachableAncestor[MAX_VERTICES + 1]; /* earliest discovered reachable ancestor */
	int m_nDiscoveryTime[MAX_VERTICES + 1];
	int m_nFinishTime[MAX_VERTICES + 1];
	COLOR m_color[MAX_VERTICES + 1];
	EdgeNode* m_Edges[MAX_VERTICES + 1];
	std::stack<int> m_topologicalSort;
};

#endif