#include<stdio.h>
#include<string.h>


void swap(char s[], int i, int j) {

	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

void permute(char s[], int start, int end) {

	if(start == end) {
		printf("%s\n", s);
		return;
	}

	for(int i=start; i<=end; i++) {
		swap(s, start, i);
		permute(s, start+1, end );
		swap(s, start, i);
	}
}

void main() {
	char s[] = "abcd";
	int len = strlen(s);
	permute(s, 0, len-1);
}


