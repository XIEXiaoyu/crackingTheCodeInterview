#include <stdio.h>

#include "5_6.h"

int swapOnE(int num)  //swapOnE stands for swapOddAndEven
{
	return ( (num & 0xaaaaaaaa) >> 1 ) | ( (num & 0x55555555) << 1 );
}



