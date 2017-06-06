#include <iostream>
#include <thread>

void doSth()
{
	std::cout << "Do sth thread\n";
}

class A
{
public:
	void operator() () const
	{
		std::cout << "Thread from class\n";
	}
};


int main()
{
	A a1;
	std::thread t1(a1); 

	std::thread t2( (A()) );

	std::thread t3{ A() };

	t1.join();
	t2.join();
	t3.join();
}