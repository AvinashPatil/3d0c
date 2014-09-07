/*
	Program to fill knapsack with capacity W  with weights wt  such that value val  is maximum.
	The weights can repeat.
*/

#include<stdio.h>
#define max(a,b) (a>b) ? a : b;



int knapsack(int wt[], int val[], int index, int cap, int cur_val) {
	//base cases
	if(cap<=0) {
		return cur_val;
	}	
	if(index < 0) {
		return cur_val;
	}
	// Includeing this weight : cap and cur_val will chnage, index wont change as we want to consider this weight again
	// excluding this weight : only index will change as we want to drop this weight.
	return max(knapsack(wt, val, index, cap-wt[index], cur_val + val[index]), 
		knapsack(wt, val, index-1, cap, cur_val));
}

void main() {
	int wt[] = {10, 20, 30};
	int val[] = {60, 100, 120};
	int cap = 50;
	
	int len = sizeof(wt) / sizeof(wt[0]);

	int res = knapsack(wt, val, len - 1, cap, 0); 	 
	printf("Max value is %d", res);
}
