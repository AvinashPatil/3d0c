/*
Find min length array sorting which will make whole array sorted
*/

#include<stdio.h>


void find_min_array(int a[], int len) {

	int start, end;
	for(int i=0; i<len-1; i++) {
		if(a[i+1] < a[i]) {
			start = i;
			break;
		}
	}

	for(int i=len-1; i>0; i--) {
		if(a[i-1] > a[i]) {
			end = i;
			break;
		}
	}

	for(int i=0; i<start; i++) {
		if(a[i] > a[start]) {
			start = i;
			break;
		}
	}

	for(int i=len-1; i>end; i--) {
		if(a[i] < a[end]) {
			end = i;
			break;
		}
	}
	printf("start = %d end = %d ", a[start], a[end]);
}

void main() {
	
	int a[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int len = sizeof(a)/sizeof(a[0]);
	
	find_min_array(a, len);

}
