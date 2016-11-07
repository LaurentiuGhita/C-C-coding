#include "List.h"


list *search_list(list* pHead, int nVal)
{
	if (pHead == NULL)
		return NULL;

	if(pHead->nVal == nVal)
		return pHead;

	return search_list(pHead->pNext, nVal);
}


/*insert in front*/
void insertList(list** pHead, int nVal)
{
	list* pNewElem = malloc(sizeof(list));

	pNewElem->nVal = nVal;
	pNewElem->pNext = *pHead;
	*pHead = pNewElem;
}

list* findPredecesor(list* pHead, int nVal)
{
	if(pHead == NULL)
		return NULL;

	if(pHead->pNext != NULL && pHead->pNext->nVal == nVal)
		return pHead;
	else
		findPredecesor(pHead->pNext, nVal);
}

int deleteList(list** pHead, int nVal)
{

	list* pNodeToDelete = search_list(*pHead, nVal);
	if(pNodeToDelete)
	{
		list* pNodePred = findPredecesor(*pHead, nVal);
		if(pNodePred == NULL)
		{
			*pHead = pNodeToDelete->pNext;
		}
		else
		{
			pNodePred->pNext = pNodeToDelete->pNext;
		}

		free(pNodeToDelete);
	}
}

void printList(list* pHead)
{
	if(pHead == NULL)
		return;

	while(pHead != NULL)
	{
		printf("%d ", pHead->nVal);
		pHead = pHead->pNext;
	}

	printf("\n");
}

void freeList(list** pHead)
{
	list* pNode = *pHead;
	if(pNode == NULL)
		return;

	
	*pHead = pNode->pNext;
	free(pNode);
	freeList(pHead);
}


int main()
{
	list* myList;

	insertList(&myList, 1);
	insertList(&myList, 10);
	insertList(&myList, 12);
	insertList(&myList, 6);
	insertList(&myList, 9);
	printList(myList);

	printList(myList);
	#if 0
	deleteList(&myList, 1);
	deleteList(&myList, 12);
	deleteList(&myList, 10);
	deleteList(&myList, 9);
	deleteList(&myList, 6);
	#endif
	printList(myList);

	freeList(&myList);
	return 0;
}

