/* Program to find if two elements add to value X */


#include<stdio.h>
#include<string.h>
#define MAX 10000


void findpair(int a[], int len , int x) {
	int bitmap[MAX];
	memset(bitmap, 0, sizeof(bitmap));
	
	for(int i= 0; i<len; i++) {
		if(bitmap[x-a[i]] == 1) {
			printf("Pair is %d %d", a[i], x - a[i]);
		}
		bitmap[a[i]] = 1;	
	}
}


void main() {
	int a[] =  {3, 5, 6, 1, 7, 2};
	int len = sizeof(a)/sizeof(a[0]);
	findpair(a, len, 13);
}


