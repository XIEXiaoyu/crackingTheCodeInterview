#include <stdio.h>

#include "5_7_1.h"

/* 	Given a offset, get a mask whose 1 is in the position of the offset.
	For example, given a offset of 3, the mask would be 00001000.
	@argument		int offset
	@argument		int mask
*/
int createMask(int offset)
{
	return (1 << offset);
}

/*	Given a number and an index, get the bit of that index of this number.
	For example, Given an integer 5, which is 00000101.
	Given 5 and an index of 0, then we get 1; if given 5 and an index of
	1, then we get 0; if given 5 and an index of 2, then we get 1, and so on.
	@argument		int 	num
	@argument 		int 	index
	@argument 		int 	bit   // 0 or 1
*/
int getBitFromNum(int num, int index)
{
	int mask = createMask(index);

	int bit = num & mask;

	bit >>= index;

	return bit;
}

/*	Given a list of numbers, count the number of 0s and 1s under an index value
	If 0s <= 1s return 0, else if 0s > 1s, return 1;
	@argument		int* 	arr
	@argument 		int 	length    	// length of the array
	@argument 		int 	index
	@argument		int* 	store the count result of 0s
	@argument 		int*	store the count result of 1s
	@return 		int 	missingBit  // 0 or 1
*/
int getMisBit(int* arr, int length, int index, int* count0, int* count1)
{
	*count0 = 0;
	*count1 = 0;
	for(int i = 0; i < length; i++)
	{
		if(getBitFromNum(arr[i], index) == 0)
		{
			(*count0)++;
		}
		else
		{
			(*count1)++;
		}
	}
	if((*count0) <= (*count1))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/* 	Given a bit, an index and an integer, inset it the bit to the index bit of the 
	given integer.
	@argument		int 	bit  // 0 or 1
	@argument		int 	index
	@argument		int* 	num
	@return 		void
*/
void insertBit(int bit, int index, int* num)
{
	int mask = 0;

	if(bit == 1)
	{
		mask = 1 << index;
		*num = (*num) | mask;
	}
	return;
}

/*	Give an integer array, get rid of all the odd numbers or the even numbers
	that is different from the misBit.
	@argument		int* 	arr
	@argument 		int 	length			// length of the array
	@argument		int 	misBit    		// 1 for odd and 0 for even
	@argument 		int 	index			// indicates which bit we can working on 
	@argument 		int* 	left			// 'left' contains the left elements, left should have the same length of the first argument
	@return 		int 	length			// this length is the one left
*/
int discardNums(int* arr, int length, int misBit, int index, int* left)
{
	int count = 0;
	// discard all the numbers that have the different bit 
	// compared with the provied bit on the index bit
	if(misBit == 1)
	{
		for(int i = 0; i < length; i++)
		{
			if(getBitFromNum(arr[i], index) == 1)
			{				
				left[count] = arr[i];
				count++;
			}
		}
	}
	else
	{
		for(int i = 0; i < length; i++)
		{
			if(getBitFromNum(arr[i], index) == 0)
			{
				left[count] = arr[i];
				count++;
			}
		}
	}

	return count;  // means how many is left
}

/* 	Given a left int array with of implicit effective length, under the condition 
	we've already knows the real effectvie length of the left array. We copy the 
	real effecitve left numbers to an new int array.
	@argument		int* 	left
	@argument		int 	length
	@argument		int* 	result			// the new array is stored here
	@return			void
*/
void getRealLeft(int* arr, int length, int* result)
{
	for(int i = 0; i < length; i++)
	{
		result[i] = arr[i];
	}

	return;
}

/*	Given an int array consisting of 0 to n, find the missing number. 
	@argument		int* 	arr
	@argument		int 	length		// the length of the array, this lenght will be reduced gradually.
	@argument 		int 	index		// we count the 0s and 1s of each number on the bit of index
	@argument		int*	missNum 	// we fill one bit of the missing number on time
	@return 		void
*/
void getMissNumEntry(int* arr, int length, int index, int* missNum)
{
	if(index == 32)
	{
		return;
	}

	int misBit = 0;
	int count0 = 0;
	int count1 = 0;

	if(length == 0)
	{
		misBit = 0;
		insertBit(0, index, missNum);
		index++;
		getMissNumEntry(arr, 0, index, missNum);

	}
	else
	{
		misBit = getMisBit(arr, length, index, &count0, &count1);
		insertBit(misBit, index, missNum);
		int leftArray[length];
		int leftArrayLength = discardNums(arr, length, misBit, index, leftArray);
		if(leftArrayLength == 0)
		{
			index++;
			getMissNumEntry(leftArray, 0, index, missNum);
		}
		else
		{
			int result[leftArrayLength];
			getRealLeft(leftArray, leftArrayLength, result);
			index++;
			getMissNumEntry(result, leftArrayLength, index, missNum);	
		}
	}
}

/* 	A second method to discard array elements. In the previous method,
	we need to create new int array to store the elements that come to 
	the next round of computation. 
	In this method, in each round, we use a mask to discard elements. 
	For example, 3 whose bit representation is 0011, is missing.
		bit3	bit2	bit1	bit0
	0: 	0 		0 		0   	0
	1: 	0 		0 		0 		1 	
	2: 	0 		0 		1 		0
	4: 	0 		1 		0 		0 
	5: 	0 		1 		0 		1

	From 0 to 5, number 3 is misssing. In the first around, we do no need
	to discard any element to count 0s and 1s to decide 0 is missing or 1
	is missing, and we found that 1 is missing. When come to the second 
	round to decide if 0 or 1 is missing, we first need to discard all the 
	elements whose bit0 is not 1. That is, we need to discard 0, 2 and 4 and
	left with 1 and 5. Similarly, we need to discard 1 and 5 when comes to 
	compute if 0 or 1 is missing in bit2.

	We need a mask that can help us to dicard 0, 2, 4 when we compute bit 1
	and discard 0, 2 and 4 plus 1 and 5 when computing bit2. 

	To compute bit1, suppose we need to discard all the elements with bit0 of 1, 
	then we need a mask1 of 0000, and result1 = mask ^ ***1. Negate result1 is 
	***0. Clear the msb3, msb2, msb1 of the negated result1, we get 0000;
	however result2 = mask ^ ***0 = ***0. After negating result2, we got ***1, 
	after clearing msb3, msb2, msb1, we got 0001, which is nonzero. 

	Our logic is that, every time we use a mask, then we detect the same 
	condition that the ones, that **** ^ mask, then negate, then clear upper
	bits, got 0s, are the ones that should be dicarded.

	So, we proceed and need to discard more to calculate bit2. Suppose we need 
	to dicard all the elements with bit1 of 0, which means we need to discard
	all the elements whose endings are 01. According to our logic, then we need 
	a mask2 that should be ended with 01, i.e, 0001. So this time result1 = 
	mask2 ^ **01 = **11. Negate and clear the msb3 and msb2, we got 0000. 
	Only elements with endings of 01 are computed to 0000, because if it is not
	ended with 01, after xor with 01, there will be at least a 0 is generated, 
	it could be 01 , 10 or 00. There will be at least a 1 left after negation, 
	and of course, it will be not be 0 eventually.

	@argument	int* arr
	@argument 	... unfinished
*/


	

