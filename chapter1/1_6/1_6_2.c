//在不新开数组的条件下，完成本题。
//方法：先左右对称翻转，然后在沿着／方向的对角线翻转
#include <stdio.h>
#define N 5

void array2DLeftRightTurnOver(int array[][5], int n){  //
	int i = 0, j = 0, k = 0;
	int half = n / 2;
	printf("2. Half is %d\n", half);

	for(i = 0; i < n; i++) {
		for(j = 0; j < half; j++) {
			k = array[i][j];
			array[i][j] = array[i][n-1-j];
			array[i][n-1-j]  = k;
		}
	}		
}

void array2DDiagonalTurnOver(int array[][5], int n) {   //
	int i = 0, j = 0, k = 0;
	for(i = 0; i < n-1; i++) {
		for(j = 0; j < n-1-i; j++) {
			k = array[i][j];
			array[i][j] = array[n-1-j][n-1-i];
			array[n-1-j][n-1-i] = k;
		}
	}
}



int main() {
	int i = 0, j = 0, k = 0;
	int array2D[N][N] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{-1, -2, -3, -4, -5},
		{-6, -7, -8, -9, -10},
		{11, 12, 13, 14, 15}
	};
	printf("1. The original array is :\n");
	for(i = 0; i < N; i++) {
		for( j = 0; j < N; j++) {
			printf("%4d,", array2D[i][j]);
		}
		printf("\n");
	}

	printf("3. The new array is: \n");
	array2DLeftRightTurnOver(array2D, N);
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("%4d,",array2D[i][j]);
		}
		printf("\n");
	}

	printf("4. The final array is: \n");
	array2DDiagonalTurnOver(array2D, N);
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("%4d,",array2D[i][j]);
		}
		printf("\n");
	}		

	return 0;
}