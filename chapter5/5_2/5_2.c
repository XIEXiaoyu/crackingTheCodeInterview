#include <stdio.h>
#include <string.h>

#include "5_2.h"

void printBianryOfADecimal(double number)
{
	if(number >= 1 || number <= 0)
	{
		if(number >=1)
		{
			printf("ERROR: number is larger than 1.\n");
		}
		else
		{
			printf("ERROR: number is less than 0.\n");
		}
		
		return;
	}

	int arr[MAX];
	memset(arr, 0, sizeof(int)*32);

	int index = 0;
	double r = 0;

	while(number > 0)
	{
		if(index > 31)
		{
			printf("ERROR: out of 32 bits.\n");
			return;
		}
		else
		{
			double r = number * 2;
			if(r >= 1)
			{
				arr[index] = 1;
				number = r - 1;
			}
			else
			{
				arr[index] = 0;
				number = r;
			}
			index++;			
		}
	}

	printf("0.");
	for(int i = 0; i < index; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");

	return;
}