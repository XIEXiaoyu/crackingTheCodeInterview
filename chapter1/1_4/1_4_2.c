/*
本题的第二种解法：核心是只有一个数组。
方法是先计算出把所有的空格变成％20之后，整个数组会增加到多少，
然后从后向前把字符按照题目的要求填进这些位置里面去。
*/
#include <stdio.h>
#include <string.h>
#define strLength 100

int main() {
	char str[strLength];
	strcpy(str," ");
	printf("1.This is the original string: %s\n",str);

	int len = strlen(str);
	printf("2.The string has %d real characters.\n", len);
	int numberOfSpaces = 0, i = 0;
	for(i = 0; i < len; i++) {
		if(str[i] == ' ')
		numberOfSpaces++;
	}
	printf("3.The string has %d space characters.\n", numberOfSpaces);

	int lenOfNewStr = len + 2 * numberOfSpaces;
	printf("4.The new string has %d characters.\n", lenOfNewStr);
	str[lenOfNewStr] = '\0';

	int indexOfSpaces[numberOfSpaces], j = 0;
	for(i = 0; i < len; i++) {
		if(str[i] == ' ') {
			indexOfSpaces[j] = i;
			j++;
		}
	}
	printf("5.The indexs of the spaces in the String are:");
	for(i = 0; i < numberOfSpaces; i++) {
		printf("%d,", indexOfSpaces[i]);
	}
	printf("\n");

	int backToFrontHead = lenOfNewStr-1, numberOfNonSpaceCharacters = 0;
	for(i = numberOfSpaces-1; i >=0; i--) {
		printf("6.1 The %dth space index is %d\n", i, indexOfSpaces[i]);
		if(i == numberOfSpaces-1){
			numberOfNonSpaceCharacters = len - indexOfSpaces[i] - 1;
		}
		else{
			numberOfNonSpaceCharacters = indexOfSpaces[i+1] - indexOfSpaces[i] - 1;
		}
		
		printf("6.2 There are %d non space characters after the %dth space.\n", numberOfNonSpaceCharacters, i);
		for(j = 0; j < numberOfNonSpaceCharacters; j++) {
			str[backToFrontHead-j] = str[indexOfSpaces[i]+numberOfNonSpaceCharacters-j];
			printf("6.3 backToFrontHead-j is %d\n, indexOfSpaces[i]+numberOfNonSpaceCharacters-j is %d, and str[indexOfSpaces[i]+numberOfNonSpaceCharacters-j] is %c\n",
				backToFrontHead-j,
				indexOfSpaces[i]+numberOfNonSpaceCharacters-j, 
				str[indexOfSpaces[i]+numberOfNonSpaceCharacters-j]);
		}
		backToFrontHead = backToFrontHead - numberOfNonSpaceCharacters - 3;
		printf("6.4 The frontHead is %d\n\n\n\n\n", backToFrontHead);

		str[backToFrontHead+1] = '%';
		str[backToFrontHead+2] = '2';
		str[backToFrontHead+3] = '0';
	}
	printf("7.The new string is: %s\n", str);	

	return 0;
}