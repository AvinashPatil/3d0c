#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX 256
char * remove_dup(char str[]) {

	int len = strlen(str);
	char *res = (char *) malloc(len +1);
	int hit[MAX];
	memset(hit, 0, sizeof(hit));

	for(int i = 0, end = 0; i<len; i++) {
		if(hit[str[i]] == 0) {
			res[end++] = str[i];
			hit[str[i]]++;
		}
	}
	//res[end] = '\0';
	return res;
	
}


void main() {
	char a[] = "geeksforgeeks";
	printf("string after dumplicate removals is %s", remove_dup(a));
}
