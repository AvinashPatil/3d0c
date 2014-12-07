#include<stdio.h>
#include<string.h>
#define min(a,b) ((a<b)?a:b)

int edit(char str1[], char str2[], int m, int n) {
	// base case
	if(m == 0) {
		return n;
	}

	if(n == 0) {
		return m;
	}

	int left = edit(str1, str2, m-1, n) + 1;
	int right = edit(str1, str2, m, n-1) + 1;
	int corner = (str1[m] == str2[n]) ? edit(str1, str2, m-1, n-1): edit(str1, str2, m-1, n-1) + 2;

	return min(min(left, right), corner);
}


void main() {

	char str1[] = "hihello";
	char str2[] = "iohello";

	int len1 = strlen(str1);
	int len2 = strlen(str2);


	printf("Edit distance in two strings is %d", edit(str1, str2, len1, len2));
}
