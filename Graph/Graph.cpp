#include "Graph.h"
#include <queue>
#include <stack>

Graph::Graph()
{
	m_nVertices = 0;
	m_bBipartite = true;
	for(int i = 0; i <= MAX_VERTICES ; i++)
	{
		m_Edges[i] = NULL;
		m_OutDegree[i] = 0;
		m_nDiscoveryTime[i] = -1;
		m_nFinishTime[i] = -1;
	}
}

void Graph::InitSearch()
{
	for(int i = 0; i < m_nVertices; i++)
	{
		m_bProcessed[i] = false;
		m_bDiscovered[i] = false;
		m_nParent[i] = NO_PARENT;
		m_nReachableAncestor[i] = i;
	}
}

void Graph::ResetColor()
{
	for(int i = 0; i < m_nVertices; i++)
	{
		m_color[i] = UNCOLORED;
	}
}

void Graph::ProcessingBFSEdge(int x, int y)
{
	/* plain processing */
	//std::cout << "ProcessingBFSEdge " << x << "-" << y << "\n";

	/* processing for bipartite*/
	if(m_color[x] == m_color[y])
	{
		std::cout << "Graph is not bipartite due to edge " << x << "-" << y << "\n";
		m_bBipartite = false;
	}

	m_color[y] = Complement(m_color[x]);
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

void Graph::DfsDiscoverTime()
{
	for(int i = 0; i < m_nVertices; i++)
	{
		if(m_nDiscoveryTime[i] != -1)
		{
			std::cout << "Node " << i << " discovered at time " << m_nDiscoveryTime[i] << "\n";
		}
	}
}

EdgeType Graph::GetEdgeType(int x, int y)
{
	if(m_nParent[y] == x)
		return TREE;

	if(m_bDiscovered[y] == true && m_bProcessed[y] == false && m_nParent[x] != y)
		return BACK;

	if(m_bProcessed[y] == true && m_nDiscoveryTime[x] < m_nDiscoveryTime[y])
		return FORWARD;

	if(m_bProcessed[y] == true && m_nDiscoveryTime[x] > m_nDiscoveryTime[y])
		return CROSS;


	return UNKNOWN;
}

void Graph::ProcessDFSVertexEarly(int x, int nTime)
{
	std::cout << "Node " << x << " started at time " << nTime << "\n";
	m_nReachableAncestor[x] = x;
}

void Graph::ProcessDFSVertexLate(int x, int nTime)
{
	std::cout << "Node " << x << " finished at time " << nTime << "\n";

	bool bRoot;
	int time_x; // earliest reachable time for x
	int time_parent; // earliest reachable time for parent[x]

	// root with more childs
	if(m_nParent[x] < 1)
	{
		if(m_OutDegree[x] > 1)
			std::cout << "Root articulation vertex " << x << "\n";
		return;
	}

	bool bRootParent = (m_nParent[m_nParent[x]] < 1);
	if((m_nReachableAncestor[x] == m_nParent[x]) && !bRootParent)
		std::cout << "Parent articulation vertex " << m_nParent[x] << "\n";

	if(m_nReachableAncestor[x] == x)
	{
		std::cout << "Bridge articulation vertex " << m_nParent[x] << "\n";
	
		/* check if not tree leaf*/
		if(m_OutDegree[x] > 0)
			std::cout << "Bridge articulation vertex " << x << "\n";
	}

	time_x = m_nDiscoveryTime[m_nReachableAncestor[x]];
	time_parent = m_nDiscoveryTime[m_nReachableAncestor[m_nParent[x]]];

	if(time_x < time_parent)
		m_nReachableAncestor[m_nParent[x]] = m_nReachableAncestor[x];
}

void Graph::ProcessDFSEdge(int x, int y)
{
	EdgeType type = GetEdgeType(x,y);
	#if 0
	/* check for cycles */
	if(type == BACK)
	{
		std::cout << "Found cycle from " << y << " to " << x << "\n";
		FindPath(y,x);
	}
	std::cout << "Processing edge " << x << " " << y << "\n";
	#endif

	if(type == TREE)
		m_OutDegree[x]++;

	if(type == BACK && m_nParent[x] != y )
	{
		if(m_nDiscoveryTime[y] < m_nDiscoveryTime[m_nReachableAncestor[x]])
			m_nReachableAncestor[x] = y;
	}
}

void Graph::FindPath(int x, int y)
{
	if(x == y)
	{
		std::cout << x << "\n";
	}
	else
	{
		std::cout << y << " ";
		FindPath(x, m_nParent[y]);
	}
}

void Graph::DfsTraversal(int x)
{
	static int nTime = -1;
	nTime++;
	EdgeNode* aux = m_Edges[x];

	m_bDiscovered[x] = true;
	m_nDiscoveryTime[x] = nTime;
	ProcessDFSVertexEarly(x, nTime);
	if(aux == NULL)
	{
		/* no adjancent edges */
		ProcessDFSVertexLate(x, nTime);
		m_bProcessed[x] = true;
		return;
	}

	/* go through all edged*/
	while(aux != NULL)
	{
		int y = aux->m_y;

		if(m_bDiscovered[y] == false)
		{
			m_nParent[y] = x;
			ProcessDFSEdge(x, y);
			DfsTraversal(y);
		}
		else
		{
			if(m_bDirected || (m_bDirected == false && GetEdgeType(x,y) == BACK))
				ProcessDFSEdge(x,y);
		}
		aux = aux->m_pNext;
	}

	m_nFinishTime[x] = ++nTime;
	ProcessDFSVertexLate(x, nTime);
	
	m_bProcessed[x] = true;
}

void Graph::BfsTraversal(int x)
{
	//InitSearch();
	std::queue<int> processingQueue;
	if(m_bDiscovered[x] == false)
	{
		m_bDiscovered[x] = true;
		processingQueue.push(x);
	}

	while(processingQueue.empty() == false)
	{
		int nNodeIndex = processingQueue.front();
		//std::cout << "Processing node " << nNodeIndex << "\n";
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
				//std::cout << "\t"; 
				ProcessingBFSEdge(nNodeIndex,y);
			}
			aux = aux->m_pNext;
		}
		processingQueue.pop();
		m_bProcessed[nNodeIndex] = true;
		//std::cout << "Finished processing node " << nNodeIndex << "\n";
		std::cout << "Node " << nNodeIndex << "\n";
	}
}

void Graph::ShortestPath(int x, int y)
{
	BfsTraversal(x);
	int end = y;
	std::stack<int> path;
	while(m_nParent[end] != NO_PARENT || end != x)
	{
		path.push(end);
		end = m_nParent[end];
	}

	if(end == x)
	{
		std::cout << "shortest path: " << x << " ";
		while(!path.empty())
		{
			std::cout << path.top() << " ";
			path.pop();
		}
	}
	std::cout << "\n";
}


void Graph::ConectedComponents()
{
	InitSearch();
	int start = 1;

	int nConnected = 0;
	for(int i = 1; i < m_nVertices; i++)
	{
		if(m_bDiscovered[i] == false)
		{
			std::cout << "Connected component " << ++nConnected << "\n";
			BfsTraversal(i);
		}
	}
}

bool Graph::IsGraphBipartite()
{
	InitSearch();
	ResetColor();
	for(int i = 1; i < m_nVertices; i++)
	{
		if(m_bDiscovered[i] == false)
		{
			m_color[i] = RED;
			BfsTraversal(i);
		}
	}

	if(m_bBipartite == true)
		std::cout << "Graph is bipartite \n";
}