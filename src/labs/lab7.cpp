#include "labs/headers/lab7.hpp"
#include "DSA/MaxHeap.hpp"
#include "DSA/PriorityQueue.hpp"
#include <cmath>
#include <iostream>


void lab7::pruebaHeap()
{
	int arr[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		arr[i] = rand() % 50;
	}
	for (int& a : arr)
	{
		std::cout << a << ",";
	}
	std::cout << "\n";
	PriorityQueue<int> pq;
	pq.build(arr);
	std::cout << pq.top()<<"\n";
	pq.print();
	std::cout << "max:" << pq.pop() <<"\n";
	pq.print();
}