/*
Implement your own strtok.

Algorithm:

1. Keep a static pointer to start of string
2. Check if the current char is one of the delimiters.
3. If it is then ignore til we reach non delimiter
4. Advance the end of token till there is non-delimiter character or '\0' 

*/


#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#define MAX 256
 
static char *start = NULL;

char * strtok1(char *str, char *delim) {

	if(str) {
		start = str;
	}

	// ignore the initial chars which are delimiters 
	
	while(true) {
		for(int i=0; i<strlen(delim); i++) {
			if(delim[i] == *start) {
				start++;
				continue;
			}
		}
		break;
	}

	// check if start has reached to EOS
	if(*start == '\0') {
		return NULL;
	}

	// locate the end of this token
	char *end = start;
	
	while(true) {

		for(int i=0; i<strlen(delim); i++) {
			if(delim[i] == *end) {
				break;
			}
		}

		end++;

		if(*end == '\0') {
			char *temp = start;
			start = end;
			return temp;
		}
	}
	
	char *ret = start;
	*end = '\0';
	start = end+1;
	return ret;
}


int main ()
{
	char str[] ="- This,.. a sample string.";
	char * pch;
	printf ("Splitting string \"%s\" into tokens:\n",str);
	pch = strtok1(str," ,.-");
	while (pch != NULL)
	{
		printf ("%s\n",pch);
		pch = strtok1(NULL, " ,.-");
	}
	return 0;
}
