#include "BinarySearchTree.h"

TreeNode::TreeNode(int nVal, TreeNode* pParent) : m_nVal(nVal) 
{ 
	m_pRightChild = m_pLeftChild = NULL; 
	m_pParent = pParent;
}

void BinarySearchTree::AddElement(int nVal)
{
	return AddElementHelper(nVal, m_pRoot);
}

bool BinarySearchTree::SearchElement(int nVal)
{
	if(NULL != SearchElementHelper(nVal, m_pRoot))
		return true;
	return false;
}

bool BinarySearchTree::DeleteElement(int nVal)
{
	DeleteElementHelper(nVal, m_pRoot);
}


void BinarySearchTree::PrintBinaryTree()
{
	PrintTree(m_pRoot);
}

void BinarySearchTree::AddElementHelper(int nVal, TreeNode*& pRoot)
{
	if(pRoot == NULL)
	{
		pRoot = new TreeNode(nVal, NULL);
	}
	else
	{
		if(nVal < pRoot->m_nVal) 
		{
			if(pRoot->m_pLeftChild == NULL)
				pRoot->m_pLeftChild = new TreeNode(nVal, pRoot);
			else
				AddElementHelper(nVal, pRoot->m_pLeftChild);			
		}
		if(nVal >= pRoot->m_nVal) 
		{
			if(pRoot->m_pRightChild == NULL)
				pRoot->m_pRightChild = new TreeNode(nVal, pRoot);
			else
				AddElementHelper(nVal, pRoot->m_pRightChild);
		}
	}
}

TreeNode* BinarySearchTree::SearchElementHelper(int nVal, const TreeNode* pRoot)
{
	if(pRoot == NULL)
		return NULL;

	if(pRoot->m_nVal == nVal)
		return const_cast<TreeNode*> (pRoot);

	if(nVal < pRoot->m_nVal)
		return SearchElementHelper(nVal, pRoot->m_pLeftChild);
	else
		return SearchElementHelper(nVal, pRoot->m_pRightChild);
}

bool BinarySearchTree::DeleteElementHelper(int nVal, TreeNode*& pRoot)
{
	TreeNode* nodeToDelete = SearchElementHelper(nVal, pRoot);
	if(nodeToDelete == NULL)
		return false;
	else
	{
		TreeNode* nodeToReplaceWith = GetRightMostNode(nodeToDelete->m_pLeftChild);
		if(nodeToReplaceWith)
		{
			std::cout << nodeToDelete->m_nVal << " will be replaced with " << nodeToReplaceWith->m_nVal << "\n";
			
			/* switch values*/
			nodeToDelete->m_nVal = nodeToReplaceWith->m_nVal;

			if(nodeToReplaceWith->m_pParent)
				nodeToReplaceWith->m_pParent->m_pRightChild = NULL; // erase link to current right most node
		}
		else
		{
			if(nodeToDelete->m_pParent)
			{
				if(nodeToDelete->m_pParent->m_nVal > nodeToDelete->m_nVal)
					nodeToDelete->m_pParent->m_pLeftChild = NULL;
				else
					nodeToDelete->m_pParent->m_pRightChild = NULL;
			}
			delete nodeToDelete;
		}
	}
	return true;
}

TreeNode* BinarySearchTree::GetRightMostNode(TreeNode*& pRoot)
{
	if(pRoot == NULL)
		return NULL;

	TreeNode* m_pRightChild = pRoot->m_pRightChild;
	if(m_pRightChild)
		GetRightMostNode(pRoot->m_pRightChild);
	else
		return pRoot;
}

void BinarySearchTree::PrintTree(TreeNode* pRoot)
{
	if(pRoot == NULL)
		return;

	int nParentVal;
	bool bHasParent = false;
	if(pRoot->m_pParent)
	{
		bHasParent = true;
		nParentVal = pRoot->m_pParent->m_nVal;
	}

	if(bHasParent)
		std::cout << pRoot->m_nVal << "--> with parent " << nParentVal << "\n";
	else
		std::cout << pRoot->m_nVal << "\n";


	
	if(pRoot->m_pLeftChild)
	{
		std::cout << "left child\n ";
		PrintTree(pRoot->m_pLeftChild);
	}

	
	if(pRoot->m_pRightChild)
	{
		std::cout << "right child\n";
		PrintTree(pRoot->m_pRightChild);
	}
}

