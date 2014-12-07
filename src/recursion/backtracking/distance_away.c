/* Program to rearrange a string so that repeating characters are d sistance away

There is another solution using Heap. Please check string/DS/trie

Learning : 
1. Do not oversolve a problem. Use backtracking!!!!!!!!
*/

#include<stdio.h>
#include<string.h>	
#include<stdbool.h>
#define CHARS 256

bool checksafe(char str[], int len, int d ) {
	int index[CHARS];
	
	for(int i = 0; i < CHARS; i++) {
		index[i] = -1;
	}	
	
	index[str[0]] = 0;

	for(int i = 1; i<= len; i++){
		if(index[str[i]] != -1) {
			if(i-index[str[i]] < d) {
				return false;
			}
		}
		index[str[i]] = i;
	}
	return true;
}


void distance1_util(char str1[], char str2[], int pos, int len, int d) {
	// base case
	if(pos == len) {
		str2[len] = '\0';
		printf("%s\n",str2);
		return;
	}

	for(int i=0; i<len; i++) {
		str2[pos] =  str1[i];
		if(checksafe(str2, pos, d)) {
			distance1_util(str1, str2,  pos + 1 , len, d);
		}
	}
}

void distance1(char str1[], char str2[], int len, int d) {
	distance1_util(str1, str2,  0, len, d);
}


void main() {

	char str1[] = "aabbcc"; //  expected o/p: abcabc
	int len = strlen(str1);
	char str2[len];
	distance1(str1,str2, len, 3);
}
