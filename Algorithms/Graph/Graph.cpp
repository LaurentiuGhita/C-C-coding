#include "Graph.h"
#include <queue>
#include <sstream>
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

	in.clear();
	int x, y;
	std::string sLine;
	while(std::getline(in, sLine))
	{
		if(!sLine.empty())
		{
			std::stringstream ss;
			ss << sLine;
			ss >> x >> y;
			
			int weight = 0;
			if(m_bWeights)
				in >> weight;

			InsertEdge(x, y, m_bDirected, weight);			
		}

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
			std::cout << "Node " << i << ": \n";
		}
		while(aux != NULL)
		{
			std::cout << "   Edge to " << aux->m_y;
			if(m_bWeights)
				std::cout << " with weight " << aux->m_nWeight << "\n";
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

	m_topologicalSort.push(x);
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
	/* check for cycles */
	if(type == BACK)
	{
		std::cout << "Found cycle from " << y << " to " << x << "\n";
		FindPath(y,x);
	}
	std::cout << "Processing edge " << x << " " << y << "\n";

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

void Graph::TopologicalSort()
{
	InitSearch();
	InitStack(m_topologicalSort);

	for(int i = 1 ; i <m_nVertices; i++)
	{
		if(m_bDiscovered[i] == false)
		{
			DfsTraversal(i);
		}
	}

	std::cout << "Topological sort ";
	while(!m_topologicalSort.empty())
	{
		std::cout << m_topologicalSort.top() << " ";
		m_topologicalSort.pop();
	}
	std::cout << "\n";
}

void Graph::InitStack(std::stack<int>& st)
{
	while(!st.empty())
		st.pop();
}

void Graph::PrimAlgorithm(int nStartIndex)
{
	InitSearch(); // not all ops from init necessary 

	EdgeNode* aux;
	std::vector<bool> bIntreeVector(MAX_VERTICES, false); // is the vertex in the tree yet
	std::vector<int> nDistanceVector(MAX_VERTICES, INIFITE); // distance from startIndex 

	int weight; // edge weight;
	int index;
	int v; // current vertex to process
	int w;
	int minDist = INIFITE; // current minimum distance

	nDistanceVector[nStartIndex] = 0;

	v = nStartIndex;
	while(bIntreeVector[v] == false)
	{

		bIntreeVector[v] = true; // add node to tree

		// go through all new edges and update distance from nStart to w if necessary
		aux = m_Edges[v];
		while(aux != NULL)
		{
			// end vertex of edge
			w = aux->m_y;
			weight = aux->m_nWeight;

			// we found a shoter path from v to w and w is not in current tree
			if(nDistanceVector[w] > weight && bIntreeVector[w] == false)
			{
				nDistanceVector[w] = weight; // update distance 
				m_nParent[w] = v; // and parent
			}

			aux = aux->m_pNext;

		}

		minDist = INIFITE;
		bool bAddedVertex = false;

		// go through all vertices
		for(int i = 1; i <= m_nVertices; ++i)
		{
			// i not in tree
			if(bIntreeVector[i] == false && minDist > nDistanceVector[i])
			{
				minDist = nDistanceVector[i];
				v = i;
				bAddedVertex = true;
			}
		}

		if(bAddedVertex)
			std::cout << "Going to node " << v << " path cost " << minDist << " from " << m_nParent[v] << "\n"; 
	}
}


// O(n^2)
// O(m log n) --> is using heaps instead of distance vector --> sparse graphs --> numar de laturi liniar cu nr de noduri
void Graph::DijkstraAlgorithm(int nStartIndex)
{
	InitSearch(); // not all ops from init necessary 

	EdgeNode* aux;
	std::vector<bool> bIntreeVector(MAX_VERTICES, false); // is the vertex in the tree yet
	std::vector<int> nDistanceVector(MAX_VERTICES, INIFITE); // distance from startIndex 

	int weight; // edge weight;
	int index;
	int v; // current vertex to process
	int w;
	int minDist = INIFITE; // current minimum distance

	nDistanceVector[nStartIndex] = 0;

	v = nStartIndex;
	while(bIntreeVector[v] == false)
	{
		std::cout << "Analizing edges from node " << v << "\n";
		bIntreeVector[v] = true; // add node to tree

		// go through all new edges --> O(m) complexity and if adding to heap --> O(m log n) 
		aux = m_Edges[v];
		while(aux != NULL)
		{
			// end vertex of edge
			w = aux->m_y;
			weight = aux->m_nWeight;

			// compute current distance to W from v through this edge and updte if smaller
			if(nDistanceVector[w] > nDistanceVector[v] + weight)
			{
				// better algorithm --> use heap instead of distance vector ( add it to heap ) 
				nDistanceVector[w] = nDistanceVector[v] + weight; // update distance 
				m_nParent[w] = v; // and parent
				std::cout << "\tFound a better way to " << w << " new parent " << v << " and distance " << nDistanceVector[w] << "\n";
			}

			aux = aux->m_pNext;

		}

		minDist = INIFITE;
		bool bAddedVertex = false;
		
		// if using heap just get the minimum --> O(log n) --> complexity 
		// go through all vertices -- and add minimum distance
		for(int i = 1; i <= m_nVertices; ++i)
		{
			// i not in tree 
			if(bIntreeVector[i] == false && minDist > nDistanceVector[i])
			{
				minDist = nDistanceVector[i];
				v = i;
				bAddedVertex = true;
				std::cout << "Added node " << i << " --> ";
			}
		}
	}
}



void ProcessSolution(int*&a, int k, int n)
{
	std::cout << "Path: ";
	for(int i = 1; i <= k; ++i)
	{
		if(i != k)
			std::cout << a[i] << ", ";
		else
			std::cout << a[i] << "\n";
	}
}

// n is the final vertex
bool IsASolution(int*&a, int k, int n)
{
	return a[k] == n;
}

void Graph::ConstructCandidate(int*&a, int k, int n, int*& candidates, int& nCandidates)
{
	int nMAX_VERTICES = 100;
	bool bInVertices[100] = { false };

	for(int i = 1; i < k; i++ )
	{
		if(a[i])
			bInVertices[a[i]] = true;
	}

	nCandidates = 0;
	// get lat node in current path
	EdgeNode* aux = m_Edges[a[k-1]];
	while(aux != NULL)
	{
		int y = aux->m_y;
		if(bInVertices[y] == false)
		{
			candidates[nCandidates] = y;
			nCandidates++;
		}
		aux = aux->m_pNext;
	}
}

void Graph::ConstructAllPaths(int nStartIndex, int nNodeIndex)
{
	int* a = new int[m_nVertices]();
	a[1] = nStartIndex;

	backtrack(a, 1, nNodeIndex);

	delete []a;
}

void Graph::backtrack(int*& a, int k, int n)
{
	const int MAX_CANDIDATES = 100;
	int* candidates = new int[MAX_CANDIDATES];
	int nCandidates = 0;

	if(IsASolution(a, k, n))
	{
		ProcessSolution(a, k, n);
	}
	else
	{
		k++;
		ConstructCandidate(a, k, n, candidates, nCandidates);
		for(int i = 0; i < nCandidates; i++)
		{
			a[k] = candidates[i];
			backtrack(a, k, n);	
		}
	}

	delete []candidates;
}



