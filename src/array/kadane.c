/* Prgram to find a subaaray with max sum
 This is alos known as Kadanes algorithm.
*/
#include<stdio.h>
#include<limits.h>

int findmaxsum(int a[], int len) {
	int sum = 0;
	int maxsum = INT_MIN;

	for(int i=0; i<len; i++) {

		sum = sum + a[i];

		if(sum > maxsum) {
			maxsum = sum;
		}

		if(sum < 0) {
			sum = 0;
		}
	}
	return maxsum;
}


void main() {
	int a[] = {-3, -2, 1 , 4, 3, -7 , 0, 5, 6};
	printf(" Max sum is %d",findmaxsum(a, (sizeof(a)/sizeof a[0])));
}
