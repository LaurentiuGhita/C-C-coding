#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node
{
	struct Node* m_pNext;
	int m_nVal;
}Node;

void AddToList(Node** pHead, int nElement);
bool DeleteFromList(Node** pHead, int nElement);
void PrintList(Node* pHead);
void ReadList(Node** pHead);