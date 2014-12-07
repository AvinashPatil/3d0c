/*
Given a sorted array arr[] and a value X, find the k closest elements to X in arr[].

Input: K = 4, X = 35
       arr[] = {12, 16, 22, 30, 35, 39, 42, 
               45, 48, 50, 53, 55, 56}
Output: 30 39 42 45
*/
/*Algorithm:

1. Find the index of the given element. If the value X does not belong in array then get the crossover index.
2. Then from that index traverse to left and right. Adding 1 element each time which is closest to X.
*/

#include<stdio.h>
#include<stdlib.h>

int get_index(int a[], int low, int high, int x) {

	if(low<high) {
		int mid = low+(high-low)/2;

		if(a[mid] == x) {
			return mid;
		}

		if(mid == low || (a[mid-1]<x && a[mid+1] >x)) {
			return mid;
		}
		
		if(x<a[mid]) {
			return get_index(a, low, mid-1, x);
		} else {
			return get_index(a, mid+1, high, x);
		}
	}
}


void find_k_closest(int a[], int len, int x, int k) {
	int index = get_index(a, 0, len-1, x);
	//printf("%d ", index);

	int left = (index > 0)? (index -1) : 0;
	int right = (index < len-1)? index +1 : len-1;
	
	while(left > 0 && right<len-1) {

		if(abs(a[left]-a[index]) < abs(a[right]-a[index])) {
			left--;
		} else {
			right++;
		}
	}

	int count = right-left;

	while(left > 0 && count < k) {
		left--;
		count++;
	}

	while(right < len-1 && count < k) {
		right++;
		count++;
	}

	if(left <0 || right > len-1) {
		printf("error");
	}

	for(int i=left; i<=right; i++) {
		printf("%d ", a[i]);
	} 

}

void main() {

	int a[] = {12, 16, 22, 30, 35, 39, 42, 
               45, 48, 50, 53, 55, 56};

	int len = sizeof(a)/sizeof(a[0]);
	//find_k_closest(a, len, 10, 4);
	find_k_closest(a, len, 56, 4);
}



