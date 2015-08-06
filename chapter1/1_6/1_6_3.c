//这次是用旋转的办法，以一层为例，把一个矩阵的上边挪到右边，右边挪到底边，底边挪到左边，左边挪到上边。
/*  a b c d                5 e 1 a 
	1 2 3 4    turn into   6 f 2 6
	e f g h                7 g 3 c
	5 6 7 8                8 h 4 d
拿第4层为例， 把d->8, 8->5, 5->a, a->d, 这样只需要一个中间变量
*/

//复杂度是O(N方)；

void rotate2D(int array[][5], int n) {
	for(int layer = 0; layer < n/2; layer++) {
		int first = layer;
		int last = n - 1 - layer;
		int i = 0;
		for(i = first; i < last; i++) {
			int offset = i - first;
			int top = array[first][i]; //储存上边

			//左边－》上边
			array[first][i] = array[last-offset][first];
			//offset = 0 - 0 = 0;
			//array[0][0] = array[3-0][0]; -5 -1  5  4
			//offset = 1 - 0 = 1;		    5  6  7  8
			//array[0][1] = array[3-1][0]; -1 -2 -3 -4
			//offset = 2 - 0 = 2;		   -5 -6 -7 -8
			//array[0][2] = array[3-2][0];

			//底边－》左边
			array[last-offset][first] = array[last][last-offset];
			//offset = 0 - 0 = 0;
			//array[3][0] = array[3][3];	-5 -1  5  4 
			//offset = 1 - 0 = 1;			-6  6  7  8
			//array[2][0] = array[3][2];	-7 -2 -3  -4
			//offset = 2 - 0 = 2;			-8 -6 -7  -8
			//array[1][0] = array[3][1];

			//右边－》底边
			array[last][last-offset] = array[i][last];
			//offset = 0;
			//array[3][3] = array[0][3];     -5 -1  5  4 
			//offset = 1;					 -6  6  7  8
			//array[3][2] = array[1][3];     -7 -2 -3  -4
			//offset = 2;					 -8 -6 -7  -8
			//array[3][1] = array[2][3];

			//上边－》右边
			array[i][last] = top;

			// array[layer][i] = array[last-offset][first]; //左边的挪到上边
			// array[last-offset][first] = array[last][last-offset];//底边的挪到左边
			// array[last][last-offset] = array[i][last];//右边的挪到底边
			// array[last][last-offset] = top;//底边的挪到上边
		}
	}
}

#include <stdio.h>
#define N 5
int main() {
	int i = 0, j = 0;
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

	rotate2D(array2D, N);
	printf("2. The new array is :\n");
	for(i = 0; i < N; i++) {
		for( j = 0; j < N; j++) {
			printf("%4d,", array2D[i][j]);
		}
		printf("\n");
	}	

	return 0;
}
