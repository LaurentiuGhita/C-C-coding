#include <iostream>

void Foo()
{
    std::cout << "Foo called \n";    
}

void Bar()
{
    std::cout << "Bar called \n";
}

int main()
{
    void (*pF)() = &Foo;
    Foo();
    Bar();
    pF();

    std::cout << "---------------------\n";
    void (*pF2)() = pF;
    pF = &Bar;

    pF();
    pF2();

}
