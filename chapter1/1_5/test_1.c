#include <stdio.h>
#include <stdlib.h>
int main()
{
	int number = 123456;
	char string[25];
	sprintf(string,"%d", number);
	printf("integer = %d string = %s\n", number, string);
	printf("%c\n", string[2]);
	return 0;

}
 // sprintf(s, "%d", 123);  //把整数123打印成一个字符串保存在s中