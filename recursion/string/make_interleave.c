/* Program to print interleavings of a string.
Note that the order of chars  should not change.


Learnings: 

1. Always write the base case first before the recursion.
2. Do not increment local varibale in the recursive call such as i++. Use i+1 to call.

*/


#include<stdio.h>
#include<string.h>


void interleave(char str1[], char str2[], int m, int n, char ils[], int index) {
	
	// Base case
	if(m ==0 && n ==0) {
		ils[index] = '\0';
		printf("%s\n", ils);
	}

	// Recurse
	
	if(m != 0) {
		ils[index] = str1[0];
		interleave(str1+1, str2, m-1, n, ils, index+1);
	}

	if(n != 0) {
		ils[index] = str2[0];
		interleave(str1, str2+1, m, n-1, ils, index+1);
	}
}


void main() {

	char str1[] = "ABCD";
	char str2[] = "XYZ";

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	char ils[len1+len2+1];
	memset(ils, 0 , len1+len2+1); 
	interleave(str1, str2, len1, len2, ils, 0);
}
