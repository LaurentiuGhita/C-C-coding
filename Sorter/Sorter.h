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

	void SelectionSort();
private:

	int m_nSize;
	std::vector<int> m_unsortedElements;
};

#endif