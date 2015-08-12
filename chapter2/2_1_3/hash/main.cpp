#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

//using namespace std;

int main(int argc, char** argv) {

	hash Hashy;
	std::string name = "";


	Hashy.AddItem("Paul", "Locha");
	Hashy.AddItem("Kim", "Iced Mocha");
	Hashy.AddItem("Emma", "Strawberry Smoothy");
	Hashy.AddItem("Annie", "Hot Chocolate");
	Hashy.AddItem("Sarah", "Passion tea");
	Hashy.AddItem("Pepper", "Caramel Mocha");
	Hashy.AddItem("Mike", "Chai Tea");
	Hashy.AddItem("Steve", "Apple Cider");
	Hashy.AddItem("Bill", "Root Beer");
	Hashy.AddItem("Marie", "Skinny Latte");
	Hashy.AddItem("Susan", "Water");
	Hashy.AddItem("Joe", "Green Tea");

	while(name != "exit") 
	{
		std::cout << "search for ";
		std::cin >> name;
		if(name != "exit")
		{
			Hashy.FindDrink(name);
		}
	}


	return 0;
}