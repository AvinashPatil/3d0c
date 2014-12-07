#include<stdio.h>
#include<limits.h>
#define MAX(a, b) ((a>b)?a:b)


int cutrod(int price[], int len) {

	if(len <= 0) {
		return 0;
	}

	int max = INT_MIN;

	for(int i=0; i<len; i++) {
		max = MAX(max, price[i] + cutrod(price, len - i - 1));
	}

	return max;
}

void main() {
	int a[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int len = sizeof(a)/sizeof(a[0]);
	printf("Max obtainable price is %d", cutrod(a, len-1));	
}
