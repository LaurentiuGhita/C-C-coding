#include "BinarySearchTree.h"

TreeNode::TreeNode(int nVal, TreeNode* pParent) : m_nVal(nVal) 
{ 
	m_pRightChild = m_pLeftChild = NULL; 
	m_pParent = pParent;
}

BinarySearchTree::~BinarySearchTree()
{
	FreeTree(m_pRoot);
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
	TreeNode* nodeToReplace = SearchElementHelper(nVal, pRoot);
	if(nodeToReplace == NULL)
		return false;
	else
	{
		/* leaf node */
		if(nodeToReplace->m_pLeftChild == NULL && nodeToReplace->m_pRightChild == NULL)
		{
			/* check if left of right child of parent*/
			if(nodeToReplace->m_pParent)
			{
				// left child of parent
				if(nodeToReplace->m_nVal < nodeToReplace->m_pParent->m_nVal)
				{
					nodeToReplace->m_pParent->m_pLeftChild = NULL;
					
				}
				else
				{
					nodeToReplace->m_pParent->m_pRightChild = NULL;
				}
				delete nodeToReplace;
			}
		}
		else
		{
			TreeNode* nodeToReplaceWith = GetRightMostNode(nodeToReplace->m_pLeftChild);
			if(nodeToReplaceWith == NULL)
			{
				if(nodeToReplace->m_nVal < nodeToReplace->m_pParent->m_nVal)
					nodeToReplace->m_pParent->m_pLeftChild = nodeToReplace->m_pLeftChild;
				else
					nodeToReplace->m_pParent->m_pRightChild = nodeToReplace->m_pLeftChild;

				delete nodeToReplace;
			}
			else
			{
				nodeToReplaceWith->m_pRightChild 
			}

		}



		if(nodeToReplaceWith)
		{
			std::cout << nodeToReplace->m_nVal << " will be replaced with " << nodeToReplaceWith->m_nVal << "\n";
		

		}
		else
		{
			if(nodeToReplace->m_pParent)
			{
				if(nodeToReplace->m_pParent->m_nVal > nodeToReplace->m_nVal)
					nodeToReplace->m_pParent->m_pLeftChild = NULL;
				else
					nodeToReplace->m_pParent->m_pRightChild = NULL;
			}
			delete nodeToReplace;
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

void BinarySearchTree::FreeTree(TreeNode* pRoot)
{
	if(pRoot == NULL)
		return;
	FreeTree(pRoot->m_pLeftChild);
	FreeTree(pRoot->m_pRightChild);

	delete pRoot;
}

