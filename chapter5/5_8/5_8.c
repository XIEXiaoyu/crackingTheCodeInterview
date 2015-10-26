#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "5_8.h"

char* createCharArr(int w, int h)
{
	int len = w * h;
	char* arr = (char*)malloc(sizeof(char) * len);
	memset(arr, 0, len);
	return arr;
}

int getIndex(int x, int y)
{
	//rbf
	printf("index is %d\n", WIDTH * y + x);
	//

	return WIDTH * y + x;
}

bool isSameByte(int x1, int x2)
{
	if( (x2 - x1) < 8 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void setBytesBright(char* arr, int index1, int index2)
{
	for(int i = 1; i < (index2 - index1); i++)
	{
		arr[index1 + i] = ~arr[index1 + i];

		//	remove before flight
		//	printf("%02x\n", arr[index1 + i] & 0xFF);
		//
	}	
}

void setWithinByte(char* arr, int x1, int x2)
{
	int index = x1 / 8;
	int starting = x1 % 8;
	int ending = x2 % 8;
	//rbf
	printf("starting is %d\n", starting);
	printf("ending is %d\n", ending);
	//

	char left = ~0;
	left <<= (8 - starting);
	//rbf
	printf("left is %02x\n", left & 0xFF);
	//

	char right = 1 << (8 - ending - 1);
	right -= 1;
	//rbf
	printf("right is %02x\n", right &0xFF);
	//

	arr[index] = ~(left | right); 

	//	remove before flight
	printf("%2x\n", arr[index] & 0xFF);
	//
}

void setStart(char* arr, int x1)
{
	int index = x1 / 8;
	//rbf
	printf("start index is %d\n", index);
	//
	int starting = x1 % 8;
	arr[index] = (1 << (8 - starting)) - 1;

	//rbf
	printf("%02x\n", arr[index] & 0xFF);
	//
}

void setEnd(char* arr, int x2)
{
	int index = x2 / 8;
	//rbf
	printf("end index is %d\n", index);
	//
	int ending = x2 % 8;
	arr[index] = ((~0) << (8 - ending - 1));

	//rbf
	printf("%02x\n", arr[index] & 0xFF);
	//
}

void drawHorizontalLine(char* arr, int x1, int x2, int y)
{
	int indexX1 = getIndex(x1, y);
	int indexX2 = getIndex(x2, y);

	bool sameByte = isSameByte(indexX1, indexX2);
	if(sameByte == true)
	{
		setWithinByte(arr, indexX1, indexX2);
		//rbf
		printf("within bytes\n");
		//
	}
	else
	{
		int index1 = indexX1 / 8;
		int index2 = indexX2 / 8;
		if(indexX2 - indexX1 < 15)
		{
			//rbf
			printf("nearby bytes\n");
			//
			setStart(arr, indexX1);
			setEnd(arr, indexX2);
		}
		else
		{
			//rbf
			printf("include at least a full byte\n");
			//	
			setStart(arr, indexX1);			
			setBytesBright(arr, index1, index2);
			setEnd(arr, indexX2);
		}		
	}
}

// print the monochrome screen on the terminal screen
// @param 	char* 	arr
// @return 	void
void printScreen(char* arr)
{
	for(int i = 0; i < HEIGHT / 8; i++)
	{
		for(int j = 0; j < WIDTH / 8; j++)
		{
			printf("%02x ", arr[i * (WIDTH / 8) + j] & 0xFF);
		}
		printf("\n");
	}
}