#include "BinaryTree.h"

const int INTEGER_MIN = -9999;

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
	}
	else
	{
		if(nVal <= (*pRoot)->m_nVal)
		{
			Insert(&(*pRoot)->m_pLeftChild, nVal);

		}
		else
		{
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

bool CheckIfBinarySearchTree(Node* pRoot)
{
	
}

int main()
{
	Node *pRoot = NULL;

	Insert(&pRoot, 2);
	Insert(&pRoot, 1);
	Insert(&pRoot, 3);

	IsBalanced(pRoot);

	Insert(&pRoot, 4);
	//Insert(&pRoot, 5);
	IsBalanced(pRoot);

}

