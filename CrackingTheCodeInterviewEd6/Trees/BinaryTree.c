#include "BinaryTree.h"

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


int main()
{
	Node *pRoot = NULL;

	Insert(&pRoot, 2);
	Insert(&pRoot, 1);
	Insert(&pRoot, 3);
	TraverseInOrder(pRoot);
	TraversePreOrder(pRoot);
	TraversePostOrder(pRoot);
}

