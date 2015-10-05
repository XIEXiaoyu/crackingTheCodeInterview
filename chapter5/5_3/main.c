#include <stdio.h>
#include <stdlib.h>

#include "5_3.h"

int main()
{
	int inputNumber = 0x98;

	int  biggerNumber = getBigger(inputNumber);

	printf("bigger is %04x\n", biggerNumber);

	int inputNumber2 = 0x02;

	int smallerNumber = getSmaller(inputNumber2);

	printf("smaller is %04x\n", smallerNumber);


	return 0;
}