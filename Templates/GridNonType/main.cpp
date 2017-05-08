#include "Grid.h"

int main()
{
    Grid<int, 10, 10> myGrid;
    Grid<int ,10, 10> my2Grid;

    my2Grid = myGrid;

    /*
    * won't compile 
    Grid<int, 11, 11> my3Grid;
    my2Grid = my3Grid;
    
    */
}