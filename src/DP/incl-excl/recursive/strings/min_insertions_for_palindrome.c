/*
	Minimum insertions required to make a string palindrome

	Learning :
1. In string always use strlen
2. Calculating size with sizeof always counnts one char extra which is '\0'
*/

#include<stdio.h>
#include<limits.h>
#include<string.h>
#define min(a,b) (a<b)?a:b

int findinserts(char a[], int low, int high) {

	// base cases
	if(low>high) {
		return 100 ;
	}

	// there is only one char left
	if(low == high) {
		return 0;
	}
//	if(low==high-1){
//		return 9;
//	}
	int res;
//	int res = (a[low] == a[high]) ? findinserts(a, (low +1), (high-1)) : 
//			(min(findinserts(a, (low +1), high), findinserts(a, low, (high-1))) +1);
	//printf("res is %d \n", res);

	if(a[low] == a[high]) {
		res = findinserts(a, (low +1), (high-1));
	}
	else {
		res = min(findinserts(a, (low +1), high), findinserts(a, low, (high-1))) + 1;
	}

	return res;
}


void main() {
	char a[] = "geekabcdef kpeeg";
//	int len = sizeof(a)/sizeof a[0];
	int len = strlen(a);
	

	int res = findinserts(a, 0, len-1);
	printf(" Min insertions required %d ", res);
}
