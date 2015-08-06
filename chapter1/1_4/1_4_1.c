//本题目解法：声明一个很大的字符串，比如有100个元素，
//可以发现，每将一个空格替换成％20，每个空格后面的字符在原来数组中的下表要增加。
//可以发现下标增加的规律是，1)
//第一个空格和第二个空格之间的字符的下标全部加2，3*1-1
//第二个空格和第三个空格之间的字符的下标增加3*2-2，
//第三个空格和第四个空格之间的字符的下标增加3*3-3,以此类推，
//第四个空格和第五个空格之间的字符的下标增加3*4-4,那么
//第n个空格之后的字符的下标增加3*n-n。
//2）空格的替换符号％20的％的出现位置为空白字符在原来数组中的位置下标加上
//n*2（n从0开始）。所以如果在原来的数组中，出现的2，7，13那么在新数组中
//的下标就是2+0*2，还是2； 7+1*2, 变成9； 13+2*2， 变成17。
//所以我们要知道空格出现的位置，也就是说要记录每个空格是所有空格当中的第几个，而且
//还要知道每个字符是在哪个空格之后，这样才能给每个字符的下标给相应的增加的数量。
#include <stdio.h>
#include <string.h>
#define LongStrLength 100

int main() {
	char strOrigin[] = "Mr John Smith and Mr Duan and Mrs Xie.";
	int len = strlen(strOrigin);
	int i = 0, j = 0;
	printf("1.The length of the Sting is %d\n", len); //

	int blankIndexRecord[len];
	memset(blankIndexRecord, 0, sizeof(int) * len);
	printf("2.Set the blankIndexRecord array to all 0s\n"); //
	for(i = 0; i < len; i++) { 
		printf("%d",blankIndexRecord[i]);
	}
	printf("\n");
	
	for(i = 0; i < len; i++){
		if(strOrigin[i] == ' '){
			blankIndexRecord[j] = i;
			j++;
		}
	}
	int numberOfBlanks = j;

	printf("3.The blank in the String are at index: ");
	for(j = 0; j < numberOfBlanks; j++) {  //
		printf("%d,", blankIndexRecord[j]);
	}
	printf("\n");

	printf("4.There are %d blanks.\n", numberOfBlanks); //

	char strLongEnough[LongStrLength];
	memset(strLongEnough,' ',LongStrLength-1);
	strLongEnough[LongStrLength-1] = '\0';    //重点//
	printf("5.Set the longString all to blanks as: %s\n", strLongEnough);
	for(i = 0; i < blankIndexRecord[0]; i++) {
		strLongEnough[i] = strOrigin[i];
	}
	printf("6.The characters before the first blanks are: %s\n", strLongEnough); //

	int indexStart = 0;
	for(i = 0; i < numberOfBlanks; i++){
		indexStart = blankIndexRecord[i] + i * 2;
		strLongEnough[indexStart] = '%';
		strLongEnough[indexStart+1] = '2';
		strLongEnough[indexStart+2] = '0';
		printf("7.i is %d, index is %d, %c %c %c\n", i, blankIndexRecord[i],
			strLongEnough[indexStart],
			strLongEnough[indexStart+1],
			strLongEnough[indexStart+2]);
	}
	printf("%s\n", strLongEnough);

	for(i = 0; i < numberOfBlanks - 1; i++){
		for(j = blankIndexRecord[i]+1; j < blankIndexRecord[i+1]; j++) {
			strLongEnough[j+(i+1)*2] = strOrigin[j];
		}
	}
	printf("8.The longString except characters after the last space is %s.\n", strLongEnough);

	int index4LastSpace = blankIndexRecord[numberOfBlanks-1] + 1;
	printf("9.The index of the character after the last space is %d\n", index4LastSpace);

	int index4LastSpaceInLongStr = blankIndexRecord[numberOfBlanks-1] + (numberOfBlanks-1)*2 + 3;
	printf("10.The index of the character for the last character in the long string is %d\n", index4LastSpaceInLongStr);

	int leftCharacters = len - index4LastSpace;
	printf("11.Left characters are %d\n", leftCharacters);

	for(j = 0; j < leftCharacters; j++) {
		strLongEnough[index4LastSpaceInLongStr+j] = strOrigin[index4LastSpace+j];
	}
	printf("12.The final String is %s\n", strLongEnough);
	return 0;
}
