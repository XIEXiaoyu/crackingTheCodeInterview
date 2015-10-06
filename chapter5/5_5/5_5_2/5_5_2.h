#include <stdio.h>

#ifndef __5_5_2_H__
#define __5_5_2_H__

/* 	Give two integers, find how many bits are different in them.
	The solution make use of right shift.

	@argument	int in1
	@argument	int in2
	@return		int bits
*/
int getBits(int in1, int in2);

/*	Give two integers, find how many bits are different in them.
	This solution makes use of c & (c - 1) can clear the least 
	significant effective bit in c.
*/
int getBits2(int in1, int in2);

#endif 
