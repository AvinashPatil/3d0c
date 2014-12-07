/*

Given an array of integers and a number x, find the smallest subarray with sum greater than the given value.

arr[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

Algorithm:
1. Take two pointers left and right starting at 0.
2. Move right ahead till sum is greater than x. Calculate the len.
3. Move the left ahead till sum falls below x. Then repeat step 2. 

*/

#include<stdio.h>
#include<stdlib.h>

int find_subarray_len(int a[], int len , int sum) {
	int left = 0;
	int right = 0;
	int cur_sum = 0;
	int min_len = len-1;

	while(cur_sum < sum) {
		cur_sum += a[right++];
	}

	min_len = right - left;
	

	while (right<len-1 && left<len-1) {

		while (cur_sum > sum) {
			cur_sum -= a[left];
			left++;
		}

		while (cur_sum <= sum) {
			cur_sum += a[right];
			right++;
		}

		if (min_len > (right - left -1))
			min_len = right - left -1;
	}
	return min_len;
}

void main() {
	int a[] = {1, 4, 45, 6, 0, 19};	
	int len = sizeof(a)/sizeof(a[0]);
	int sum = 5;
	int res = find_subarray_len(a, len, sum);
	printf("\nthe subarray len is %d\n", res);
}
