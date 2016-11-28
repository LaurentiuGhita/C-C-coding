#include "Graph.h"

int main()
{
	Graph myGraph;
	std::ifstream fin("input1");
	myGraph.ReadGraph(fin);
	myGraph.PrintGraph();
}