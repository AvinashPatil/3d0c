/*
http://community.topcoder.com/stat?c=problem_statement&pm=12608
*/

#include<stdio.h>
#include<limits.h>
#define MIN(a,b) (a<b)?a:b

int minTimes_right(int range[], int len, int start, int end) {
	
	int min[len];

	for(int i=0; i<len; i++) {
		min[i] = INT_MAX;
	}
	min[start] = 0;
	for(int i=start+1; i<=end; i++) {
		for(int j=start; j<i; j++) {
			if((i <= j+range[j]) && (min[i] > min[j] + range[j])) {
				min[i] = min[j] + range[j];
			}
		}
	}
	/*for(int i=0; i<len; i++) {
		printf(" %d ", min[i]);
	}*/
	return min[end];
}
int minTimes_left(int range[], int len, int start, int end) {
	
	int min[len];

	for(int i=0; i<len; i++) {
		min[i] = INT_MAX;
	}

	min[start] = 0;

	for(int i=start-1; i>=end; i--) {
		for(int j=start; j>i; j--) {
			if((i <= j+range[j]) && (min[i] > min[j] + range[j])) {
				min[i] = min[j] + range[j];
			}
		}
	}
	/*for(int i=0; i<len; i++) {
		printf(" %d ", min[i]);
	}*/
	return min[end];
}

int minTimes(int range[], int len, int start, int end) {

	int range_new[len*2];

	for(int i=0; i<len; i++) {
		range_new[i] = range_new[i+len] = range[i];
	}

	return MIN(minTimes_right(range_new, len*2, start, (end < start)?end+=len:end), 
		minTimes_left(range_new, len*2, (end>start)?start+=len:start, end));
}
	

void main() {
	int range[] = {3,2,1,1,3,1,2,2,1,1,2,2,2,2,3};
	int len = sizeof(range)/sizeof(range[0]); 
	int start = 6;
	int end = 13;


	/*int res = minTimes_right(range, len, start, end);
	printf("%d", res);*/
	int res = minTimes(range, len, start, end);
	printf("%d", res);
}
