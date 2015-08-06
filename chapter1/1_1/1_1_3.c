//cracking the code interview question 1.1
//本题目的第三种解决办法
//让所有的字符按照ASCII码的十进制大小从小到大排序，排序之后用后面的字符减去前面
//的字符，如果出现了差为0的情况，则说明有相同大小的字符，也就是两个字符是相同的。
#include <stdio.h>
#include <string.h>

int main() {
	char strInput[] = "abcdefgg.";
	int len = strlen(strInput);
	int subtracted[len - 1];
	//利用bubble sort
	int i = 0, j = 0, k = 0;
	for(i = 0; i < len - 1; i++) {
		for(j = 0; j < len - 1 - i; j++) {
			if (strInput[j] > strInput[j+1]) {
				k = strInput[j];
				strInput[j] = strInput[j+1];
				strInput[j+1] = k;
			}
		}
	}

	//printf("%s\n", strInput);

	for(i = 0; i < len - 1; i++) {
		subtracted[i] = strInput[i+1] - strInput[i];
		if(subtracted[i] == 0) {
			printf("The string has repeated characters.\n");
			return 0;
		}
	}

	// for(i = 0; i < len -1; i++) {
	// 	printf("%d", subtracted[i]);
	// }
	// printf("\n");
	printf("The string has no repeated characters.\n");
	return 0;
}