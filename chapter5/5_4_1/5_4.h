#include <stdio.h>
#include <stdbool.h>

#ifndef __5_4_H__
#define __5_4_H__
/* 	Given a number and get the last bit of it.
	@argument 	int nubmer
	@return		int 0 or 1
*/
int getBit(int number);

/* 	Given two bits, compare if they are not the same.
	It returns ture if argument 1 and argument 2 are not the same.
	@argument	int bit1
	@argument	int bit2
	@return 	bool true or false
*/
bool isSame(int bit1, int bit2);

/* 	Given to words, check out how many bit we need to 
	change from nubmer A to number B.
	@arguemnt 	int number1
	@argument 	int number2
	@return 	int bits
*/
int getBits(int number1, int number2);

#endif
