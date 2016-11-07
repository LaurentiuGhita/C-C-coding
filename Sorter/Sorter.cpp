#include "Sorter.h"
#include "../Utils/utils.h"

Sorter::Sorter(std::istream& in)
{
	std::cout << "Enter size of vector\n";
	in >> m_nSize;

	for(int i = 0; i < m_nSize; i++)
	{
		int aux;
		in >> aux;
		m_unsortedElements.push_back(aux);
	}
}

Sorter::Sorter(std::vector<int> input)
{
	m_unsortedElements = input;
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






