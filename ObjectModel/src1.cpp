#include <iostream>


class A
{
public:
	A() { std::cout << "A c-tor\n";}
	~A() { std::cout << "A d-tor\n";}

	A(const A& src) { std::cout << "A copy c-tor\n";}
	A operator=(const A& rhv) { std::cout << "A asignment operator\n"; return *this;}
	//virtual void doSth() { std::cout << "A do sth\n";}
	void ciuciu() {}
	int a;
};

class B : public A
{
public:
	B(){std::cout << "B-ctor\n";}
	B(const B& src) { std::cout << "B copy c-tor\n";}
	void doSth() { std::cout << "B do sth\n";}
};


int main()
{
	//std::cout << &A::doSth << "\n";
	std::cout << &A::ciuciu << "\n";
}