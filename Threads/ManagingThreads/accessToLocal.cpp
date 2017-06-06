#include <iostream>
#include <thread>
#include <chrono>

void doSth(int& i)
{
	int index = 0;
	while(index < i)
	{
		std::cout << std::this_thread::get_id() << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		index++;
	}
	

}

struct Func
{
	Func(int& nVar) : m_nVar(nVar) {}
	void operator() ()
	{
		for(int j = 0; j < 100; ++j)
			m_nVar++;	
	}

	int& m_nVar;
};


int main()
{
	int x = 10;

	std::thread my_thread(doSth, std::ref(x));
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	std::thread t2 = std::move(my_thread);

	t2.join();



}