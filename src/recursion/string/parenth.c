/*
	This program prints all the possible parenthesis combinations. 

Learnings: 
	1. Do not change value of variable in giving recursion call.
	2. Look at the conditions in IF carefully.

*/
#include<stdio.h>



int parenth(char str[], int count, int lcount, int rcount) {

	if(lcount < 0 || rcount < lcount) {
		return -1; 
	}

	if(lcount  == 0 && rcount == 0) {
		str[count] = '\0';
		printf("%s\n", str);
		return 0;
	}

	if(lcount > 0) {
		str[count] = '(';

		parenth(str, count+1, lcount -1, rcount);
	}

	if(lcount <  rcount) { // this means there are more '(' than ')'
		str[count] = ')';
		parenth(str, count+1, lcount, rcount - 1);
	}
}


void main() {
	
	char str[6] = {0};
	parenth(str, 0, 3, 3);
}
