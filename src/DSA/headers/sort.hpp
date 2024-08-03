#pragma once
#include <vector>
#include "../src/DSA/headers/DoubleLinkedList.hpp"
#include "../src/classes for labs/headers/Usuario.hpp"
class sort
{
public:
	std::vector<int> bubble(std::vector<int>);
	std::vector<int> insertion(std::vector<int>);
	std::vector<int> merge(std::vector<int>, std::vector<int> );
	std::vector<int> merge_sort(std::vector<int>);
	NodoDoble<Usuario>* get_middle(DoubleLinkedList<Usuario>*, int);
	DoubleLinkedList<Usuario>* mergeList(DoubleLinkedList<Usuario>*, DoubleLinkedList<Usuario>*);
	DoubleLinkedList<Usuario>* merge_sort_list(DoubleLinkedList<Usuario>*);
};

