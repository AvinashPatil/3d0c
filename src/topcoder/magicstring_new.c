#include<stdio.h>
#include<string.h>
#include<stdbool.h>


int magic_string_len(char str[], int len) {

	int i = 0;
	int j = len-1;

	bool flag_a, flag_b;
	int magic_len = 0;

	while(i<j) {

		if(str[i++] == '>' && str[j--] == '<') {
			magic_len += 2;
		}

		while(str[i] != '>' && i<j) {
			i++;
		}

		while(str[j] != '<' && i<j) {
			j--;
		}
	}
	return magic_len;
}

void main() {
	//char str[] = "<><><<>";
	char str[] = "<<>>";
	//char str[] = "<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>";
	//char str[] = ">>><<<";

	int len = strlen(str);

	int res = magic_string_len(str, len);
	printf("magic str len is %d", res);
}
