#pragma once
#include <DSA/Queue.hpp>
#include <DSA/Tree.hpp>
template<class T>
struct BinaryNode
{
	T* value = nullptr ;
	BinaryNode<T>* left = nullptr;
	BinaryNode<T>* right = nullptr;
};


template<class T>
class BinaryTree 
{
public:

	//STATE
	int sizeT() noexcept;
	bool isEmpty() noexcept;
	bool isRoot(const BinaryNode<T>* const node) noexcept;
	bool isInternal(const BinaryNode<T>* const node) noexcept;
	bool hasLeft(const BinaryNode<T>* const node) noexcept;
	bool hasRight(const BinaryNode<T>* const node) noexcept;
	int depht(const BinaryNode<T>* const node) noexcept;
	int height(const BinaryNode<T>* const node) noexcept;

	//ACCESS
	BinaryNode<T>* left(const BinaryNode<T>* const node) noexcept;
	BinaryNode<T>* right(const BinaryNode<T>* const node) noexcept;
	BinaryNode<T>* parent(const BinaryNode<T>* const node) noexcept;
	

	//MODIFIERS
	void addRoot(const T element) noexcept;
	void insertLeft(const BinaryNode<T>* node, const T& element) noexcept;
	void insertRight(const BinaryNode<T>* node, const T& element) noexcept ;
	T& remove(const BinaryNode<T>* node) noexcept;

private:
	BinaryNode<T>* root = nullptr;	
	int size = 0;
};


//IMPLEMENTATION

template<class T>  
int BinaryTree<T>::sizeT() noexcept
{
	return size;
}


template<class T>
bool BinaryTree<T>::isEmpty() noexcept
{
	return size == 0;
}


template<class T>
bool BinaryTree<T>::isRoot(const BinaryNode<T>* const node) noexcept
{
	return node == root;
}


template<class T>
bool BinaryTree<T>::isInternal(const BinaryNode<T>* const node) noexcept
{	
	return hasLeft(node) || hasRight;
}


template<class T>
bool BinaryTree<T>::hasLeft(const BinaryNode<T>* const node) noexcept
{
	return left(node) != nullptr ;
}

template<class T>
bool BinaryTree<T>::hasRight(const BinaryNode<T>* const node) noexcept
{
	return right(node) != nullptr;
}

template<class T>
int BinaryTree<T>::depht(const BinaryNode<T>* const node) noexcept
{
	if (isRoot(node))
	{
		return 0;
	}
	else
	{
		return 1 + depht(parent(node));
	}
}

template<class T>
int BinaryTree<T>::height(const BinaryNode<T>* const node) noexcept
{
	if (!isInternal(node)) 
	{
		return 0;
	}
	else
	{	

		const int heghtChildren = fmax(height(left(node), height(right(node)));
		return 1 + heghtChildren;
	}
}

template<class T>
BinaryNode<T>* BinaryTree<T>::left(const BinaryNode<T>* const node) noexcept
{
	return node->left
}

template<class T>
BinaryNode<T>* BinaryTree<T>::right(const BinaryNode<T>* const node) noexcept
{
	return node->right;
}

template<class T>
BinaryNode<T>* BinaryTree<T>::parent(const BinaryNode<T>* const node) noexcept 
{
	if (isRoot(node))
	{
		return nullptr;
	}
	else
	{
		Queue<BinaryNode<T>*> queu;
		queu.queue(root);
		BinaryNode<T>* temp = root;

		while (!queu.isEmpty() && left(queu.peek()) != node && right(queu.peek()) != node)
		{
			temp = queu.dequeue;
			if (hasLeft(temp))
			{
				queu.enqueue(left(temp));
			}
			if (hasRight(temp))
			{
				queu.enqueue(right(temp));
			}
		}
		return temp;
	}

}


template<class T>
void BinaryTree<T>::addRoot(const T element) noexcept
{
	root = new BinaryNode<T>(element);
	size = 1; 
}

template<class T>
void BinaryTree<T>::insertLeft(const BinaryNode<T>* node, const T& element) noexcept
{
	node->left = new BinaryNode<T>(element);
	size++;
}



template<class T>
void BinaryTree<T>::insertRight(const BinaryNode<T>* node, const T& element) noexcept
{
	node->right = new BinaryNode<T>(element);
	size++;
}

template<class T>
T& BinaryTree<T>::remove(const BinaryNode<T>* node) noexcept
{	
	
	const BinaryNode<T>* father = parent(node);
	if (hasLeft(father) * (left(father) == node))
	{
		father->left = node->left;
	}
	if (hasRight(father) * (right(father) == node))
	{
		father->right = node->right;
	}
	node->left = nullptr, node->right = nullptr;
	delete node;
	size--:

}