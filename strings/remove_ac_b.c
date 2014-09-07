/* Program to remove 'ac' and 'b'  from given string.

Learning:
1. When we 'continue' in the loop the increment takes place. Take this in account!!!!!!!!

*/ 

#include<stdio.h>
#include<string.h>


void remove_ac_b(char str[]) {

	int len = strlen(str);

	int cur_end;

	cur_end = 0;	

	for(int i=0; i<len; ) {
		if (str[i] == 'b') {	
			i = i + 1;
			continue;
		}
		if(str[i] == 'a' && str[i+1] == 'c') {
			i = i + 2;
			continue;
		}

		if(i<len) {
			str[cur_end++] = str[i++];
		}
	}

	str[cur_end] = '\0';
}

void main() {

	//char str[]="acbac";
	//char str[]="aaac";
	//char str[]="ababac";
	char str[]="bbbbd";

	remove_ac_b(str);

	printf("After removal %s", str);
}
