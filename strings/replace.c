/* Program to replace spaces with %20 in a string.
	
ALWAYS ALLOCATE A STRING IF YOU WANT TO USE IT IN ANOTHER FUNCTION.
DO NOT TRY TO UPDATE A CONSTANT STRING!!!

REMEMBER strlen GIVES len WHICH YOU SHOULD USE LIKE len-1

THIS CAN SCREW UP BOUDARIES.

*/

#include<stdio.h>
#include<string.h>

void replace(char *str) {
	int len = strlen(str);
	int spaces = 0;
	
	for(int i=0; i<len; i++) {
		if(str[i] == ' ') {
			spaces++;
		}
	}

	int new_len = (len + spaces* 2) - 1;

	for(int i= len-1; i >= 0; i--) {
		if(str[i] != ' ') {
			str[new_len--] = str[i];
		} else {
			str[new_len--] = '0';
			str[new_len--] = '2';
			str[new_len--] = '%';
		}
	}
	printf("%s", str);
}

void main() {

	char str[100] = "hi this is the string";
	
	replace(str);	
}
