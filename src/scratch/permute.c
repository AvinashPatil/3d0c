#include<stdio.h>
#include<string.h>


void swap(char str[], int i, int j) {
	char temp;
	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}


void permute(char str[], int start, int end) {
	//base case
	if(start == end) {
		printf("%s\n", str);
	}

	for(int i=start; i<=end; i++) {
		swap(str, start, i);
		permute(str, start+1, end);
		swap(str, start, i);
	}
}

void main() {
	char str[] = "abcd";
	int len = strlen(str);

	permute(str, 0, len-1);
}

