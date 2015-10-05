#include <stdio.h>
#include <stdbool.h>

#include "5_4.h"

int main() 
{
	int number1 = 0x33;
	int number2 = 0x47;

	printf("%d\n", getBits(number1, number2));

	return 0;
}