#include <stdio.h>

#include "5_6.h"

int main()
{
	int num = 0x69;

	printf("%08x\n", swapOnE(num));
	printf("%d\n", swapOnE(num));


	printf("----------\n");

	int num1 = 0x40090000;
	printf("%08x\n", swapOnE(num1));
	printf("%d\n", swapOnE(num1));


	return 0;
}