#include "Graph.h"
#include <queue>

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

void Graph::ProcessingBFSEdge(int x, int y)
{
	std::cout << "ProcessingBFSEdge " << x << "-" << y << "\n";
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

		InsertEdge(x, y, m_bDirected, weight);
	}
}

int Graph::InsertEdge(int x, int y, bool bDirected, int weight)
{
	EdgeNode* newEdge = new EdgeNode(y, m_Edges[x], weight);

	m_Edges[x] = newEdge;

	if(bDirected == false)
	{
		InsertEdge(y, x, true, weight);
	}

	m_nEdges++;
}

void Graph::PrintGraph()
{
	if(m_bDirected)
		std::cout << "Graph is directed \n";
	else
		std::cout << "Graph is undirected \n";
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
	InitSearch();
	std::queue<int> processingQueue;
	if(m_bDiscovered[x] == false)
	{
		m_bDiscovered[x] = true;
		processingQueue.push(x);
	}

	while(processingQueue.empty() == false)
	{
		int nNodeIndex = processingQueue.front();
		std::cout << "Processing node " << nNodeIndex << "\n";
		EdgeNode* aux = m_Edges[nNodeIndex];

		/* Process edges */
		while(aux != NULL)
		{
			int y = aux->m_y;

			/*Add it to processing queue and update parrent*/
			if(m_bDiscovered[y] == false)
			{
				m_nParent[y] = nNodeIndex;
				m_bDiscovered[y] = true;
				if(m_bProcessed[y] == false)
					processingQueue.push(y);
			}

			if(m_bProcessed[y] != true || m_bDirected == true)
			{
				std::cout << "\t"; 
				ProcessingBFSEdge(nNodeIndex,y);
			}
			aux = aux->m_pNext;
		}
		processingQueue.pop();
		m_bProcessed[nNodeIndex] = true;
		std::cout << "Finished processing node " << nNodeIndex << "\n";
	}
}
