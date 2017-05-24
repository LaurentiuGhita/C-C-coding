#ifndef SUPER_SMART_POINTER_H
#define SUPER_SMART_POINTER_H

#include <iostream>
#include <memory>
#include <map>

template <typename T>
class SuperSmartPointer
{
public:
    explicit SuperSmartPointer(T* inPtr); // for conversions
    virtual ~SuperSmartPointer();

    SuperSmartPointer(const SuperSmartPointer<T>& src); // copy c-tor
    SuperSmartPointer<T>& operator=(const SuperSmartPointer<T>& rhs); // assignment operator

    const T& operator*() const;
    const T* operator->() const;

    T& operator*();
    T* operator->();

    operator void*() const { return mPtr;} // used when converting an istance of SuperSmartPointer to a void*

protected:
    T* mPtr;
    static std::map<T*, int> sRefCountMap;
    void finalizePointer();
    void initPointer(T* inPtr);
};


template <typename T>
std::map<T*, int> SuperSmartPointer<T>::sRefCountMap;


// c-tor
template<typename T>
SuperSmartPointer<T>::SuperSmartPointer(T* inPtr)
{
    initPointer(inPtr);
}

template<typename T>
SuperSmartPointer<T>::SuperSmartPointer(const SuperSmartPointer<T>& src)
{
    initPointer(src.m_Ptr);
}

template<typename T>
SuperSmartPointer<T>& SuperSmartPointer<T>::operator=(const SuperSmartPointer<T>& rhs)
{
    if(this == &rhs)
        return *this;

    finalizePointer();
    initPointer(rhs.m_Ptr);
    return *this;
}

template<typename T>
SuperSmartPointer<T>::~SuperSmartPointer()
{
    finalizePointer();
}

template<typename T>
void SuperSmartPointer<T>::initPointer(T* inPtr)
{
    mPtr = inPtr;
    if(sRefCountMap.find(mPtr) == sRefCountMap.end()) {
        sRefCountMap[mPtr] = 1;
    }
    else
    {
        sRefCountMap[mPtr]++;
    }
}

template<typename T>
void SuperSmartPointer<T>::finalizePointer()
{
    if(sRefCountMap.find(mPtr) == sRefCountMap.end())
    {
        throw std::runtime_error("Error missing entry in map!");
    }
    sRefCountMap[mPtr]--;
    if(sRefCountMap[mPtr] == 0)
    {
        sRefCountMap.erase(mPtr);
        delete mPtr;
        mPtr = nullptr;
    }
}

template<typename T>
const T* SuperSmartPointer<T>::operator->() const
{
    return mPtr;
}

template<typename T>
T* SuperSmartPointer<T>::operator->()
{
    return mPtr;
}

template<typename T>
const T& SuperSmartPointer<T>::operator*() const
{
    return *mPtr;
}

template<typename T>
T& SuperSmartPointer<T>::operator*()
{
    return *mPtr;
}








#endif





















