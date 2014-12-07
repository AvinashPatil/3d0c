#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define diff(a, b) (abs(a-b))


int min_avg(int a[], int len, int pos, int included, int total, int cur_sum) {

	// base case
	if(pos == len) {
		//return (((total-cur_sum)/(len-included)) - ((included > 0)?(cur_sum/included):0));
		if(included < len && included >0) {
			int avg1, avg2;
			avg1 = (total - cur_sum) / (len - included);
			avg2 = cur_sum/ included;
			return abs(avg1-avg2);
		} else {
			return INT_MAX;
		}

	}

	int min = INT_MAX;

	int res =  diff(min_avg(a, len, pos+1, included+1, total, cur_sum + a[pos]) , 
		   min_avg(a, len, pos+1, included, total, cur_sum));

	if(res < min) {
		min = res;
	}

	return min;
}

void main() {

	int a[] = {1, 7, 4, 3, 8, 3, 9, 1000};
	int len = sizeof(a)/sizeof(a[0]);

	int sum = 0;
	for(int i=0; i<len; i++) {
		sum = sum + a[i];
	}

	printf("Min avg diff is %d", min_avg(a, len, 1, 1, sum, a[0]));
}
