/*str1 = "Sun is out today"
str2 = "soiyt"

Remove all chars in str2 from str1

str1 = "un u da"
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define CHARS 256

int remove_s(char str1[], char str2[]) {

	if(str1== NULL) {
		return -1;		
	}
	if(str2 == NULL) {
		printf("%s", str1);
		return 0;
	}

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	if(len1 == 0) {
		return -1;
	}
	if(len2 == 0) {
		printf("%s", str1);
		return 0;
	}
	bool hit[CHARS];
	
	for(int i=0; i<CHARS; i++) {
		hit[i] = false;
	}
	
	for(int i=0; i<len2; i++) {
		hit[str2[i]] = true;
		if(str2[i] >='a' && str2[i] <= 'z') {
			int index = str2[i] - 'a';
			hit['A' + index] = true;
		}

		if(str2[i] >='A' && str2[i] <= 'Z') {
			int index = str2[i] - 'A';
			hit['a' + index] = true;
		}
	}
	
	int end = 0;
	for(int i=0; i<len1; i++) {
		if(hit[str1[i]] == false) {
			str1[end] = str1[i];
			end++;
		}
	}
	str1[end] = '\0';
	printf("%s", str1);
	return 0;
}

void main() {
	char str1[] = "Sun is out today";
	char str2[] = "soiyt";
	remove_s(str1, str2);
}

