#pragma once
#include "DSA/SingleLinkedList.hpp"

template<class T>
struct TreeNode {
	TreeNode<T> parent = nullptr;
	SingleLinkedList<TreeNode<T>*> children = SingleLinkedList<TreeNode<T>*>();
};



template<class T>
class Tree {
public:
	virtual bool isParent(const TreeNode<T>* const Parent, const TreeNode<T>* const Child);
	virtual bool isAncestor(const TreeNode<T>* const Ancstr, TreeNode<T>* const node);
	virtual bool isBrother(TreeNode<T>* brthr, TreeNode<T>* node);
	virtual bool ischild(TreeNode<T>* child, TreeNode<T>* Parent);
	virtual bool isExternal(TreeNode<T>* node);

	virtual TreeNode<T> Parent(TreeNode<T>* node);


	virtual int  depth(TreeNode<T>* node);	
	virtual int height(TreeNode<T>* node);

private:
	TreeNode<T>* root = nullptr;

};

//IMPLEMENTATION

template<class T> bool Tree<T>::isParent(const TreeNode<T>* const parent, const TreeNode<T>* const child)
{
	return child->parent == parent;

}

template<class T> bool Tree<T>::isAncestor(const TreeNode<T>* const ancstr, TreeNode<T>* const node)
{	
	while (parent(node) != ancstr && parent(node) != nullptr) {
		node = parent(node);
	}

	return  parent(node) != nullptr ;

}

template<class T> bool Tree<T>::isBrother(TreeNode<T>* brothr, TreeNode<T>* node)
{
	NodoSimple<T>* curr = node->parent.children->First();
	while (curr != brothr && curr != nullptr)
	{
		curr = curr->next;
	}
	return curr != nullptr;
}

template<class T> bool Tree<T>::ischild(TreeNode<T>* child, TreeNode<T>* parent)
{
	NodoSimple<T>* curr = parent->children->First();
	while (curr != child && curr != nullptr)
	{
		curr = curr->next;
	}
	return curr != nullptr;
}

template<class T> bool Tree<T>::isExternal(TreeNode<T>* node)
{
	return node->children == nullptr;

}

template<class T> 
TreeNode<T> Tree<T>::Parent(TreeNode<T>* node)
{
	return node->parent;

}
template<class T> 
int Tree<T>::depth(TreeNode<T>* node)
{
	if (node == root) {
		return 0;
	}
	else {
		return 1 + depth(parent(node));
	}


}
template<class T> 
int Tree<T>:: height(TreeNode<T>* node)
{
	if ( isExternal(node)) {
		return 0;

	}
	else {
		int maxHeight = 0;
		NodoSimple<T>* const child = node->children;
		while (child->next != nullptr)
		{
			maxHeight = max(maxHeight, height(child->value));
		}
		return 1 + maxHeight;
	}

}