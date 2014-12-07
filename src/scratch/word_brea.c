/* Program to put spaces in a word such that the words formed are valid words in a dictionary
*/




#include<stdio.h>
#include<string.h>
#include<stdbool.h>


char *dictionary[] = {"hi", "how", "me", "you", "i", "ice", "cream"};

bool dictionary_contains(char w[], int start, int end) {
	for(int j=0; j<sizeof(dictionary)/sizeof(dictionary[0]); j++) {
		for(int i=start; i<=end; i++) {
			if(dictionary[j][i] != w[i]) {
				break;
			} else if( i==end ) {
				return true;
			}
		}
	}
	return false;
}

bool word_break(char w[]) {
	// base case
	if(w[0] == '\0') {
		return true;
	}
	
	for(int i=0; w[i] != '\0'; i++) {
		if(dictionary_contains(w, 0, i) && word_break(w+i+1)) {
			return true;
		}
	}
	return false;
}

void main() {
	if(word_break("hihowicreamx"))
		printf("Yes"); 
	else 
		printf("No"); 
}


