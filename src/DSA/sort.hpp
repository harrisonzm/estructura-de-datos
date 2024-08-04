#pragma once
#include "../src/DSA/DoubleLinkedList.hpp"
#include "../src/classes for labs/headers/Usuario.hpp"
#include <vector>

class sort
{
public:
	std::vector<int> bubble(std::vector<int>);
	std::vector<int> insertion(std::vector<int>);
	std::vector<int> merge(std::vector<int>, std::vector<int> );
	std::vector<int> mergeSort(std::vector<int>);
	NodoDoble<Usuario>* getMiddle(DoubleLinkedList<Usuario>*, size_t);
	DoubleLinkedList<Usuario>* mergeList(DoubleLinkedList<Usuario>*, DoubleLinkedList<Usuario>*);
	DoubleLinkedList<Usuario>* mergeSortList(DoubleLinkedList<Usuario>*);
};

