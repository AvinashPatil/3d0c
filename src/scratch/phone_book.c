#include<stdio.h>
#include<string.h>


char phone[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void phone_book_util(char num[], int len, int pos, char name[]) {
	// base case
	if(len == pos) {
		name[pos] = '\0';
		printf("%s\n", name);
		return;
	}

	int index = num[pos] - '0';

	for(int i=0; i<strlen(phone[index]); i++) {
		name[pos] = phone[index][i];
		phone_book_util(num, len, pos+1, name);
	}
	
}

void phone_book(char num[]) {

	int len = strlen(num);
	char name[len];
	phone_book_util(num, len, 0, name);

}



void main() {
	phone_book("724");
}


