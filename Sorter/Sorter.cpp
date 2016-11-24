#include "Sorter.h"
#include "../Utils/utils.h"
#include <queue>
#include <stdlib.h>
#include <time.h>  

Sorter::Sorter(std::istream& in)
{
	std::cout << "Enter size of vector\n";
	in >> m_nSize;

	for(int i = 0; i < m_nSize; i++)
	{
		int aux;
		in >> aux;
		m_unsortedElements.push_back(aux);
		m_mergeSortedElements.push_back(aux);
		m_quickSortElements.push_back(aux);
	}
}

Sorter::Sorter(std::vector<int> input)
{
	m_unsortedElements = input;
	m_mergeSortedElements = input;
	m_mergeSortedElements = input;
}

void Sorter::SelectionSort()
{
	std::vector<int> sortedVector;
	sortedVector = m_unsortedElements;

	for(int i = 0; i < sortedVector.size() - 1; i++)
	{
		int minIndex = i;
		for(int j = i + 1; j < sortedVector.size(); j++)
		{
			if(sortedVector[j] < sortedVector[minIndex])
				minIndex = j;
		}
		if(minIndex != i)
			mySwap(sortedVector[i], sortedVector[minIndex]);
	}

	printVector(sortedVector);
}

void Sorter::Merge(std::vector<int>& elements, int nStart, int nMiddle, int nEnd)
{
	std::queue<int> leftSide;
	std::queue<int> rightSide;
	for(int i = nStart; i <= nEnd; i++)
	{
		if(i <= nMiddle)
		{

			leftSide.push(elements[i]);
		}
		else
		{
			rightSide.push(elements[i]);
		}
	}

	int index = nStart;
	while(!leftSide.empty() && !rightSide.empty())
	{
		if(leftSide.front() < rightSide.front())
		{
			elements[index] = leftSide.front();
			leftSide.pop();
		}
		else
		{
			elements[index] = rightSide.front();
			rightSide.pop();
		}

		index++;
	}

	/*copy rest of elements*/
	if(!leftSide.empty())
	{
		while(!leftSide.empty())
		{
			elements[index] = leftSide.front();
			leftSide.pop();
			++index;
		}
	}

	if(!rightSide.empty())
	{
		while(!rightSide.empty())
		{
			elements[index] = rightSide.front();
			rightSide.pop();
			++index;
		}
	}
}

void Sorter::MergeSort(int nStart, int nEnd)
{
	if(nStart < nEnd)
	{
		int nMiddle = (nStart + nEnd) / 2;
		MergeSort(nStart, nMiddle);
		MergeSort(nMiddle + 1, nEnd);
		Merge(m_mergeSortedElements, nStart, nMiddle, nEnd);
	}
}

void Sorter::PrintMergeSorted()
{
	std::cout << "Merge sorted: ";
	for(int i = 0; i < m_mergeSortedElements.size(); i++)
		std::cout << m_mergeSortedElements[i] << " ";

	std::cout << "\n";
}

void Sorter::QuickSort(int nStart, int nEnd)
{
 	srand (time(NULL));
	int nPivotIndex = nStart + rand() % (end - nStart + 1);

	int nLessThanIndex = nStart;
	int nBiggerThanIndex = nPivotIndex + 1;

	
}






