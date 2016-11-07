#include "BinarySearchTree.h"

BinarySearchTree::AddElement(Node*& rootNode, int nVal)
{
	TreeNode* newNode = TreeNode(nVal);

	if(m_pRoot == NULL)
	{
		m_pRoot = newNode;
	}


}