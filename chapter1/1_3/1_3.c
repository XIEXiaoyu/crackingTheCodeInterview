#include <stdio.h>
#include <string.h>

int main(void) {
	//思路
	//第一步：A字符串和B字符串的字符数目必须相等.
	//第二步：查看A字符串中的每一种字符（区分大小写，并且包含空格字符、逗号句号
	//       等各种符号）在A中的数量，然后看在B字符串
	//       当中是否也有相同的数目。
	//第三步：如果A字符串中所有种类的字符都能满足第二步，那么A字符串的字符调整顺序
	//       之后，就能和B字符串一样。

	char strA[] = "illla";
	char strB[] = "llill";
	int strRecordA[96];
	int strRecordB[96];
	memset(strRecordA, 0, sizeof(int) * 96);
	memset(strRecordB, 0, sizeof(int) * 96);

	int lenA = strlen(strA);
	int lenB = strlen(strB);

	if(lenA != lenB) {
		printf("String A can't be transformed into string B.\n");
		return 0;
	}

	int i = 0, A = 0, B = 0;
	for(i = 0; i < lenA; i++) {
		A = strA[i] - 31;
		strRecordA[A]++;
		B = strB[i] - 31;
		strRecordB[B]++;
	}

	for(i = 0; i < 96; i++) {
		if(strRecordA[i] != strRecordB[i]) {
			printf("String A can't be transformed into string B.\n");
			return 0;
		}
	}

	printf("String A can be transformed into string B.\n");
	return 0;
}