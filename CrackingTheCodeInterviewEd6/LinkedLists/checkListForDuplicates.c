#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	struct Node* m_pNext;
	int m_nVal;
}Node;

void AddToList(Node** pHead, int nElement)
{
	Node* currentHead = *pHead;

	Node* newNode = malloc(sizeof(Node)); 
	newNode->m_pNext = NULL;
	newNode->m_nVal = nElement;

	if(currentHead == NULL)
	{
		*pHead = newNode;
	}
	else
		AddToList(&currentHead->m_pNext, nElement);
}

bool DeleteFromList(Node** pHead, int nElement)
{
	Node* pCurrentHead = *pHead;

	if(pCurrentHead == NULL)
		return;

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

void RemoveDuplicates(Node** pHead)
{
	Node* pCurrentHead = *pHead;

	while(pCurrentHead != NULL)
	{

	}
}

int main()
{
	Node* pHead = NULL;
	AddToList(&pHead, 10);
	AddToList(&pHead, 11);
	AddToList(&pHead, 12);
	DeleteFromList(&pHead, 11);
	DeleteFromList(&pHead, 12);
	DeleteFromList(&pHead, 10);

	PrintList(pHead);
}
