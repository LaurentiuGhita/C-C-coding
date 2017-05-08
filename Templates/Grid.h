#ifndef GRID_H
#define GRID_H

#include <iostream>

template <typename T>
class Grid
{
public:
    Grid(std::size_t nWidth = DEFAULT_WIDTH, std::size_t nHeight = DEFAULT_HEIGHT);
    ~Grid();

    // copy ctors
    Grid(const Grid<T>& src); 
    template<typename E>
    Grid(const Grid<E>& src);

    //assignment operator
    Grid<T>& operator=(const Grid<T>& rhs);
    template<typename E>
    Grid<T>& operator=(const Grid<E>& rhs);

    /* setters */
    void SetElementAt(std::size_t nX, std::size_t nY, const T& inElem);
    
    /* getters */
    T& GetElementAt(std::size_t nX, std::size_t nY);
    const T& GetElementAt(std::size_t nX, std::size_t nY) const;
    std::size_t GetWidth() const { return m_nWidth; }
    std::size_t GetHeight() const { return m_nHeight; }

    static const std::size_t DEFAULT_WIDTH = 10;
    static const std::size_t DEFAULT_HEIGHT = 10;

protected:
    
    void CopyFrom(const Grid<T>& src);
    template <typename E>
    void CopyFrom(const Grid<E>& src);

    T** mCells;
    std::size_t m_nWidth;
    std::size_t m_nHeight;
};


template <typename T>
Grid<T>::Grid(std::size_t nWidth, std::size_t nHeight) :
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
    std::cout << "Copy ctor\n";
    CopyFrom(src);
}

template <typename T>
template <typename E>
Grid<T>::Grid(const Grid<E>& src)
{
    std::cout << "Templatized copy ctor\n";
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
template<typename E>
Grid<T>& Grid<T>::operator=(const Grid<E>& rhs)
{
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

template <typename T>
template <typename E>
void Grid<T>::CopyFrom(const Grid<E>& src)
{
    m_nWidth = src.GetWidth();
    m_nHeight = src.GetHeight();

    mCells = new T*[m_nWidth];
    
    for(int i = 0; i < m_nWidth; ++i)
    {
        mCells[i] = new T[m_nHeight];
    }

    for(int i = 0; i < m_nWidth; ++i)
    {
        for(int j = 0; j < m_nHeight; ++j)
        {
            mCells[i][j] = src.GetElementAt(i,j);
        }
    } 
}

template<typename T>
void Grid<T>::SetElementAt(std::size_t nX, std::size_t nY, const T& inElem)
{
    mCells[nX][nY] = inElem;
}

template<typename T>
T& Grid<T>::GetElementAt(std::size_t nX, std::size_t nY)
{
    return mCells[nX][nY];
    
}

template<typename T>
const T& Grid<T>::GetElementAt(std::size_t nX, std::size_t nY) const
{
    return mCells[nX][nY];
    
}

#endif