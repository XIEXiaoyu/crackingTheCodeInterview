#include <stdio.h>

#include "5_5_2.h"

int getBits1(int in1, int in2)
{
	int c;
	int count = 0;
	for(c = in1 ^ in2; c !=0; c >>=1)
	{
		count+= c & 1;
	}

	return count;
}

int getBits2(int in1, int in2)
{
	int c = 0;
	int count = 0;
	for(c = in1 ^ in2; c != 0; c &= (c - 1))
	{
		count++;
	}
	return count;
}