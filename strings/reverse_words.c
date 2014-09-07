/*
	Learnings:
1. char *str = "abcd" is a string constant .
2. char str[] = "abcd" is NOT A STRING CONST :O

3. Do not forget *temp to reach upto a char

*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define BLANK 0
#define WORD 1
void reverse(char *start, char *end) {
	char temp;
	while(start < end) {
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void reverse_words(char str[]) {
	char *temp = str;
	char *word_begin = str;

	while(*temp != '\0') {
		temp++;
		if(*temp == ' ') {
			reverse(word_begin, temp -1);
			word_begin = temp + 1;
		}
		if(*temp == '\0') {
			reverse(word_begin, temp-1);
		}
	}
	reverse(str, temp -1);
}

// Clean approach handles the starting spaces and all spaces well. 

void reverse_words1(char str[]) {
	int state = BLANK;
	char *end = str;
	char *word_begin = str;

	while(*end != '\0') {
		end++;
		if(*end == ' ') {
			if(state == WORD) {
				reverse(word_begin, end-1);
				state = BLANK;
			}
			continue;
		}
		if (*end != ' ' && *end != '\0') {
			if(state == BLANK) {
				word_begin = end;
				state = WORD;
			}
			continue;
		}

		if(*end == '\0') {
			reverse(word_begin, end-1);
		}
	}
	reverse(str, end-1);
}

void main() {
	char str[] = "  t um jo aaye    jindagi me baat ban gayi";

	//str[1] = str[0];
	printf("string is  before \n %s\n", str);

	reverse_words1(str);
	printf("string is  after \n %s\n", str);
}
