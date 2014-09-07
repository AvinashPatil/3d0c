/* Maximum Sum Increasing Subsequence
*/
#include<stdio.h>
#include<string.h>



int maxSumIn(int a[], int len) {
	int msis[len];
	memset(msis, 0 , sizeof(msis));

	msis[0] = a[0];
	for(int i= 1; i<len; i++) {
		for(int j=0; j<i; j++) {
			if(a[i] > a[j] && msis[i] < msis[j] + a[i]) {
				msis[i] = msis[j] + a[i];
			}
		}
	}
	
	int max = 0;
	for(int i = 0; i<len; i++) {
		if(msis[i] > max) {
			max = msis[i];
		}
	}
	return max;
}

void main() {
	int a[] = {1, 101, 2, 3, 100, 4, 5};
	int len = sizeof(a)/ sizeof(a[0]);

	int res = maxSumIn(a, len);
	printf("Max sum is %d", res);
}	
