#include <stdio.h>
#define N 5

int main() {
	int array2D[N][N] = {
		{1, 2, 0, 4, 0},
		{6, 7, 4, 9, 10},
		{1, 0, 3, 4, 5},
		{2, 3, 4, 5, 6},
		{3, 4, 5, 6, 8}
	};

	printf("1. The original array is: \n");
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%4d,", array2D[i][j]);
		}
		printf("\n");
	}

	int arrayRow[N], arrayCol[N];
	for(int i = 0; i < N; i++) {
		arrayRow[i] = -1;
		arrayCol[i] = -1;
	}

	printf("2. The original arrayRow is: \n");
	for(int i = 0; i < N; i++) {
		printf("%2d ", arrayRow[i]);
	}
	printf("\n");

	printf("3. The original arrayRow is: \n");
	for(int i = 0; i < N; i++) {
		printf("%2d ", arrayCol[i]);
	}
	printf("\n");

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(array2D[i][j] == 0) {
				arrayRow[i] = 0;
				printf("2. arrayRow is: \n");
				for(int k = 0; k < N; k++) {
					printf("%2d ", arrayRow[k]);
				}
				printf("\n");

				arrayCol[j] = 0;
				printf("3. arrayCol is: \n");
				for(int k = 0; k < N; k++) {
					printf("%2d ", arrayCol[k]);
				}
				printf("\n");
			}
		}
	}

	for(int i = 0; i < N; i++) {
		if(arrayRow[i] == 0){
			for(int j = 0; j < N; j++){
				array2D[i][j] = 0;		
			}
			printf("4. Row clear is: \n");
			for(int k = 0; k < N; k++) {
				for(int l = 0; l < N; l++) {
					printf("%d ", array2D[k][l]);
				}
				printf("\n");
			}	
		}
	}

	for(int i = 0; i < N; i++) {
		if(arrayCol[i] == 0){
			for(int j = 0; j < N; j++){
				array2D[j][i] = 0;
			}
			printf("5. Col clear is: \n");
			for(int k = 0; k < N; k++) {
				for(int l = 0; l < N; l++) {
					printf("%d ", array2D[k][l]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}

