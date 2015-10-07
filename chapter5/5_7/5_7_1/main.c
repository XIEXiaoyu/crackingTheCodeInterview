#include <stdio.h>

#include "5_7_1.h"

int main()
{
	int arr[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 14, 12, 11, 10};  // missing number is 3

	int missNum = 0;

	getMissNumEntry(arr, MAX, 0, &missNum);

	printf("missNum: %04x\n", missNum);

	return 0;
}