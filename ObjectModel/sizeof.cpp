#include <iostream>

class A { int a; char* b;};
class B : public virtual A { char* c;};
class C : public virtual A {};
class D : public B, public C {};


int main()
{
	std::cout << "sizeof A = " << sizeof(A) << "\n";
	std::cout << "sizeof B = " << sizeof(B) << "\n";
	std::cout << "sizeof C = " << sizeof(C) << "\n";
	std::cout << "sizeof D = " << sizeof(D) << "\n";
} 