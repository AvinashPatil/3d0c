/* find the smallest subarray with sum greater than k in O(n) time*/

#include<stdio.h>


int find_smallest(int a[], int len, int k) {

	int start=0;
	int end =0;
	int sum = a[start];

	int min_len = len;

	sum = 0;

	for(int i=0; i<len; i++) {

		sum=sum+a[end];
		if(sum>=k) {
			if(min_len > (end - start)) {
				min_len = end-start;
			}
		}

		while(sum-a[start] > k) {
			start++;
		}

		end++;

	}
	return min_len;
}

void  main() {

	int a[]= {1, 4, 45, 6, 10, 19};
	int len = sizeof(a)/sizeof(a[0]);

	printf("min len is %d\n", find_smallest(a, len, 51));
}
