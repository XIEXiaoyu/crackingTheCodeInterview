//cracking the code interview question 1.1
//第一种方法：简单粗暴的比较法。
//从这个character String的第一个字符开始，每一个字符与它后面的字符进行比较，
//是否有重复的字符。如果没有重复的，那么重复这个步骤。再从第二个字符开始，将所
//有的字符与第二个字符进行比较，如此进行下去。
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[] = "Nobady rut me is X.";
	//1. 找出这个字符串有多少个字符
	int len = strlen(str);
	//2. 检查是否所有字符全都不同，如果有相同，跳出程序并报告结果。
	printf("The string has %d characters.\n", len);
	int i = 0, j = 0, jump = 0;
	for(i = 0; i < len - 1; i++){
		if(str[i] == ' '){
			continue;
		}
		for(j = i + 1; j < len; j++){
			if(str[i] == str[j]){
				jump = 1;
				break;
			}			
		}
		if(jump == 1) {
			printf("The %dth character of %c is the same with the %dth character.\n", i+1, str[i], j+1);
			return 0;
		}
	}
	printf("All characters are not the same!\n");
}