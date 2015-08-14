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

void hash::FindDrink(std::string name)
{
	int index = Hash(name);
	bool foundName = false;
	std::string drink;

	item* Ptr = HashTable[index];
	while(Ptr != NULL)
	{	
		if(Ptr->name == name)
		{
			foundName = true;
			drink = Ptr->drink;
			break;
		}
		else
		{
			Ptr = Ptr->next;
		}
	}

	if(foundName == true)
	{
		std::cout << "Favorite drink = " << drink << std::endl;
	}
	else
	{
		std::cout << name << "'s info was not found in the Hash Table.\n";
	}
}

void hash::RemoveItem(std::string name)
{
	int index = Hash(name);

	item* delPtr;
	item* p1;
	item* p2;

	//case 0 - bucket is empty
	if(HashTable[index]->name == "emtpy" && HashTable[index]->drink =="empty")
	{
		std::cout << name << "was not found in the Hash Table\n";
	}

	//case 1 - only 1 item contained in the bucket, and match
	else if(HashTable[index]->name == name && HashTable[index]->next == NULL)
	{
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
		std::cout << name << " was removed from the Hash Table\n";
	}
	//case 2 - match is located in the first item in the bucket, but ther are more items in the bucket.
	else if(HashTable[index]->name == name)
	{
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;

		std::cout << name << " was removed from the Hash Table\n";
	}
	//case 3 - bucket contains items, but first item is not a match
	else
	{
		p2 = HashTable[index];
		p1 = p2->next;

		while(p1 != NULL && p1->name != name)
		{
			p2 = p1;
			p1 = p2->next;
		}

		//case 3.1 - no match
		if(p1 == NULL) 
		{
			std::cout << name << " was not found in the Hash Table\n";
		}
		//case 3.2 - match is found
		else
		{
			delPtr = p1;
			p1 = p1->next;
			p2->next = p1;

			delete delPtr;
			std::cout << name << " was removed from the Hash Table\n";
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
