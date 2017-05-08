#include "Grid.h"

int main()
{
    Grid<int> myIntGrid;

    Grid<double> myDoubleGrid;

    myIntGrid = myDoubleGrid;

    std::cout << myIntGrid.GetElementAt(0,0);
}