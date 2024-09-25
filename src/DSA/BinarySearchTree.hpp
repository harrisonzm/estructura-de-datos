#include "DSA/BinaryTree.hpp"
#include <queue>
#include <iostream>
#include <typeinfo>
#include <cmath>

template <typename T>
struct  BTSEntry
{
private:
	int key = 0;
	T* value = nullptr;

public:
	int getKey() noexcept { return key; }
	void setKey( int k) noexcept { key = k; }
	T* getValue() noexcept { return value; }
	void setValue( T*  val) noexcept { value = val; }

	std::ostream& operator<<(std::ostream& COUT)
	{
		COUT << this->getKey();
		return COUT;
	}

	bool operator==(int& num) {
		return num == this->getKey();
	}
};




template< typename T >
class BinarySearchTree : public BinaryTree<BTSEntry<T>> 
{
public:
	BinaryNode<BTSEntry<T>>* find( int k) noexcept;
	void insert( T*  obj,  int K) noexcept;
	T* Remove(int k) noexcept;

	int height(BinaryNode<BTSEntry<T>>* node);
	int depht(BinaryNode<BTSEntry<T>>* node);
	BinaryNode<BTSEntry<T>>* maxNode( BinaryNode<BTSEntry<T>>* node) noexcept;
	BinaryNode<BTSEntry<T>>* minNode( BinaryNode<BTSEntry<T>>* node) noexcept;

	void inOrder(BinaryNode<BTSEntry<T>>* node);
	void toPrint();

protected:
	int fDepht(BinaryNode<BTSEntry<T>>* curr, BinaryNode<BTSEntry<T>>* find);
	BinaryNode<BTSEntry<T>>* search( int k,  BinaryNode<BTSEntry<T>>*  node);
	void addEntry( BinaryNode<BTSEntry<T>>* v,  BinaryNode<BTSEntry<T>>* o);

	BinaryNode<BTSEntry<T>>* predecesor(BinaryNode<BTSEntry<T>>* node) noexcept;
	
	
	void print( BinaryNode<BTSEntry<T>>* node, int level, std::queue<BTSEntry<T>*>* queu, int h);

};


//IMPLEMENTATION

template< typename T> 
BinaryNode<BTSEntry<T>>* BinarySearchTree<T>::find(int k) noexcept
{
	return search(k, this->Root());
}

template< typename T> 
BinaryNode<BTSEntry<T>>* BinarySearchTree<T>::search( int k,  BinaryNode<BTSEntry<T>>* node)
{

	if (node->getValue()->getKey() == k)
	{
		return node;
	}
	else if (k < node->getValue()->getKey())
	{
		return search(k, this->left(node));
	}
	else
	{
		return search(k, this->right(node));
	}

}

template< typename T> 
void BinarySearchTree<T>::insert( T*  obj,int k) noexcept
{	
	BTSEntry<T>* tempent = new BTSEntry<T>();
	tempent->setValue(obj);
	tempent->setKey(k);
	BinaryNode<BTSEntry<T>>* newNode = new BinaryNode<BTSEntry<T>>();
	newNode->setValue(tempent); 
	

	if (this->isEmpty())
	{
		this->addRoot(newNode);
	}
	else
	{
		addEntry(this->Root(), newNode);
		this->size++;
	}
}

template< typename T>
void BinarySearchTree<T>::addEntry(BinaryNode<BTSEntry<T>>* v, BinaryNode<BTSEntry<T>>* o)
{	
	if (o->getValue()->getKey() < v->getValue()->getKey())
	{
		if (this->hasLeft(v))
		{
			addEntry(this->left(v), o);
		}
		else 
		{
			v->setLeft(o);
		}
	}
	else 
	{
		if (this->hasRight(v))
		{
			addEntry(this->right(v), o);
		}
		else
		{
			v->setRight(o);
		}
	}
}


