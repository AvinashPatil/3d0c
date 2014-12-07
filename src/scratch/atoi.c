#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int atoi(char s[]) {

	int res=0;
	int len = strlen(s);
	bool is_neg = false;
	int i = 0;

	if(s[0] == '-') {
		is_neg = true;
		i = 1;
	}

	for(; i<len; i++) {
		res = (res*10) + (s[i] - '0');
	}

	return ((is_neg)?res*-1:res);
}


int atoin(char s[]) {

	int temp = 0;

	for(int i=0; s[i] != '\0'; i++) {
		temp = (temp*10) + (s[i] - '0');
	}
	return temp;
}

void main() {

	int a = atoin("1234");
	printf("%d", a);
}
