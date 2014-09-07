#include<stdio.h>
#include<string.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)


int LCSubseq(char a[], char b[], int m, int n) {

	//base cases
	if(m<0 || n<0) {
		return 0;
	}

	if(a[m] == b[n])
		return 1 + LCSubseq(a, b, m-1, n-1);
	else 
		return max(LCSubseq(a, b, m-1, n), LCSubseq(a, b, m, n-1));
}

int LCSubstr(char a[], char b[], int m, int n) {

	//base cases
	int MAX = INT_MIN;
	int res = 0;

	if(m==0 || n==0) {
		return 0;
		
	}

	if(a[m] == b[n]) {
		res = 1+ LCSubstr(a, b, m-1, n-1);
	} else {
		res = max(LCSubstr(a, b, m, n-1), 
		LCSubstr(a, b, m-1, n));
	}
	if(res > MAX) {
		MAX = res;
	}
	return MAX;
}

void main(){
	char a[] = "abviznash";
	char b[] = "avinashpatil";

	int m = strlen(a);
	int n = strlen(b);

	int res = LCSubseq(a, b, m-1, n-1);
	printf("LCSubseq is %d\n", res);
	res = 0;
	res = LCSubstr(a, b, m-1, n-1);
	printf("LCSubstr is %d\n", res);

} 

