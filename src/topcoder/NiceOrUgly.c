/*
http://community.topcoder.com/stat?c=problem_statement&pm=6871
*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool checkVolwel(char a) {

	if(a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U') {
		return true;
	}
	return false;
}	

bool any_nice (int a, int b, int c, int d) {
	if(a ==0 || b ==0 || c ==0 || d==0)
		return true;
	return false;
}

bool any_ugly(int a, int b, int c, int d) {
	if(a ==1 || b ==1 || c ==1 || d==1)
		return true;
	return false;
}	

int nice_ugly(char str[], int len, int pos, int vowel_count, int cons_count) {

	int flag1, flag2, flag3, flag4;	
		
	flag1 = flag2 = flag3 = flag4= -1;

	if(vowel_count >=3 || cons_count >=5) {
		return 1;
	}

	if(pos == len) {
		return 0; // nice
	}

	if(checkVolwel(str[pos]) == true) {
		flag1 = nice_ugly(str, len, pos+1, vowel_count+1, 0);
	} else if (str[pos] != '?') {
		flag2 = nice_ugly(str, len, pos+1, 0, cons_count+1);
	}
	if(str[pos] == '?') {
		flag3 = nice_ugly(str, len, pos+1, vowel_count+1, 0);
		flag4 = nice_ugly(str, len, pos+1, 0, cons_count+1);
	}

	if(any_nice(flag1, flag2, flag3, flag4) && any_ugly(flag1, flag2, flag3, flag4)) {
		return 42;
	}
	if(any_nice(flag1, flag2, flag3, flag4)) {
		return 0;
	}
	if(any_ugly(flag1, flag2, flag3, flag4)) {
		return 1;
	}
}

void main() {
	//char str[] = "HELLOWORLD";
	//char str[] = "H??LOWOR??";
	char str[] = "HELLOW?RLD";
	//char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int len = strlen(str);

	int res = nice_ugly(str, len, 0, 0, 0);

	if(res == 1) {
		printf("Ugly");
	} else if (res == 0) {
		printf("Nice");
	} else {
		printf("42");
	}
}	

