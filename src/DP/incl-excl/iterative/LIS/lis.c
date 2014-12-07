/* Program to print the len of 
	LONGEST INCREASING SUBSEQUENCE
*/

#include<stdio.h>
#include<string.h>

int lis_(int a[], int len) {
	
	int lis[len];
	memset(lis, 0 , sizeof(lis));

	/* This method build table from left to right*/

	for(int i = 1; i<len; i++) {
		for(int j=0; j<i; j++) {
			if(a[i] > a[j] && lis[i] < lis[j] + 1) {
				lis[i] = lis[j] + 1;
			}
		}
	}

	int max = 0;
	for(int i=0; i<len; i++) {
		if(lis[i] > max)
			max = lis[i];
	}
	return max;
}

void main() {
	int a[] = {6, 9, 2, 5, 0, 8, 9, 10};
	int len = sizeof(a)/ sizeof(a[0]);
	printf("len of LIS is %d",lis_(a, len));
}