template<typename T>
T* BinarySearchTree<T>::Remove(int k) noexcept
{
	BinaryNode<BTSEntry<T>>* node = find(k);
	BTSEntry<T>* temp = node->getValue();
	if (this->hasLeft(node) && this->hasRight(node))
	{
		BinaryNode<BTSEntry<T>>* predecess = predecesor(node);
		node->setValue(predecess->getValue());
		predecess->setValue(nullptr);
		delete this->remove(predecess);
	}
	else
	{
		delete this->remove(node);
	}
	T* tempval = temp->getValue();
	delete temp;
	return tempval;
	
}

template< typename T>
BinaryNode<BTSEntry<T>>* BinarySearchTree<T>::predecesor( BinaryNode<BTSEntry<T>>* node) noexcept
{
	BinaryNode<BTSEntry<T>>* temp = this->left(node);
	return maxNode(temp);
}
template< typename T>
BinaryNode<BTSEntry<T>>* BinarySearchTree<T>::maxNode(  BinaryNode<BTSEntry<T>>* node) noexcept
{

	if (this->hasRight(node))
	{
		return maxNode(this->right(node));
	}
	else
	{
		return node;
	}

}


template< typename T>
BinaryNode<BTSEntry<T>>* BinarySearchTree<T>::minNode(  BinaryNode<BTSEntry<T>>* node) noexcept
{

	if (this->hasLeft(node))
	{
		return minNode(this->left(node));
	}
	else
	{
		return node;
	}

}


template< typename T>
void BinarySearchTree<T>::toPrint()
{
	std::queue<BinaryNode<BTSEntry<T>>*> q1;
	std::queue<BinaryNode<BTSEntry<T>>*> q2;
	q1.push(this->Root());
	while (!q1.empty() || !q2.empty())
	{
		while (!q1.empty())
		{
			BinaryNode<BTSEntry<T>>* temp = q1.front();
			q1.pop();
			std::cout << temp->getValue()->getKey() << " ";
			if (this->hasLeft(temp))
			{
				q2.push(this->left(temp));
			}

			if (this->hasRight(temp))
			{
				q2 .push(this->right(temp));
			}
		}
		std::cout << "\n";
		
		while (!q2.empty())
		{
			BinaryNode<BTSEntry<T>>* temp = q2.front();
			std::cout << temp->getValue()->getKey() << " ";
			if (this->hasLeft(temp))
			{
				q1.push(this->left(temp));
			}

			if (this->hasRight(temp))
			{
				q1.push(this->right(temp));
			}
			q2.pop();
		}
		std::cout << "\n";
		
	}


}


template<typename T>
void BinarySearchTree<T>::inOrder(BinaryNode<BTSEntry<T>>* node)
{

	std::cout <<  node->getValue()->getKey() << "-";
	if (this->hasLeft(node))
	{
		inOrder(this->left(node));
	}
	if(this->hasRight(node))
	{
		inOrder(this->right(node));
	}

}

template<typename T>
int BinarySearchTree<T>::depht(BinaryNode<BTSEntry<T>>* node)
{
	int val = fDepth(this->Root(), node);
	if (val > this->size)
	{
		return -1;
	}
	return val;
}

template<typename T>
int BinarySearchTree<T>::fDepht(BinaryNode<BTSEntry<T>>* curr, BinaryNode<BTSEntry<T>>* find)
{
	if (curr == find)
	{
		return 0;
	}
	else
	{
		if (find->getValue()->getKey() < curr->getValue()->getKey() && hasLeft(curr))
		{
			return 1 + fDepht(left(curr), find);
		}
		else if (find->getValue()->getKey() > curr->getValue()->getKey() && hasRight(curr))
		{
			return 1 + fDepht(right(curr), find);
		}
		else
		{
			return 1;
		}
	}
}


template<typename T>
int BinarySearchTree<T>::height(BinaryNode<BTSEntry<T>>* node)
{
	if (this->sizeT() == 0)
	{
		return 0;
	}
	else {
		if (!this->hasLeft(node) && !this->hasRight(node))
		{
			return 0;
		}
		else
		{
			int maxim = 0;
			int hL, hR = 0;
			if (this->hasLeft(node))
			{
				hL = height(this->left(node));
			}
			if (this->hasRight(node)) {
				hR = height(this->right(node));
			}

			maxim = std::max(hL, hR);
			return 1 + maxim;
		}
	}
}