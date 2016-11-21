#ifndef HEAP_H
#define HEAP_H

const int START_SIZE = 10;


class Heap
{
public:
	Heap() : m_nSize(0), m_nMemorySize(START_SIZE) { m_nElements = new int[START_SIZE];}
	Heap(int nBeginSize), m_nSize(0),
	~Heap();

	int GetFirstChildIndex(int nParentIndex);

private:
	int m_nSize;
	int m_nMemorySize;
	int* m_nElements;


};

#endif