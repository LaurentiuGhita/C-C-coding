#include "Heap.h"
#include <iostream>

int main()
{

	PriorityQueue pq;
	pq.Enqueue(10);
	pq.Enqueue(11);
	pq.Enqueue(5);
	pq.Enqueue(3);
	pq.Enqueue(20);
	pq.Enqueue(2);
	pq.Enqueue(1);
	
	pq.Print();

#if 0
	Heap myHeap;

	myHeap.AddElement(6, 4);
	myHeap.AddElement(5, 4);
	myHeap.AddElement(9, 5);
	myHeap.AddElement(1, 100);
	myHeap.AddElement(2, 55);
	myHeap.AddElement(3, 1);
	myHeap.AddElement(66, 2);
	myHeap.AddElement(90, 50);
	myHeap.AddElement(7, 99);

	myHeap.DeleteMinimum();
	myHeap.Print();

	myHeap.DeleteMinimum();
	myHeap.Print();

	myHeap.DeleteMinimum();
	myHeap.Print();

	myHeap.DeleteMinimum();
	myHeap.Print();
#endif


}
