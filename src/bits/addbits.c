/* This program will add two bit strings

Note that the len will be different for two bit strings
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
#define max(a,b) (a>b)? a:b

int getint(char str[]) {
	int len = strlen(str);
	int res = 0;

	for(int i = 0; i<len; i++) {
		if(str[i] == '1') {
			res = res + (1 << i);
		}
	}
	return res;
}
char * get_bitstr(int a, int len) {
	len = len + 2;
	char *res = (char *) malloc(sizeof(char) * len); // one for string term and one for carry
	
	memset(res, 0, len);
	
	int index = 0;
	while(a > 0) {
		if(a & 1) {
			res[index] = '1';
		} else {
			res[index] = '0';
		}
		a = a>>1;
		index++;
	}
	return res;
}
char *  addbits(char str1[], char str2[]) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int x = getint(str1);
	int y = getint(str2);
	int z = x+y;
	char * res = get_bitstr(z, max(len1, len2));
	return res;	
}

char add(char x, char y, int *c) {
	int a = x - '0';
	int b = y - '0';

	int res = a^b;
	if(*c == 1) {
		res = *c ^ res;
		*c = res & (*c);
	}
	else {
		*c = a&b;
	}
	return '0' + res;
}

char * addbits2(char str1[], char str2[]){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	char *res = (char *) malloc(sizeof(char) * (max(len1,len2)+2)); // one for string term and one for carry
	
	int i, j, k;
	k = i = j = 0;
	int carry = 0;
	while(i <len1 && j< len2) {
		res[k++] = add(str1[i++], str2[j++], &carry); 
	}
	while(i < len1) {
		res[k++] = add(str1[i++], '0', &carry); 
	} 
	while(j < len2) {
		res[k++] = add('0',str2[j++], &carry); 
	}
	res[k] = '\0';
	
	return res;
}
	
void main() {

	char str1[] = "1100101";
	char str2[] = "101";

	printf("res is %s \n", addbits(str1, str2));
	printf("res is %s \n", addbits2(str1, str2));
}
