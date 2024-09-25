#include "labs/headers/lab8.hpp"
#include "classes for labs/headers/Usuario.hpp"
#include  "DSA/BinarySearchTree.hpp"
#include <string>

void lab8::puntoA()
{


	BinarySearchTree< int> BST;
	int numsArr[] = { 25,15,50,10,22,35,70,4,12,18,24,31,44,66 };
	for (int i : numsArr)
	{
		int*  num = new int(i);

		BST.insert(num, *num);

	}
	std::cout << "before\n";
	BST.toPrint();

	std::cout << "insert value: 90 , key : 90 \n";
	int *i = new int(90);
	BST.insert(i, *i);
	BST.Remove(15);

	BinaryNode<BTSEntry<int>>* tempMax = BST.maxNode(BST.Root());
	std::cout << "key : " << tempMax->getValue()->getKey() << " value : " << *tempMax->getValue()->getValue() << "\n";

	BinaryNode<BTSEntry<int>>* tempMin = BST.minNode(BST.Root());
	std::cout << "key : " << tempMin->getValue()->getKey() << " value : " << *tempMin->getValue()->getValue() << "\n";
	
	std::cout << " inorder ----";
	BST.inOrder(BST.Root());
	
	BST.toPrint();

}


void lab8::puntoB()
{
	Usuario* user1 = new Usuario("Juan", 10101013);
	Usuario* user2 = new Usuario("Pablo", 10001011);
	Usuario* user3 = new Usuario("Maria", 10101015);
	Usuario* user4 = new Usuario("Ana", 1010000);
	Usuario* user5 = new Usuario("Diana", 10111105);
	Usuario* user6 = new Usuario("Mateo", 10110005);
	BinarySearchTree<Usuario> BST;

	BST.insert(user1, 7);
	BST.insert(user2,4);
	BST.insert(user3, 9);
	BST.insert(user4, 2);
	BST.insert( user5, 10);
	BST.insert(user6, 8);


	BST.toPrint();

}
