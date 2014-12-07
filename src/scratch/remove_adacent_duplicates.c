#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void remove_dup(char s[]) {
	int len = strlen(s);
	int j=0;
	for(int i=0; i<len; i++) {
		if(s[i] != s[j]) {
			s[j] = s[i];
			j++;
		}	
	}
	s[j] = '\0';
	printf("%s\n", s);
}

void remove_dup1(char s[]) {

	int end = 1;
	for(int i=1; i<strlen(s); i++) {
		int j;
		for(j=0; j<end; j++) {
			if(s[j] == s[i]) {
				break;
			}
		}
		if(j == end) {
			s[end] = s[i];
			end++;
		}
	}
	s[end] = '\0';
	printf("%s\n", s);
}


bool remove_dup2(char s[]) {

	int cur = 0;
	int i = 1;
	bool flag = false;
	while(s[i] != '\0') {
		if(s[cur] != s[i]) {
			if(flag) {
				s[cur] = s[i];
			}
			cur++;
			i++;
		} else {
			flag == true;
			i++;
		}
	}
}

void main()  {
	char s[] = "azxxxzy";
	//remove_dup1(s);

	//while(remove_dup2(s)) {
		;
	}
	printf("%s\n", s);
}

