#include <stdio.h>
#include <string.h>

int main() {
	char* s1 = "Iamagoodgirl";
	char* s2 = "goodgirlIama";
	int lenS1 = strlen(s1);
	int lenS2 = strlen(s2);
	printf("1. The length of the string is %d\n", lenS1);

	if(lenS1 != lenS2) {
		printf("2. s2 is not rotated from s1.\n");
		return 0;
	} else {
		char s1s1[2*lenS1+1];

		memset(s1s1, '#', 2*lenS1);
		memset(s1s1+2*lenS1, '\0', 1);
		printf("3. s1s1 is set to #\n");
		printf("%s\n", s1s1);

		strcpy(s1s1, s1);
		printf("4. The s1sa sting is the same as s1:\n");
		printf("%s\n", s1s1);
		strcat(s1s1,s2);
		printf("5. The s1s1 sting is %s\n", s1s1);

		if (isSubString(s1s1, s2)) {
			printf("6. The s2 is coming from the rotated s1.\n");
		}
		else printf("7. The s2 is not from the rotated s1.\n");
	}
	
	return 0;
}