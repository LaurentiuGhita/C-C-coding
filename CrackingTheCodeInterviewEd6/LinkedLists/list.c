#include "list.h"


void AddToList(Node** pHead, int nElement)
{
	Node* currentHead = *pHead;

	if(currentHead == NULL)
	{
		Node* newNode = malloc(sizeof(Node)); 
		newNode->m_pNext = NULL;
		newNode->m_nVal = nElement;

		*pHead = newNode;
	}
	else
		AddToList(&currentHead->m_pNext, nElement);
}

bool DeleteFromList(Node** pHead, int nElement)
{
	Node* pCurrentHead = *pHead;

	if(pCurrentHead != NULL)
	{
		if(pCurrentHead->m_nVal == nElement)
		{
			*pHead = pCurrentHead->m_pNext;
			free(pCurrentHead);
		}
		else
		{
			Node* pNext = pCurrentHead->m_pNext; 
			if(pNext)
			{
				if(pNext->m_nVal == nElement)
				{
					pCurrentHead->m_pNext = pNext->m_pNext;
					free(pNext);
					*pHead = pCurrentHead;
				}
				else
				{
					DeleteFromList(&pNext, nElement);
				}
			}
		}		
	}

}

void PrintList(Node* pHead)
{
	Node* pCurrentHead = pHead;
	while(pCurrentHead != NULL)
	{
		printf("%d ", pCurrentHead->m_nVal);
		pCurrentHead = pCurrentHead->m_pNext;
	}
	printf("\n");
}

void PrintReverseList(Node* pHead)
{
	if(pHead)
	{
		PrintReverseList(pHead->m_pNext);
		printf("%d ", pHead->m_nVal);
	}	
}

void ReadList(Node** pHead)
{

	int nListMaxElements;
	int i;
	printf("element count = "); scanf("%d", &nListMaxElements);

	for(i = 0; i < nListMaxElements; ++i)
	{
		int aux;
		scanf("%d", &aux);
		AddToList(pHead, aux);
	}
}

int ListLength(Node* pHead)
{
	int count = 0;
	if(pHead)
	{
		while(pHead)
		{
			pHead = pHead->m_pNext;
			++count;
		}
	}
	return count;
}

void FreeList(Node** pHead)
{
	if(pHead && *pHead)
	{
		Node* pCurrentHead = *pHead;

		while(pCurrentHead)
		{
			Node* pToDelete = pCurrentHead;
			pCurrentHead = pCurrentHead->m_pNext;
			free(pToDelete);
		}
	}
}