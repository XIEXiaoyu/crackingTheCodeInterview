#include <stdio.h>

#include "5_5_2.h"

int main()
{
	int in1 = 0x71;
	int in2 = 0x33;

	int count = getBits2(in1, in2);

	printf("count: %d\n", count);
}