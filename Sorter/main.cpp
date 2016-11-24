#include <iostream>

#include "Sorter.h"

int main()
{

	std::vector<int> input;
	input.push_back(22);
	input.push_back(1);
	input.push_back(10);
	input.push_back(5);
	input.push_back(4);
	input.push_back(2);
	input.push_back(99);

	Sorter mySorter(input);

	mySorter.MergeSort();
	mySorter.PrintMergeSorted();
}
