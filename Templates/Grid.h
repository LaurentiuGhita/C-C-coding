#ifndef GRID_H
#define GRID_H

#include <iostream>

template <typename T>
class Grid
{
public:
    Grid(int nWidth = DEFAULT_WIDTH, int nHeight = DEFAULT_HEIGHT);
    Grid(const Grid<T>& src); // copy ctor
    ~Grid();
    Grid<T>& operator=(const Grid<T>& rhs);

    /* setters */
    void SetElementAt(int nX, int nY, const T& inElem);
    
    /* getters */
    T& GetElementAt(int nX, int nY);
    const T& GetElementAt(int nX, int nY) const;
    int GetWidth() { return m_nWidth; }
    int GetHeight() { return m_nHeight; }

    static const int DEFAULT_WIDTH = 10;
    static const int DEFAULT_HEIGHT = 10;

protected:
    void CopyFrom(const Grid<T>& src);
    T** mCells;
    int m_nWidth;
    int m_nHeight;
};

#endif