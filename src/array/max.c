/* Find element in Array which has first increasing and then decreasing elements

Time taken : 
	1. Use == in if condition and NOT = !!!!!

*/
#include<stdio.h>


int findmax(int a[], int low, int high) {
	// Only one element
	if(high == low) {
		return a[low];	
	}
	
	// two elements left
	if(high == low +1) {
		if(a[high] > a[low])
			return a[high];
		else
			return a[low];
	}

	int mid = low + (high - low)/2;

	// found 
	if((mid == 0 || a[mid] > a[mid-1]) && (mid == high || a[mid] > a[mid+1]))
		return a[mid];

	//recurse
	if(a[mid] > a[mid-1] && a[mid] < a[mid+1])
		return findmax(a, mid+1, high);
	else
		return findmax(a, low, mid-1);
}

void main() {
	int a[] = {-3, -4, 1, 3, 4, 8, 6, 5, 4, 1};
	int len = sizeof(a) / sizeof(a[0]);

	printf(" Max is %d  %d",findmax(a, 0, len-1), len);
	
}
