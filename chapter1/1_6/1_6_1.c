//在新开数组的条件下，完成本题。
#include <stdio.h>
#define N 5

int main() {
	int array2D[N][N] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{-1, -2, -3, -4, -5},
		{-6, -7, -8, -9, -10},
		{11, 12, 13, 14, 15}
	};
	printf("1. The original array is: \n");
	int i = 0, j = 0;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("%4d,",array2D[i][j]);
		}
		printf("\n");
	}

	int array2DNew[N][N];
	for(j = N-1; j >= 0; j--) {
		for(i = 0 ; i < N; i++) {
			array2DNew[i][j] = array2D[N-1-j][i];
		}
	}
	printf("2. The new array is : \n");
	for(i = 0; i < N ; i++) {
		for(j = 0; j < N; j++) {
			printf("%4d,", array2DNew[i][j]);
		}
		printf("\n");
	}
}