#include "Graph.h"
#define CHECK_CYCLES 1

int main()
{
	Graph myGraph;
	std::ifstream fin("input2");
	myGraph.ReadGraph(fin);
	myGraph.DijkstraAlgorithm(1);
	//myGraph.PrimAlgorithm(1);
	//myGraph.PrintGraph();
	//myGraph.BfsTraversal(1);
	//myGraph.ShortestPath(1,7);
	//myGraph.ConectedComponents();
	//myGraph.IsGraphBipartite();
	//myGraph.DfsTraversal(1);
	//myGraph.DfsDiscoverTime();
	//myGraph.TopologicalSort();
}