#include "Heap.h"

#include <iostream>

int Heap::GetParentIndex(int nChildIndex)
{
	if(nChildIndex <= INVALID_INDEX)
		return INVALID_INDEX;

	if(nChildIndex % 2 == 0)
		return (nChildIndex - 2) / 2;
	else
		return (nChildIndex - 1) / 2; 
}

void Heap::Heapify()
{

}

void Heap::HeapifyHelper(HeapElement* pRoot)
{
	int nFirstChildIndex = GetFirstChildIndex(pRoot->m_nIndex);
	int nSecondChildIndex = GetSecondChildIndex(pRoot->m_nIndex);

	HeapElement* pFirstChild = NULL;
	HeapElement* pSecondChild = NULL;

	if(nFirstChildIndex < m_nSize)
		pFirstChild = &m_Elements[nFirstChildIndex];

	if(nSecondChildIndex < m_nSize)
		pSecondChild = &m_Elements[nFirstChildIndex];
}
