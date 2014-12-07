/*
 Reverse a string:

Either use array or use pointers.
Keep an eye where end points to '\0' remember to decrement it there.


ALWAYS ALLOCATE A STRING IF YOU WANT TO USE IT IN ANOTHER FUNCTION.
DO NOT TRY TO UPDATE A CONSTANT STRING!!!

REMEMBER strlen GIVES len WHICH YOU SHOULD USE LIKE len-1

THIS CAN SCREW UP BOUDARIES.

*/

#include<stdio.h>


void reverse(char *str){

	int start = 0;
	int end = 0;

	while(str[end] != 0) {
		end++;
	}

	end--;
		
	while(start != end) {	
		char temp;
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}

	printf("%s", str);

}

void reverse1(char *str) {

	char *start, *end;
	start = end = str;
	while(*end != '\0')
		end++;
	end--;
	while(start != end) {
		char  temp;
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	printf("%s", str);
}

void main() {
	char str[100] = "hi this is string";
	reverse1(str);
}
