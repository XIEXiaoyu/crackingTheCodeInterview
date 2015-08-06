#include <stdio.h>
#include <string.h>

#define length 50
#define transition 10

int main() {
	char str[] = "aabbcccc     &&&cccccccccccddd";
	int len = strlen(str);
	printf("1. the length of the string is %d\n", len);

	char strNew[length];
	memset(strNew, 0, length);
	printf("2. The strNew is \"%s\"\n", strNew);

	char charQuantity[transition];
	memset(charQuantity, 0, transition);

	int i = 0, j = 0, quantity = 1, postitionIndexInNewStr = 0;
	int digits = 0;
	char sample = str[0];

	for(i = 1; i < len; i++) {
		printf("3. Now i is %d\n", i);
		digits = 0;
		if(str[i] == sample || i == len-1) {
			quantity++;
			if(i == len-1) {
				strNew[postitionIndexInNewStr] = sample;
				sprintf(charQuantity, "%d", quantity);
				for(j = 0; j < transition; j++) {
					if(charQuantity[j] != '\0') digits++;
				}
				for(j = 0; j < digits; j++) {
					strNew[postitionIndexInNewStr+1+j] = charQuantity[j]; 
					printf("4. the string is %s\n", strNew);	
				}
				break;				
			}
		}
		else{
			strNew[postitionIndexInNewStr] = sample;
			sprintf(charQuantity, "%d", quantity);
			for(j = 0; j < transition; j++) {
				if(charQuantity[j] != '\0') digits++;
			}
			for(j = 0; j < digits; j++) {
				strNew[postitionIndexInNewStr+1+j] = charQuantity[j]; 
				printf("4. the string is %s\n", strNew);	
			}		
			postitionIndexInNewStr = postitionIndexInNewStr + 1 + digits;
			printf("5. postitionIndexInNewStr is %d\n", postitionIndexInNewStr);
			sample = str[i];
			quantity = 1;
		}
	}

	int lenNew = strlen(strNew);
	printf("6. The updated length of the strlen is %d\n", lenNew);

	if(lenNew == len) {
		printf("7. The new string is %s\n", str);
	}
	else{
		printf("7. The new string is %s\n", strNew);
	}

	return 0;	
}