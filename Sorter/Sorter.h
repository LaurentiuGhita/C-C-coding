#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <fstream>
#include <vector>

class Sorter
{
public:
	Sorter(std::istream& stream);
	Sorter(std::vector<int> input);

	void Merge(std::vector<int>& elements, int nStart, int nMiddle, int nEnd);

	void MergeSort() { MergeSort(0, m_mergeSortedElements.size());}
	void MergeSort(int nStart, int nEnd);
	void SelectionSort();

	void PrintMergeSorted();
private:

	int m_nSize;
	std::vector<int> m_unsortedElements;
	std::vector<int> m_mergeSortedElements;
};

#endif