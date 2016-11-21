#ifndef HEAP_H
#define HEAP_H

const int START_SIZE = 10;
const int INVALID_INDEX = -1;

struct HeapElement
{
	HeapElement();
	HeapElement(int nVal, int nIndex) : m_nVal(nVal), m_nPriority(nVal), m_nIndex(nIndex) {}
	HeapElement(int nVal, int nPriority, int nIndex) : m_nVal(nVal), m_nPriority(nPriority), m_nIndex(nIndex) {}
	void SetIndex(int nIndex) { m_nIndex = nIndex; }
	int m_nVal;
	int m_nPriority;
	int m_nIndex;
};

class Heap
{
public:
	Heap() : m_nSize(0), m_nMemorySize(START_SIZE) { m_Elements = new HeapElement[START_SIZE];}
	~Heap();

	int GetFirstChildIndex(int nParentIndex) { return nParentIndex * 2 + 1;}
	int GetSecondChildIndex(int nParentIndex) { return nParentIndex * 2 + 2; }
	int GetParentIndex(int nChildIndex);
	void Heapify();

private:
	void HeapifyHelper(HeapElement* pRoot);

	int m_nSize;
	int m_nMemorySize;
	HeapElement* m_Elements;
};

#endif