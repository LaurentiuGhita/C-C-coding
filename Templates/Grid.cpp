#include "Grid.h"

template <typename T>
Grid<T>::Grid(int nWidth, int nHeight) :
    m_nWidth(nWidth), m_nHeight(nHeight)
{
    mCells = new T*[m_nWidth];
    for(int i = 0; i < m_nWidth; ++i)
    {
        mCells[i] = new T[m_nHeight];
    }
}

template<typename T>
Grid<T>::Grid(const Grid<T>& src)
{
    CopyFrom(src);
}

template<typename T>
Grid<T>::~Grid()
{
    for(int i = 0; i < m_nWidth; ++i)
        delete [] mCells[i];

    delete [] mCells;
    mCells = NULL;
}

template<typename T>
Grid<T>& Grid<T>::operator=(const Grid<T>& rhs)
{
    if(this == &rhs)
        return *this;

    /* delete old used memory*/
    for(int i = 0; i < m_nWidth; ++i)
    {
        delete []mCells[i];
    }
    delete [] mCells;
    mCells = NULL;

    CopyFrom(rhs);
    return *this;
}


template<typename T>
void Grid<T>::CopyFrom(const Grid<T>& src)
{
    m_nWidth = src.m_nWidth;
    m_nHeight = src.m_nHeight;
    mCells = new T*[m_nWidth];
    
    for(int i = 0; i < m_nWidth; ++i)
    {
        mCells[i] = new T[m_nHeight];
    }

    for(int i = 0; i < m_nWidth; ++i)
    {
        for(int j = 0; j < m_nHeight; ++j)
        {
            mCells[i][j] = src.mCells[i][j];
        }
    } 
}

template<typename T>
void Grid<T>::SetElementAt(int nX, int nY, const T& inElem)
{
    mCells[nX][nY] = inElem;
}

template<typename T>
T& Grid<T>::GetElementAt(int nX, int nY)
{
    std::cout << "Non const method\n";
    return mCells[nX][nY];
    
}

template<typename T>
const T& Grid<T>::GetElementAt(int nX, int nY) const
{
    std::cout << "Const method\n";
    return mCells[nX][nY];
    
}


int main()
{
    const Grid<int> myIntGrid;

    int nHeight = 10;
    int nWidth = 10;

    //for(int i = 0; i < nWidth; ++i)
     //   for(int j = 0; j < nHeight; ++j)
       //     myIntGrid.SetElementAt(i,j, i + j);


    int element = myIntGrid.GetElementAt(1,1);
    const int& constElem = myIntGrid.GetElementAt(1,1);
}