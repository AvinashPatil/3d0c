#include<stdio.h>
#include<string.h>

int my_strcmp(char str1[], char str2[]) {

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	if(len1 != len2) {
		return -1; 
	}

	for(int i=0; i<len1; i++) {

		int offset;
		offset = 0;

		if(str1[i] == str2[i] ) {
			continue;
		} else if(str1[i] >= 'a' && str1[i] <= 'z') {
			// lower case str1
			offset = 'a' - 'A';

		} else if((str1[i] >= 'A' && str1[i] <= 'Z')) {
			offset = 'A' - 'a';
		}
		if(offset != 0) {
			if((str1[i] - offset) ==  str2[i]) {
				continue;
			} else {
				return str1[i] - str2[i];
			}
		}
	}
	return 0;
}



void main(){
	char str1[] = "avinash";
	char str2[] = "AvinaSH";
	printf("strcmp result is %d", my_strcmp(str1, str2));
}
