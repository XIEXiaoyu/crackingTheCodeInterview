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

	int count0 = 0;
	int count1 = 0;
	int misBit = getMisBit(arr, length, index, &count0, &count1);
	
	if( count0 == 0 && count1 == 0)
	{
		insertBit(0, index, missNum);
	}
	else
	{
		insertBit(misBit, index, missNum);
		int leftArray[length];
		int leftArrayLength = discardNums(arr, length, misBit, index, leftArray);
		int result[leftArrayLength];
		getRealLeft(leftArray, leftArrayLength, result);
		index++;
		getMissNumEntry(result, leftArrayLength, index, missNum);
	}
}