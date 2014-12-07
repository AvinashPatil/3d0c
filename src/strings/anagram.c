/*
	Find if two strings are anagrams or not.
	
Learnings: 
	1. Always use memset(hit, 0 , 256) instead of a for loop.

*/

#include<stdio.h>
#include<string.h>


void anagram(char *str1, char *str2) {

	//printf("%s", str1);

	int uniq_chars = 0;
	int hit[256];
	memset(hit, 0 , 256);

	//process str1
	for(int i=0; i < strlen(str1); i++) {
		if(hit[str1[i]] == 0) {
			uniq_chars++;
		}
		hit[str1[i]]++; 
	}

	//process str2
	for(int i=0; i < strlen(str2); i++) {
		hit[str2[i]]--;
		if(hit[str2[i]] == 0) {
			uniq_chars--;
			if(uniq_chars == 0 && (i == strlen(str2)-1)) {
				printf("Strings are anagram");
				return;
			}
		}
	}

	printf("Strings are NOT anagram");
}


int main() {
	char * str1 = "this is string 1";
	char * str2 = "this is string 1";

	anagram(str1, str2);
}
