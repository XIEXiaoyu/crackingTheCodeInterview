#include <stdio.h>
#include <string.h>

void reverse(char* str) {
	int len = strlen(str);
	int i = 0;
	char k = 0;
	int half = len / 2;

	for(i = 0; i < half; i++) { 
		k = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = k;
	}
}

int main(void) {
	char str[] = "I will always love you.";
	reverse(str);
	printf("%s\n", str);

	return 0;
}