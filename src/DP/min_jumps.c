/* 
Program to find min number oj jumps to reach the end.

This program builds table jumps[i] which stores the min jumps required to reach to ith position from left. 
Learning : 
	1. Use memset when want to set mem to 0
	

	BE VERY CAREFUL ABOUT BOUNDARY CONDITIONS
*/

#include<stdio.h>
#include<string.h>
#include<limits.h>



int minjumps(int a[], int len) {
	int jumps[len];

	jumps[0] = 1;
	for(int i = 1; i<len; i++) {

		jumps[i] = INT_MAX;

		for(int j = 0; j<i; j++) {
			if((i <= (jumps[j] + a[j])) && (jumps[i] > (jumps[j] + 1))) {
				jumps[i] = jumps[j] + 1;
			}
		}
	}
	
	/*for(int i = 0; i<len; i++) {
		printf("%d ", jumps[i]);
	}	*/
	return jumps[len-1];
}

void main() {
	int a[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	//int a[] = {1, 1, 1, 1,1 ,1 ,1 ,1,  1, 1, 1, 1 };
	int len = sizeof(a)/ sizeof(a[0]);

	
	int res = minjumps(a, len);
	printf("\nMin jumps %d", res);
}	

