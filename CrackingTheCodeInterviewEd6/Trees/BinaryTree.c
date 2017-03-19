#include "BinaryTree.h"

const int INTEGER_MIN = -9999;
const int INTEGER_MAX = 9999;

int max(int a, int b)
{
	if(a < b)
		return b;

	return a;
}

void Insert(Node** pRoot, int nVal)
{

	if(*pRoot == NULL)
	{
		*pRoot = malloc(sizeof(Node));
		(*pRoot)->m_nVal = nVal;
		(*pRoot)->m_pRightChild = NULL;
		(*pRoot)->m_pLeftChild = NULL;
		(*pRoot)->m_pParent = NULL;
	}
	else
	{
		if(nVal <= (*pRoot)->m_nVal)
		{
			if((*pRoot)->m_pLeftChild == NULL)
			{
				Node* pnew = malloc(sizeof(Node));
				pnew->m_nVal = nVal;
				pnew->m_pRightChild = NULL;
				pnew->m_pLeftChild = NULL;
				pnew->m_pParent = *pRoot;
				(*pRoot)->m_pLeftChild = pnew;	
			}
			else	
				Insert(&(*pRoot)->m_pLeftChild, nVal);

		}
		else
		{
			if((*pRoot)->m_pRightChild == NULL)
			{
				Node* pnew = malloc(sizeof(Node));
				pnew->m_nVal = nVal;
				pnew->m_pRightChild = NULL;
				pnew->m_pLeftChild = NULL;
				pnew->m_pParent = *pRoot;
				(*pRoot)->m_pRightChild = pnew;
			}
			else
				Insert(&(*pRoot)->m_pRightChild, nVal);
		}
	}
}

void TraverseInOrder(Node* pRoot)
{
	if(pRoot)
	{
		TraverseInOrder(pRoot->m_pLeftChild);
		printf("%d\n", pRoot->m_nVal);		
		TraverseInOrder(pRoot->m_pRightChild);
	}
}

void TraversePreOrder(Node* pRoot)
{
	if(pRoot)
	{
		printf("%d\n", pRoot->m_nVal);
		TraversePreOrder(pRoot->m_pLeftChild);
		TraversePreOrder(pRoot->m_pRightChild);
	}
}

void TraversePostOrder(Node* pRoot)
{
	if(pRoot)
	{
		TraversePostOrder(pRoot->m_pLeftChild);
		TraversePostOrder(pRoot->m_pRightChild);
		printf("%d\n", pRoot->m_nVal);
	}
}

int GetHeight(Node* pRoot)
{
	if(pRoot == NULL)
		return -1;

	int nLeftHeight = GetHeight(pRoot->m_pLeftChild);
	int nRightHeight = GetHeight(pRoot->m_pRightChild);

	int nMax = nLeftHeight < nRightHeight ? nRightHeight : nLeftHeight;

	int nLen = 1 + nMax;

	return nLen;
}

int CheckHeight(Node* pRoot)
{
	if(pRoot == NULL)
		return -1;

	int nHeightLeft = CheckHeight(pRoot->m_pLeftChild);
	if(nHeightLeft == INTEGER_MIN)
		return INTEGER_MIN;

	int nHeightRight = CheckHeight(pRoot->m_pRightChild);
	if(nHeightRight == INTEGER_MIN)
		return INTEGER_MIN;

	int heightDiff = nHeightRight - nHeightLeft;
	if(abs(heightDiff) > 1)
		return INTEGER_MIN;
	else
		return max(nHeightLeft, nHeightRight) + 1;
}


bool IsBalanced(Node* pRoot)
{
	if(CheckHeight(pRoot) != INTEGER_MIN)
	{
		printf("Is balanced \n");
		return true;

	}
	else
	{
		printf("Not balanced \n");
		return false;
	}
}

bool CheckIfBinarySearchTree(Node* pRoot, int min , int max, bool bRoot)
{

	if(pRoot == NULL)
		return true;

	if(pRoot->m_nVal > max || pRoot->m_nVal < min)
		return false;

	int bLeft = CheckIfBinarySearchTree(pRoot->m_pLeftChild, INTEGER_MIN, pRoot->m_nVal, false);
	
	if(!bLeft)
		return false;

	bool bRight = CheckIfBinarySearchTree(pRoot->m_pRightChild, pRoot->m_nVal, INTEGER_MAX, false);
	if(!bRight)
		return false;

	return true;
}


int IsLeftChild(Node* pParent, Node* pChild)
{
	if(!pParent || !pChild)
		return -1;

	int nChildVal = pChild->m_nVal;
	int nParentVal = pParent->m_nVal;

	if(nChildVal <= nParentVal)
		return 1;
	else
		return 0;
}

int GetSuccessor(Node* pNode)
{
	if(pNode->m_pRightChild)
	{
		printf("Successor %d \n", pNode->m_pRightChild->m_nVal);
		return pNode->m_pRightChild->m_nVal;
	}

	Node* pParent = pNode->m_pParent;
	Node* pCurrent = pNode;

	int nRet = IsLeftChild(pParent, pCurrent); 
	while( nRet == 0)
	{
		pCurrent = pParent;
		pParent = pParent->m_pParent;
		nRet = IsLeftChild(pParent, pCurrent); 
	}
	
	if(nRet == -1)
	{
		printf("Node has no successor\n");
		return -1;
	}
	else
	{
		printf("Successor %d \n", pParent->m_nVal);
	}
}

int main()
{
	Node *pRoot = NULL;

	Insert(&pRoot, 3);
	Insert(&pRoot, 1);
	Insert(&pRoot, 4);
	Insert(&pRoot, 2);

	Node* pNew = malloc(sizeof(Node));
	pNew->m_nVal = 100;
	pNew->m_pRightChild = NULL;
	pNew->m_pLeftChild = NULL;

	//pRoot->m_pLeftChild->m_pRightChild = pNew;

	bool bIsBST = CheckIfBinarySearchTree(pRoot, INTEGER_MIN, INTEGER_MAX, true);
	if(bIsBST)
		printf("Is binary saerch tree\n");
	else
		printf("Not a binary tree\n");

	GetSuccessor(pRoot->m_pLeftChild->m_pRightChild);
}