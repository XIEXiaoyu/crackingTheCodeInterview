#include <stdio.h>
#include <stdbool.h>

#include "5_5_1.h"

int getBit(int number)
{
	if( (number & 1) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool isSame(int bit1, int bit2)
{
	if( (bit1 ^ bit2) == 1 )
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int getBits(int number1, int number2)
{
	int bit1 = 0;
	int bit2 = 0;
	int bits = 0;

	while( ( number1 != 0 ) || ( number2 != 0 ) )
	{
		bit1 = getBit(number1);
		bit2 = getBit(number2);

		if( true == isSame(bit1, bit2) )
		{
			bits++;
		}
		number1 >>= 1;
		number2 >>= 1;
	}

	return bits;
}