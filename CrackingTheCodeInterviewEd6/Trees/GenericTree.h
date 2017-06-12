#ifndef GENERIC_TREE_H
#define GENERIC_TREE_H
#include <iostream>
#include <unordered_set>
#include <memory>

class Node;
using SharedNodePointer = std::shared_ptr<Node> ;
using WeakNodePointer = std::weak_ptr<Node> ; 

class Node
{
public:
	Node(int nVal) : m_nVal(nVal), m_pParent(nullptr) {}

	int Value() { return m_nVal; }
	void SetParent(SharedNodePointer pParent) { m_pParent = pParent; }
	void Add(SharedNodePointer pChild) { if(pChild) childs.insert(pChild);}
	std::unordered_set<SharedNodePointer> GetChilds() { return childs; }
private:
	int m_nVal;
	SharedNodePointer m_pParent;
	std::unordered_set<SharedNodePointer> childs; //links to childs
};



class GenericTree
{
public:

	WeakNodePointer GetRoot() { WeakNodePointer pt = pRoot; return pt; }
	WeakNodePointer AddLink(int nParentVal, int nChildVal);
private:
	SharedNodePointer pRoot;
};

#endif