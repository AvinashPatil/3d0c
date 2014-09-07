/*
	KMP string matching algorithm
	Prefix which are also suffix

Examples:
For the pattern “AABAACAABAA”, lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]
For the pattern “ABCDE”, lps[] is [0, 0, 0, 0, 0]
For the pattern “AAAAA”, lps[] is [0, 1, 2, 3, 4]
For the pattern “AAABAAA”, lps[] is [0, 1, 2, 0, 1, 2, 3]
For the pattern “AAACAAAAAC”, lps[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4]
*/



#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void get_array(char pat[], int a[], int len) {
	int c = 0;
	a[0] = 0;

	for(int i=1; i<len; i++) {  // note we start from 1 here
		if(pat[i] ==  pat[c]) {
			c++;
		} else {
			c = 0;
		}
		a[i] = c;
	}
	
	/*for(int i=0; i<len; i++) {
		printf("%d ", a[i]);
	} */
}

bool kmp(char text[], char pat[], int a[]) {
	
	for(int i=0, j=0; i<strlen(text);) {
		if(text[i] == pat[j]) {
			j++;
			i++;
		} else {
			if(j != 0) {
				j = a[j-1]; // we do not want to increment i here  	
					    // as we want to match this character again
			} else {
				i++;
			}
		}
		if(j == (strlen(pat)-1)) {
			return true;
		}
	}
	return false;
}

void main() {
	//char pat[] = "AABAACAABAA";
	char pat[] = "ABABCABAB";
	int len = strlen(pat);
	int a[len];
	get_array(pat, a, len);

	char text[]= "ABABDABACDABABCABAB";

	if(kmp(text, pat, a)) {
		printf("Pattern found");
	} else {
		printf("Pattern not found");
	}
}
