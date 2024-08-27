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

template<typename T>
NodoDoble<T>* getMiddle(DoubleLinkedList<T>* list, size_t n) {
	NodoDoble<T>* curr = list->First();
	for (int i = 0; i < n / 2 - 1; i++) {
		curr = curr->next;
	}
	return curr;
}

template<typename T>
DoubleLinkedList<T>* mergeList(DoubleLinkedList<T>* left, DoubleLinkedList<T>* right) {
	DoubleLinkedList<T>* result = new DoubleLinkedList<T>();
	NodoDoble<T>* l = left->First();
	NodoDoble<T>* r = right->First();
	while (l != nullptr && r != nullptr) {
		if (l->value.getId() < r->value.getId()) {
			result->addLast(&(l->value));
			l = l->next;
		}
		else {
			result->addLast(&(r->value));
			r = r->next;
		}
	}
	while (l != nullptr) {
		result->addLast(&(l->value));
		l = l->next;
	}
	while (r != nullptr) {
		result->addLast(&(r->value));
		r = r->next;
	}
	return result;
}

template<typename T>
DoubleLinkedList<T>* mergeSortList(DoubleLinkedList<T>* list) {
	if (list->First() == nullptr || list->First()->next == nullptr) {
		return list;
	}
	size_t size = list->Len();
	NodoDoble<T>* mid = getMiddle(list, size);

	DoubleLinkedList<T>* left = new DoubleLinkedList<T>();
	left->setFirst(list->First());
	left->setLast(mid);
	left->setLen(size / 2);

	DoubleLinkedList<T>* right = new DoubleLinkedList<T>();
	right->setFirst(mid->next);
	if (mid->next != nullptr) mid->next->prev = nullptr;
	mid->next = nullptr;
	right->setLast(list->Last());
	right->setLen(size - size / 2);

	left = mergeSortList(left);
	right = mergeSortList(right);
	return mergeList(left, right);
}

void sort::bubbleSortList(DoubleLinkedList<Empleado>* list)
{
	for (int i = 1; i < list->Len(); i++)
	{
		NodoDoble<Empleado>* curr = list->First();
		NodoDoble<Empleado>* finder = curr;
		NodoDoble<Empleado>* minor = curr;
		while (finder->next != nullptr)
		{
			if (finder->value <= minor->value)
			{
				minor = finder;
			}
		}
		NodoDoble<Empleado>* temp1 = curr;
		NodoDoble<Empleado>* temp2 = curr;
		
		
	}
}