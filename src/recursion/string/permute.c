/*
Program to print all the permutations of a string.
Repeatations allowed.

e. ip= ABC
op =
	AAA
       AAB
       AAC
       ABA
       ...
       ...
       CCB
       CCC

Learnings: Please look at the program very carefully. Make sure with yourself why a character get considered again for next position.

*/ 

#include<stdio.h>
#include<string.h>

void permute(char str1[], char str2[], int pos, int len) {

	if(pos == len) {
		printf("%s\n", str2);
		return;
	}

	for(int i=0; i<len; i++) { // permutation means try all symbols for given position
		str2[pos] = str1[i];
		permute(str1, str2, pos + 1, len); // for next position i will again start from 0 thats why we see repeats !!!
	}
}

void main() {

	char str[] = "ABC";
	int len= strlen(str);
	char str2[len+1];
	str2[len] = '\0';
	
	permute(str, str2, 0, len);
}
