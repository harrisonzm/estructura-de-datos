#pragma once
#include "DSA/DoubleLinkedList.hpp"
#include "classes for labs/headers/Empleado.hpp"
#include "classes for labs/headers/Usuario.hpp"
#include <vector>

namespace sort
{
	std::vector<int> bubble(std::vector<int>);
	std::vector<int> insertion(std::vector<int>);
	std::vector<int> merge(std::vector<int>, std::vector<int> );
	std::vector<int> mergeSort(std::vector<int>);
	NodoDoble<Empleado>* getMiddle(DoubleLinkedList<Empleado>*, size_t);
	DoubleLinkedList<Empleado>* mergeList(DoubleLinkedList<Empleado>*, DoubleLinkedList<Empleado>*);
	DoubleLinkedList<Empleado>* mergeSortList(DoubleLinkedList<Empleado>*);
};

