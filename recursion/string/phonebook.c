/* Program to print all strings possible give a phone key pad
	

	 I dont believe i wrote this program correctly :)
*/


#include<stdio.h>
#include<string.h>

char phone[10][5] = {"abc", "def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printnames_util(char num[], char str[],  int len, int pos) {

	if(pos == len) {
		str[len] = '\0';
		printf("%s\n", str);
		return;
	}
	
	int cur_ph_digit = num[pos] - '0';
	
	for(int i=0; i< strlen(phone[cur_ph_digit]); i++) {

		str[pos] = phone[cur_ph_digit][i];
		printnames_util(num, str, len, pos+1);	
	}
}
	
void printnames(char num[]) {
	int len = strlen(num);
	char str[len + 1];
	printnames_util(num, str, len, 0);
}

void main() {
	printnames("345");
}
