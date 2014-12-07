/* Prgram to remove min elements from either side such that 
2*min > max*/

#include<stdio.h>
#include<limits.h>
#define MIN(a,b) ((a<b)?a:b)

int remove_min(int a[], int len) {

	int removals = len;
	for(int i=0; i<len; i++) {
		int max = INT_MIN;
		int min = INT_MAX;
		for(int j=i; j<len; j++) {

			if(a[j] < min) {
				min = a[j];
			}

			if(a[j] > max) {
				max = a[j];
			}

			if(2*min >  max) {
				if(removals > (len - (j-i)))
					removals = len - (j-i);
			}
		}
	}
	return removals;
}

int getmin(int a[], int start, int end) {
	int min = INT_MAX;
	for(int i=start; i<=end; i++) {
		if(a[i] < min) {
			min = a[i];
		}
	} 
	return min;
}

int getmax(int a[], int start, int end) {
	int max = INT_MIN;
	for(int i=start; i<=end; i++) {
		if(a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

int remove_min_dp(int a[], int l, int h) {

	if(l>=h) {
		return 0;
	}
	int min = getmin(a, l, h);
	int max = getmax(a, l, h);
	if(2*min > max) {
		return 0;
	}
	return MIN(remove_min_dp(a, l+1, h),
			remove_min_dp(a, l, h-1)) + 1;
}


void main() {
	int a[] = {4, 5, 100, 9, 10, 11, 12, 15, 200};
	int len = sizeof(a)/sizeof(a[0]);

	printf("Min removals = %d ", remove_min(a, len));
	printf("Min removals = %d ", remove_min_dp(a, 0, len-1));

}
