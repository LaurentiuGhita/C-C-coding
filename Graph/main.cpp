#include "Graph.h"
#define CHECK_CYCLES 1

int main()
{
	Graph myGraph;
	std::ifstream fin("input1");
	myGraph.ReadGraph(fin);
	//myGraph.PrintGraph();
	//myGraph.BfsTraversal(1);
	//myGraph.ShortestPath(1,7);
	//myGraph.ConectedComponents();
	//myGraph.IsGraphBipartite();
	//myGraph.DfsTraversal(1);
	//myGraph.DfsDiscoverTime();
	myGraph.TopologicalSort();
}