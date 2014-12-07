/*
http://community.topcoder.com/stat?c=problem_statement&pm=12888
*/
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

int ORSolitaire(int a[], int len, int desired_no) {

	// calculate the count array

	int size = sizeof(int);

	struct hit {
		int a_index;
		int count;
	};
	struct hit hitmap[size];


	memset(hitmap, 0, size*sizeof(struct hit));

	for(int i=0; i<len; i++) {
		for(int j = 0; j<size; j++) {
			if(a[i] & (1<<j)) {
				hitmap[j].count++;
				hitmap[j].a_index = i;
			}
		}
	}

	// calculate min from count for positions where desired no has 1 bit set
	int min = INT_MAX;

	
	bool repeat[len];
	
	for(int i=0; i<len; i++) {
		repeat[i] = false;
		
	}
	for(int i=0; i<size; i++) {

		if(desired_no & (1<<i)) {

			if(repeat[hitmap[i].a_index] == true) {
				hitmap[i].count--;
			}

			if(min > hitmap[i].count) {
				min = hitmap[i].count;
				repeat[hitmap[i].a_index] = true;
			}
		}
	}
	return min;
}

void main() {

	int a[] = {5,2,4,52,62,9,8,3,1,11,6};
	//int a[] = {503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346};

	int desired_no = 11;
	//int desired_no = 510;

	int len = sizeof(a)/ sizeof(a[0]);

	int res = ORSolitaire(a, len, desired_no);
	printf("Min numbers to be removed is %d", res);
}
