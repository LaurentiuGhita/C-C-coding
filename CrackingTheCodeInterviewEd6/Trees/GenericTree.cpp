#include "GenericTree.h"

#include <algorithm>

WeakNodePointer GenericTree::AddLink(int nParentVal, int nChildVal)
{
	if(pRoot == nullptr)
	{
		pRoot = std::make_shared<Node>(nParentVal);
	}

	SharedNodePointer parent = pRoot;
	// search for parent with nParentVal
	while(parent->Value() != nParentVal)
	{
		std::unordered_set<SharedNodePointer> childs;

		auto it = std::find_if(std::begin(childs), std::end(childs), 
				[&](SharedNodePointer const& Obj) { return Obj->Value() == parent->Value(); });

		if(it == child.end())
		{
				
			break;
		}
	}


	{	
		SharedNodePointer child = std::make_shared<Node>(nChildVal);
		child->SetParent(pRoot);
		
		pRoot->Add(child);
	}

}


int main()
{

}