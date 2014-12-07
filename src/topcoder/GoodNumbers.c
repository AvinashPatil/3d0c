/*
http://community.topcoder.com/stat?c=problem_statement&pm=12816

Can we make it faster??
*/


#include<stdio.h>
#include<stdbool.h>


bool check(int a[], int b[], int len, int num) {
	// check if num is multiple of a[i] and not b[i]
	// for any i

	for(int i=0; i<len; i++) {
		if(num>a[i] && num%a[i] == 0 && num%b[i] != 0 ) {
			return true;
		}
	}

	return false;
	
}	

int count(int a[], int b[], int len, int N) {
	int ret=0;
	for(int num=1; num<=N; num++) {
		if(check(a, b, len, num))
			ret++;
	}

	return ret;

}


void main() {
	int a[] = {168120222,756,408,194,681,856,964,677,250,845};
	int b[] = {809,652,204,532,420,10,640688057,55,174076738,318};
	
	int len = sizeof(a)/sizeof(a[0]);

	int N = 1000000000; 

	int res = count(a, b, len, N);

	printf("Min count is %d", res);
}



