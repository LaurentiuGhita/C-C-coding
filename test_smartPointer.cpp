#include <iostream>
#include <memory>

class A
{
public:
    A(){ std::cout << "A c-tor \n";m_nA = 0;};
    A(int nA) : m_nA(nA) { std::cout << "A c-tor \n"; }
    ~A() { std::cout << "A-dtor \n"; }
    
    const A operator+(const int cell) const
    {
        A newCell;
        newCell.m_nA = m_nA + cell;
        return newCell;
    }

    void Print() { std::cout << m_nA << "\n";}
private:
    int m_nA;
};


int main()
{
    A *a = new A();
    std::shared_ptr<A> p1(a);
    std::shared_ptr<A> p2 = p1  ;

}