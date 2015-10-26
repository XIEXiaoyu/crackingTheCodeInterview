#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "5_8.h"

int main()
{
	int w = WIDTH/8;
	int h = HEIGHT/8;
	int length = w * h;
	printf("length is %d\n", length);
	char* arr = createCharArr(w, h);

	//int x1 = 1, x2 = 9, y = 1;

	//int x1 = 1, x2 = 7, y = 1;

	int x1 = 1, x2 = 16, y = 0;

	drawHorizontalLine(arr, x1, x2, y);

	printScreen(arr);

	printScreenInBits(arr);

	return 0;
}