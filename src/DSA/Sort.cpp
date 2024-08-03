#include "../src/DSA/headers/sort.hpp"
#include <vector>

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
	int size1 = v1.size();
	int size2 = v2.size();
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



std::vector<int> sort::merge_sort(std::vector<int> list)
{
	if (list.size() > 1) {
		int mid = list.size() / 2;
		std::vector<int> left(list.begin(), list.begin() + mid);
		std::vector<int> right(list.begin() + mid, list.end());
		left = merge_sort(left);
		right = merge_sort(right);
		list = merge(left, right);
		
	}
	
	
	return list;
}

NodoDoble<Usuario>* sort::get_middle(DoubleLinkedList<Usuario>* list, int n){
	NodoDoble<Usuario>* curr = list->First();
	for (int i = 0; i < n / 2 - 1; i++) {
		curr = curr->next;
	}
	return curr;
}

DoubleLinkedList<Usuario>* sort::mergeList(DoubleLinkedList<Usuario>* left, DoubleLinkedList<Usuario>* right)
{
	DoubleLinkedList<Usuario>* result = new DoubleLinkedList<Usuario>();
	NodoDoble<Usuario>* l = left->First();
	NodoDoble<Usuario>* r = right->First();
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


DoubleLinkedList<Usuario>* sort::merge_sort_list(DoubleLinkedList<Usuario>* list)
{
	if (list->First()->next == nullptr) {
		return list;
	}
	NodoDoble<Usuario>* mid = get_middle(list, list->Len());
	DoubleLinkedList<Usuario>* left = new DoubleLinkedList<Usuario>();
	left->setFirst( list->First());
	left->setLast(mid);
	DoubleLinkedList<Usuario>* right = new DoubleLinkedList<Usuario>();
	right->setFirst(left->Last()->next);
	left->Last()->next = nullptr;
	right->setLast(list->Last());
	mid->next = nullptr;

	left =  merge_sort_list(left);
	right = merge_sort_list(right);
	return mergeList(left, right);
}
