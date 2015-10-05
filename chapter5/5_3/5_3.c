#include <stdio.h>
#include <stdlib.h>

#include "5_3.h"

int getBigger(int inputNumber)
{
	int c  = inputNumber;
	int c1 = 0;		//c1 is for count 1s
	int c0 = 0;		//c2 is for count 0s


	while( (c & 1) == 0 && (c != 0) )
	{
		c0++;
		c >>= 1;
	}

	while( (c & 1) == 1)
	{
		c1++;
		c >>= 1;
	} 

	printf("c0 is %d, and c1 is %d\n", c0, c1);

	if( (c0 + c1) == 31 || (c0 + c1 == 0) )
	{
		return -1;
	}
	//If c is 7fff0000 or numbers like 7f000000, then c0 + c1 = 31.
	//If c is 0, then c0 + c1 = 0;

	int p = c0 + c1;

	inputNumber |= (1 << p);

	inputNumber &=	~((1 << p) - 1);

	inputNumber |= (1 << (c1 - 1)) - 1;

	return inputNumber;
}

/* 	Get a smaller one 
	@argument int inputNumber
	@argument int smallerNumber
*/
int getSmaller(int inputNumber)
{
	int c = inputNumber;
	int cTemp = inputNumber;

	int c0 = 0;
	int c1 = 0; 

	while( (c & 1) == 1)
	{
		c1++;
		c >>= 1;
	}

	while( (c & 1) == 0 && (c != 0))
	{
		c0++;
		c >>= 1;
	}


	if( ( (c1 + c0) == 31 ) && ( (cTemp & 1) == 1 ) )
	{
		return -1;
	}

	if( (c1 + c0) == 0 )
	{
		return -1;
	}

	int p = c1 + c0;  	// Set p to 0;

	//Clear p through to 0 
	c &= ( ~ ( ( 1 << ( p + 1 ) ) - 1 ) );

	printf("c = %04x\n, c0 = %d, c1 = %d, p = %d\n", c, c0, c1, p);

	int mask = ( (1<<p) - 1 ) & ( ~ ( ( 1 << ( c0 - 1 ) ) - 1 ) );
	int a = (1 << p) - 1;
	int b = ~ ((1 << (c0 - 1)) - 1);

	printf("*1 = %04x, *2 = %04x\n", a, b);
	
	c |= mask;

	printf("Mask: %04x\n", mask);

	return c;
}
