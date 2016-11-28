#include "Graph.h"
#include "../Heap/Heap.h" /*PriorityQueue*/

Graph::Graph()
{
	m_nVertices = 0;
	for(int i = 0; i <= MAX_VERTICES; i++)
	{
		m_Edges[i] = NULL;
		m_OutDegree[i] = 0;
	}
}

void Graph::InitSearch()
{
	for(int i = 0; i <= MAX_VERTICES; i++)
	{
		m_bProcessed[i] = false;
		m_bDiscovered[i] = false;
		m_nParent[i] = NO_PARENT;
	}
}

void Graph::ProcessingEdge(int x, int y)
{
	std::cout << "ProcessingEdge " << x << "-" << y << "\n";
}

void Graph::ReadGraph(std::istream& in)
{
	in >> m_bDirected;
	in >> m_bWeights;
	in >> m_nVertices;

	int x, y;
	while(in >> x >> y)
	{
		int weight = 0;
		if(m_bWeights)
			in >> weight;

		InsertEdge(x, y, weight);
	}
}

int Graph::InsertEdge(int x, int y, int weight)
{
	EdgeNode* newEdge = new EdgeNode(y, m_Edges[x], weight);

	m_Edges[x] = newEdge;

	if(m_bDirected == false)
	{
		InsertEdge(y, x, weight);
	}

	m_nEdges++;
}

void Graph::PrintGraph()
{
	for(int i = 0; i < m_nVertices; i++)
	{
		bool bEmpty = true;
		EdgeNode* aux = m_Edges[i];
		if(aux != NULL)
		{
			bEmpty = false;
			std::cout << "Node " << i << ": ";
		}
		while(aux != NULL)
		{
			std::cout << aux->m_y << " ";
			aux = aux->m_pNext;
		}

		if(bEmpty == false)
			std::cout << "\n";
	}
}

void Graph::DfsTraversal(int nStart)
{

}


void Graph::BfsTraversal(int x)
{
	if(m_bDiscovered[x] == false)
	{
		m_bDiscovered[x] = true;
	}

	EdgeNode* aux = m_Edges[x];
	while(aux != NULL)
	{
		int y = aux->m_y;
		if(m_bDiscovered[y] == false)
		{
			m_nParent[y] = x;
		}
	}
}
