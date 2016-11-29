#include "Graph.h"

int main()
{
	Graph myGraph;
	std::ifstream fin("input1");
	myGraph.ReadGraph(fin);
	myGraph.PrintGraph();
	//myGraph.BfsTraversal(1);
	//myGraph.ShortestPath(1,7);
	myGraph.ConectedComponents();
}