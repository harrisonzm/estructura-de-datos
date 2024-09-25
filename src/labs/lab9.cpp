#include "labs/headers/lab9.hpp"
#include <DSA/HashTable.hpp>
#include <classes for labs/headers/Usuario.hpp>
#include <cmath>

void lab9::puntoA()
{
	hashTable<int, int> tableD = *(new hashTable<int,int>(10,'D'));
	int count = 0;
	int inserted[40];
	while (count < 20) {
		int temp = (std::rand()*(count+1)) % 100;
		inserted[count] = temp;
		int* num = new int(temp);
		tableD.insert(temp, num);
	}

	//int*  tempDel = tableD[inserted[5]];
	//tableD.deleteFrom(5);
	hashTable<int, int> tableM = *(new hashTable<int, int>(10,'M'));
	
	while (count < 40) {
		int temp = (std::rand() * (count + 1)) % 100;
		inserted[count] = temp;
		int* num = new int(temp);
		tableM.insert(temp, num);
	}
	//int* tempDel = tableM[inserted[15]];
	//tableM.deleteFrom(15);
	std::cout << "table multiplication-----------------------" << "\n";
	tableM.toPrint();
	std::cout << "table division-----------------------" << "\n";
	tableD.toPrint();

}
void lab9::puntoB()
{
	hashTable<int, Usuario> tableD = *(new hashTable<int, Usuario>(5, 'D'));
	hashTable<int, Usuario> tableM = *(new hashTable<int, Usuario>(5, 'M'));

	Usuario* user1 = new Usuario("Juan", 10101013);
	Usuario* user2 = new Usuario("Pablo", 10001011);
	Usuario* user3 = new Usuario("Maria", 10101015);
	Usuario* user4 = new Usuario("Ana", 1010000);
	Usuario* user5 = new Usuario("Diana", 10111105);
	Usuario* user6 = new Usuario("Mateo", 10110005);
	tableD.insert(user1->getId(), user1);
	tableD.insert(user2->getId(), user2);
	tableD.insert(user3->getId(), user3);
	tableD.insert(user4->getId(), user4);
	tableD.insert(user5->getId(), user5);
	tableD.insert(user6->getId(), user6);
	Usuario* user7 = new Usuario("Juan", 10101013);
	Usuario* user8 = new Usuario("Pablo", 10001011);
	Usuario* user9 = new Usuario("Maria", 10101015);
	Usuario* user10 = new Usuario("Ana", 1010000);
	Usuario* user11 = new Usuario("Diana", 10111105);
	Usuario* user12 = new Usuario("Mateo", 10110005);
	tableM.insert(user7->getId(), user7);
	tableM.insert(user8->getId(), user8);
	tableM.insert(user9->getId(), user9);
	tableM.insert(user10->getId(), user10);
	tableM.insert(user11->getId(), user11);
	tableM.insert(user12->getId(), user12);
	std::cout << "table multiplication-----------------------"<<"\n";
	tableM.toPrint();
	std::cout << "table division-----------------------" << "\n";
	tableD.toPrint();
}