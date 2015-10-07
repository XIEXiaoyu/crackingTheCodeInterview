#include <stdio.h>

#ifndef __5_7_1_H__
#define __5_7_1_H__

/*	MAX is the original length of the int array
*/
#define MAX 15

/* 	Given a offset, get a mask whose 1 is in the position of the offset.
	For example, given a offset of 3, the mask would be 00001000.
	@argument		int offset
	@argument		int mask
*/
int createMask(int offset);

/*	Given a number and an index, get the bit of that index of this number.
	For example, Given an integer 5, which is 00000101.
	Given 5 and an index of 0, then we get 1; if given 5 and an index of
	1, then we get 0; if given 5 and an index of 2, then we get 1, and so on.
	@argument		int 	num
	@argument 		int 	index
	@argument 		int 	bit   // 0 or 1
*/
int getBitFromNum(int num, int index);

/*	Given a list of numbers, count the number of 0s and 1s under an index value
	If 0s <= 1s return 0, else if 0s > 1s, return 1;
	@argument		int* 	arr
	@argument 		int 	length    	// length of the array
	@argument 		int 	index
	@argument		int* 	store the count result of 0s
	@argument 		int*	store the count result of 1s
	@return 		int 	missingBit  // 0 or 1
*/
int getMisBit(int* arr, int length, int index, int* count0, int* count1);

/* 	Given a bit, an index and an integer, inset it the bit to the index bit of the 
	given integer.
	@argument		int 	bit  // 0 or 1
	@argument		int 	index
	@argument		int* 	num
	@return 		void
*/
void insertBit(int bit, int index, int* num);

/*	Give an integer array, get rid of all the odd numbers or the even numbers
	that is different from the misBit.
	@argument		int* 	arr
	@argument 		int 	length			// length of the array
	@argument		int 	misBit    		// 1 for odd and 0 for even
	@argument 		int 	index			// indicates which bit we can working on 
	@argument 		int* 	left			// 'left' contains the left elements, left should have the same length of the first argument
	@return 		int 	length			// this length is the one left
*/
int discardNums(int* arr, int length, int misBit, int index, int* left);

/* 	Given a left int array with of implicit effective length, under the condition 
	we've already knows the real effectvie length of the left array. We copy the 
	real effecitve left numbers to an new int array.
	@argument		int* 	left
	@argument		int 	length
	@argument		int* 	result			// the new array is stored here
	@return			void
*/
void getRealLeft(int* arr, int length, int* result);

/*	Given an int array consisting of 0 to n, find the missing number. 
	@argument		int* 	arr
	@argument		int 	length		// the length of the array, this lenght will be reduced gradually.
	@argument 		int 	index		// we count the 0s and 1s of each number on the bit of index
	@argument		int*	missNum 	// we fill one bit of the missing number on time
	@return 		void
*/
void getMissNumEntry(int* arr, int length, int index, int* missNum);

#endif