#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

//using namespace std;

hash::hash()
{
	for(int i = 0; i < tableSize; i++) 
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}
}

void hash::AddItem(std::string name, std::string drink)
{
	int index = Hash(name);

	if(HashTable[index]->name == "empty")
	{
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else
	{
		item* Ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;

		while(Ptr->next != NULL) {
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}

int hash::NumberOfItemsInIndex(int index) {
	item* Ptr = HashTable[index];
	int count = 0;
	if(Ptr->name == "empty") 
	{
		return count;
	}
	else
	{	
		count++;
		while(Ptr->next != NULL) 
		{
			count++;
			Ptr = Ptr->next;
		}
		return count;
	}
}

void hash::PrintTable() 
{
	int number;
	for(int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemsInIndex(i);
		std::cout << "--------------------------" << std::endl;
		std::cout << "the index is " << i << std::endl;
		std::cout << HashTable[i]->name << std::endl;
		std::cout << HashTable[i]->drink << std::endl;
		std::cout << "# of items are " << number << std::endl;
		std::cout << "--------------------------" <<std::endl;
	}
}

void hash::PrintItemsInIndex(int index) 
{
	item* Ptr;
	Ptr = HashTable[index];
	if(Ptr->name == "empty") 
	{
		std::cout << "index = " << index << " is empty." << std::endl;
	}
	else
	{	
		std::cout << "index " << index << " contains the following items." << std::endl;
		while(Ptr != NULL) {
			std::cout << "-------------------" << std::endl;
			std::cout << Ptr->name << std::endl;
			std::cout << Ptr->drink << std::endl;
			std::cout << "-------------------" << std::endl;
			Ptr = Ptr->next;
		}
	}
}

int hash::Hash(std::string key) //hash::Hash means the Hash() function comes from the hash class
{ 
	int hash = 0;
	int index;

	for(int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
	}

	index = hash % tableSize;

	return index;
}
