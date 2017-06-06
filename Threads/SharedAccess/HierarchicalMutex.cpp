#include "HierarchicalMutex.h"


thread_local unsigned long HierarchicalMutex::m_thisThreadHierarchyVal = HierarchicalMutex::MAX_VAL;

void HierarchicalMutex::CheckForHierarchyViolation()
{
	if(m_thisThreadHierarchyVal <= m_nHierarchyVal)
	{
		throw std::logic_error("mutex hierarchy violated");
	}
}

void HierarchicalMutex::UpdateHierarchyValue()
{
	m_nPreviousHierarchyVal = m_thisThreadHierarchyVal;
	m_thisThreadHierarchyVal = m_nHierarchyVal;
}

void HierarchicalMutex::Lock()
{
	CheckForHierarchyViolation();
	internalMutex.lock();
	UpdateHierarchyValue();
}

void HierarchicalMutex::UnLock()
{
	m_thisThreadHierarchyVal = m_nPreviousHierarchyVal;
	internalMutex.unlock();
}

bool HierarchicalMutex::TryLock()
{
	CheckForHierarchyViolation();
	if(!internalMutex.try_lock())
		return false;
	UpdateHierarchyValue();
	return true;
}


HierarchicalMutex myMutex(1000);
HierarchicalMutex myMutex2(2000);

void doSthResourceA()
{
	myMutex.Lock();
	std::cout << "Aquired A\n";
	myMutex.UnLock();
}

void doSthResourceB()
{
	myMutex2.Lock();
	std::cout << "Aquired B\n";
	myMutex2.UnLock();
}

void goodJob()
{
	myMutex2.Lock();
	myMutex.Lock();

	std::cout << "Aquired B and A\n";
	myMutex.UnLock();
	myMutex2.UnLock();
}

void badJob()
{
	myMutex.Lock();
	myMutex2.Lock();

	std::cout << "Aquired A and B\n";
	myMutex2.UnLock();
	myMutex.UnLock();
}


int main()
{

	std::thread t1(badJob);
	t1.join();

}