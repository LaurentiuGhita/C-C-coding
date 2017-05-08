#ifndef GRID_H
#define GRID_H

#include <iostream>

template < typename T, int WIDTH, int HEIGHT>
class Grid
{
public:
    void SetElementAt(int x, int y, const T& inElem);
    T& GetElementAt(int x, int y);
    const T& GetElementAt(int x, int y) const;

    int GetWidth() const { return HEIGHT; }
    int GetHeight() const { return WIDTH; }

protected:
    T mCells[WIDTH][HEIGHT];
};


template < typename T, int WIDTH, int HEIGHT >
void Grid<T, WIDTH, HEIGHT>::SetElementAt(int x, int y, const T& inElem)
{
        mCells[x][y] = inElem;
}

template < typename T, int WIDTH, int HEIGHT >
T& Grid<T, WIDTH, HEIGHT>::GetElementAt(int x, int y)
{
    return mCells[x][y];
}

template < typename T, int WIDTH, int HEIGHT >
const T& Grid<T, WIDTH, HEIGHT>::GetElementAt(int x, int y) const
{
    return mCells[x][y];
}

#endif
