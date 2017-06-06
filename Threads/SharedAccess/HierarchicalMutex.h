#ifndef HIERARCHICAL_MUTEX_H
#define HIERARCHICAL_MUTEX_H

#include <iostream>
#include <mutex>
#include <thread>


class HierarchicalMutex
{
public:
	explicit HierarchicalMutex(unsigned long val) : 
			m_nHierarchyVal(val), m_nPreviousHierarchyVal(0){}

	void Lock();
	void UnLock();
	bool TryLock();

private:

	void CheckForHierarchyViolation();
	void UpdateHierarchyValue();

	std::mutex internalMutex;
	unsigned long const m_nHierarchyVal;
	unsigned long m_nPreviousHierarchyVal;

	static long const MAX_VAL = 999999;
	static thread_local unsigned long m_thisThreadHierarchyVal;
};

#endif