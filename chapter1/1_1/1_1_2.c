//cracking the code interview question 1.1
//第二种方法
//方法：
//    1.创造一个数组A，数组A的长度能够包含所有可能的字符,这个数组的每一个
//      元素的初始值设为0。
//    2.然后逐一看目标数组B的每一个字符。例如，如果数组B的第一个字符是'a', 
//      那么就在数组A的'a'的位置，把初始值0变成1，如果在B中又出现一个'a',
//      那么就把1再变成2。
//    3.遍历数组A的元素之后，看数组B。只要任何一个元素的值是大于1的，则说明
//      这个元素出现了1次以上。
#include <stdio.h>
#include <string.h> // for memset()

int main(void) {
	int i = 0;

	//下面7行代码没有什么卵用，纯为了练习如何把一个sting的所有元素给同样的字符,
	//并且练习用'\060',表示字符0。\是转义字符，0代表8进制，60是8进制的数，换成
	//10进制是48，48在ASCII表里面字符0。
	// char allChar[96];
	// for(i = 0; i < 96; i++) {
	// 	allChar[i] = '\060'; //127-32+1=96
	// }
	// for(int i = 0; i < 96; i++) {
	// 	printf("%c\n", allChar[i]);
	// }

	// int allCharRecord[96];
	// memset(allCharRecord, 0, sizeof(int) * 4); 
	//用memeset()初始化一个一维数组 http://c.biancheng.net/cpp/html/157.html
	//http://www.tutorialspoint.com/c_standard_library/c_function_memset.htm
	//0会转化成NULL存到每一个字节里面去。
	//所以一个int,包含4个字节，4个字节全部是NULL，那么整个int还是NULL。
	//如果代码是
	// int allCharRecord[96];
	// memeset(allCharRecord, 48, sizeof(int) * 4); 
	//那么一个48会转化成00110000存到每一个字节里，那么
	//一个int，四个字节就会变成00110000 00110000 00110000 00110000，
	//这样打印这个四字节的int的时候，%d就会打印出808464432。是
	//2的4次，5次，12次，13次，20次，21次，28次，29次方的和。
 
	int allCharRecord[96];
	int index = 0;

	memset(allCharRecord, 0, sizeof(int) * 96);
	for(i = 0; i < 96; i++) {
		printf("%d\n", allCharRecord[i]);
	}

	int len = 0;
	char str[] = "Iwilbea.";
	//char str[] = "IHamafiHneOK.OKOK" ;
	//"I am a good girl, and I don't want to be annoyed."
	len = strlen(str);
	for(i = 0; i < len; i++) {
		index = str[i] - ' ';
		allCharRecord[index]++;
	}

	int repeat = 0; 
	for(i = 0; i < 96; i++) {
		repeat = allCharRecord[i] - 1;
		if(repeat > 0) {
			char repeatedChar = i+32;
			printf("The character %c is found repeated.\n", repeatedChar);
			return 0;
		}
	}

	printf("No repeated character appeared.\n");

	return 0;
}