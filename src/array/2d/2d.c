
/*
Learning : 
	1. Do not apply sizeof on array in the called function!!!!
*/


#include<stdio.h>
#include<limits.h>
#include<string.h>

#define COL 5
#define ROW 5


void kadane(int a[], int *sum, int *start, int *end) {
	int p_start = 0;
	int cursum;
	*start = *end  = 0;
	cursum = 0;
	*sum = INT_MIN;

	for(int i=0; i < ROW; i++) {

		cursum = cursum + a[i];
		
		//printf("In loop  %d\n", cursum);	
		if(cursum < 0) {
			cursum = 0;
			p_start = i;
		}
		else if(cursum > *sum) {
			*sum = cursum;
			*end = i;
			*start = p_start;
		}
		
	}
	
//	printf("In kadane start = %d end %d \n", *start, *end);
}


void findmaxrect(int a[][COL], int *startcol, int *endcol, int *startrow, int *endrow, int *maxsum) {

	*maxsum = 0;
	int temp[ROW];
	int start, end, right, sum;
	
	for(int left=0; left<COL; left++) {
		memset(temp, 0 , sizeof(temp));
		for(right=left; right<COL;right++) {

			for(int i=0; i<ROW; i++) {
				temp[i] += a[i][right];
			}

			kadane(temp, &sum, &start, &end);

			if(sum > *maxsum) {
				//update ever
				*maxsum = sum;
				*startcol = left;
				*endcol = right;
				*startrow = start;
				*endrow = end;
				//printf("Here Maxsum = %d sum = %d start = %d end = %d ", *maxsum, sum, start, end);
			}
		}
	}
}


void main() {

	int a[ROW][COL] = 	{ {-1, 3, 4, 0, 2},
				  { 3, 5, 7, -5, 2},
				  {-7- 10, 3, 5, 1},
				  { 9, -8, -7, 1, 6},
				  { 3, 2, 4, 2, 0}		
				};

	int startcol, endcol, startrow, endrow, maxsum;
	findmaxrect(a, &startcol, &endcol, &startrow, &endrow, &maxsum);	
	printf("Max sum is %d and startcol = %d, endcol = %d, startrow = %d, endrow = %d", maxsum, startcol, endcol, startrow, endrow);
}
