#include "DSA/Sort.hpp"
#include <vector>
#include "classes for labs/headers/Empleado.hpp"
std::vector<int> sort::insertion(std::vector<int> v)
{
	size_t n = v.size();
	for (int i = 1; i < n; i++)
	{
		int key = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > key)
		{
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
	return v;
}

std::vector<int> sort::bubble(std::vector<int> v)
{
	size_t n = v.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
	return v;
}
std::vector<int> sort::merge(std::vector<int> v1,std::vector<int> v2)
{	
	size_t size1 = v1.size();
	size_t size2 = v2.size();
	std::vector<int> result;
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < size1 && j < size2) {
		if(v1[i]<v2[j]){
		 result[k++] = v1[i++];
		}
		else {
			result[k++] = v2[j++];
		}
	}
	while (i < size1) {
		result[k++] = v1[i++];
	}
	while (j < size2) {
		result[k++] = v2[j++];
	}
	return result;
}

 

std::vector<int> sort::mergeSort(std::vector<int> list)
{
	if (list.size() > 1) {
		size_t mid = list.size() / 2;
		std::vector<int> left(list.begin(), list.begin() + mid);
		std::vector<int> right(list.begin() + mid, list.end());
		left = mergeSort(left);
		right = mergeSort(right);
		list = merge(left, right);
		
	}
	
	
	return list;
}

NodoDoble<Empleado>* sort::getMiddle(DoubleLinkedList<Empleado>* list, size_t n) {
	NodoDoble<Empleado>* curr = list->First();
	for (int i = 0; i < n / 2 - 1; i++) {
		curr = curr->next;
	}
	return curr;
}

DoubleLinkedList<Empleado>* sort::mergeList(DoubleLinkedList<Empleado>* left, DoubleLinkedList<Empleado>* right)
{
	DoubleLinkedList<Empleado>* result = new DoubleLinkedList<Empleado>();
	NodoDoble<Empleado>* l = left->First();
	NodoDoble<Empleado>* r = right->First();
	while (l != nullptr && r != nullptr) {
		if (l->value.getId() < r->value.getId()) {
			result->addLast(l->value);
			l = l->next;
		}
		else {
			result->addLast(r->value);
			r = r->next;
		}
	}
	while (l != nullptr) {
		result->addLast(l->value);
		l = l->next;
	}
	while (r != nullptr) {
		result->addLast(r->value);
		r = r->next;
	}
	return result;

}


DoubleLinkedList<Empleado>* sort::mergeSortList(DoubleLinkedList<Empleado>* list)
{
	if (list->First()->next == nullptr) {
		return list;
	}
	NodoDoble<Empleado>* mid = getMiddle(list, list->Len());
	DoubleLinkedList<Empleado>* left = new DoubleLinkedList<Empleado>();
	left->setFirst( list->First());
	left->setLast(mid);
	DoubleLinkedList<Empleado>* right = new DoubleLinkedList<Empleado>();
	right->setFirst(left->Last()->next);
	left->Last()->next = nullptr;
	right->setLast(list->Last());
	mid->next = nullptr;

	left =  mergeSortList(left);
	right = mergeSortList(right);
	return mergeList(left, right);
}
