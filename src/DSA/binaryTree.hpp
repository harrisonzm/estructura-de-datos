#pragma once
#include <queue>
#include <DSA/Tree.hpp>

template<typename T>
struct BinaryNode
{
private:
	T* value = nullptr ;
	BinaryNode<T>* left = nullptr;
	BinaryNode<T>* right = nullptr;

public:
	
	T* getValue() { return value; }
	void setValue(T* val) { value = val; }
	BinaryNode<T>* getLeft() { return left; }
	BinaryNode<T>* getRight() { return right; }
	void setLeft(BinaryNode<T>* val) { left = val; }
	void setRight(BinaryNode<T>* val) { right = val; }
	void nullLeft() { left = nullptr; }
	void nullRight() { right = nullptr; }
	std::ostream& operator<<(std::ostream& COUT)
	{
		COUT << this->getValue();
		return COUT;
	}
	
	
};



template<class T>
class BinaryTree 
{
public:

	//STATE
	int sizeT() noexcept;
	bool isEmpty() noexcept;
	bool isRoot( BinaryNode<T>* node) noexcept;
	bool isInternal(BinaryNode<T>* node) noexcept;
	bool hasLeft(BinaryNode<T>* node) noexcept;
	bool hasRight(BinaryNode<T>* node) noexcept;
	int depht(BinaryNode<T>*  node) noexcept;
	int height(BinaryNode<T>* node) noexcept;
	void preOrder(BinaryNode<T>*);
	void inOrder(BinaryNode<T>*);
	void posOrder(BinaryNode<T>*);

	//ACCESS
	BinaryNode<T>* Root() noexcept;
	BinaryNode<T>* left(BinaryNode<T>* node) noexcept;
	BinaryNode<T>* right( BinaryNode<T>* node) noexcept;
	BinaryNode<T>* parent(BinaryNode<T>* node) noexcept;
	

	//MODIFIERS
	void addRoot(T* element) noexcept;
	void addRoot(BinaryNode<T>* node) noexcept;
	void insertLeft(BinaryNode<T>* node, T* element) noexcept;
	void insertRight( BinaryNode<T>* node,  T* element) noexcept ;
	T* remove(BinaryNode<T>* node) noexcept;
protected:
	int size = 0;
	BinaryNode<T>* root = nullptr;	
};


//IMPLEMENTATION

template<class T>  
int BinaryTree<T>::sizeT() noexcept
{
	return this->size;
}


template<class T>
bool BinaryTree<T>::isEmpty() noexcept
{
	return this->size == 0;
}


template<class T>
bool BinaryTree<T>::isRoot(BinaryNode<T>* node) noexcept
{
	return node == root;
}


template<class T>
bool BinaryTree<T>::isInternal(BinaryNode<T>*  node) noexcept
{	
	return hasLeft(node) || hasRight(node);
}


template<class T>
bool BinaryTree<T>::hasLeft(BinaryNode<T>*  node) noexcept
{
	return left(node) != nullptr ;
}

template<class T>
bool BinaryTree<T>::hasRight(BinaryNode<T>* node) noexcept
{
	return right(node) != nullptr;
}

template<class T>
int BinaryTree<T>::depht( BinaryNode<T>*  node) noexcept
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
int BinaryTree<T>::height(BinaryNode<T>* node) noexcept
{
	if (!isInternal(node)) 
	{
		return 0;
	}
	else
	{	
		const int heightL = hasLeft(node) ? height(left(node)) : 0;
		const int heightR = hasRight(node) ? height(right(node)): 0;
		const int heghtChildren = heightL * (heightL>heightR) + heightR * (heightR > heightL);
		return 1 + heghtChildren;
	}
}


template<class T>
BinaryNode<T>* BinaryTree<T>::Root() noexcept
{
	return this->root;
}

template<class T>
BinaryNode<T>* BinaryTree<T>::left(BinaryNode<T>* node) noexcept
{
	return node->getLeft();
}

template<class T>
BinaryNode<T>* BinaryTree<T>::right(BinaryNode<T>*  node) noexcept
{
	return node->getRight();
}

template<class T>
BinaryNode<T>* BinaryTree<T>::parent(BinaryNode<T>* node) noexcept 
{
	if (isRoot(node))
	{
		return nullptr;
	}
	else
	{
		std::queue<BinaryNode<T>*> queu;
		BinaryNode<T>* temp = this->Root();
		queu.push(temp);

		while (!queu.empty() && left(temp) != node && right(temp) != node)
		{    
			temp = queu.front();
			queu.pop();
			if (hasLeft(temp))
			{
				
				queu.push(left(temp));
			}
			if (hasRight(temp))
			{
				queu.push(right(temp));
			}
		}
		return temp;
	}

}


template<class T>
void BinaryTree<T>::addRoot(T* element) noexcept
{
	root = new BinaryNode<T>();
	root->setValue(element);
	size = 1; 
}

template<class T>
void BinaryTree<T>::addRoot( BinaryNode<T>* node) noexcept
{
	root = node;
	size = 1;
}

template<class T>
void BinaryTree<T>::insertLeft(BinaryNode<T>* node, T* element) noexcept
{
	
	node->setLeft( new BinaryNode<T>());
	node->getLeft()->setValue(element);
	size++;
}



template<class T>
void BinaryTree<T>::insertRight(BinaryNode<T>* node,  T* element) noexcept
{
	node->setRight(new BinaryNode<T>());
	node->getRight()->setValue(element);
	size++;
}

template<class T>
T* BinaryTree<T>::remove(BinaryNode<T>* node) noexcept
{	
	
	BinaryNode<T>* father = parent(node);
	if (hasLeft(node) || hasRight(node))
	{
		BinaryNode<T>* child = nullptr;
		if (hasLeft(node)) {
			child = left(node);
		}
		else {
			child = right(node);
		}

		if (left(father) == node)
		{
			father->setLeft(child);
		}
		else
		{
			father->setRight(child);
		}

		node->nullLeft();
		node->nullRight();
	}
	else
	{
		father->nullLeft();
		father->nullRight();
	}
	T* tempVal = node->getValue();
	delete node;
	size--;
	return tempVal;

}

template<class T>
void BinaryTree<T>::preOrder(BinaryNode<T>* node) {
	std::cout << node->getKey() <<" - ";

	if (hasLeft(node))
	{
		preOrder(left(node));
	}
	if (hasRight(node))
	{
		preOrder(right(node));
	}
}


template<class T>
void BinaryTree<T>::inOrder(BinaryNode<T>* node)
{
	if (hasLeft(node))
	{
		inOrder(left(node));
	}
	std::cout << node->getValue() << " - ";

	if (hasRight(node))
	{
		inOrder(right(node));
	}
}
template<class T>
void BinaryTree<T>::posOrder(BinaryNode<T>* node)
{
	if (hasLeft(node))
	{
		posOrder(left(node));
	}
	if (hasRight(node))
	{
		posOrder(right(node));
	}
	std::cout << node->getValue() << " - ";
}