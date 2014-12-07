/*
http://community.topcoder.com/stat?c=problem_statement&pm=13166
http://community.topcoder.com/stat?c=problem_statement&pm=13166&rd=15854

Learning : NEVER EVER DO pos++ in recursive call..use pos+1.. this kills lot of time 

We have to find the lowest sum which can not be the sum of any subset of given set.
Two Algos
1. Calculate MAx sum. For each i in max sum check if there exists a subset which adds to i.

2. Calculate Max. For each sum of subset generated mark temp[i] as true. Then return smallest i for which temp[i] is false.

*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX 100

bool sum_of_sub(int a[], int len, int k, int cur_sum, int pos) {

	// base case
	if(cur_sum == k) {
		return true;
	}	
	if(pos == len) {
		return false;
	}

	return (sum_of_sub(a, len, k, cur_sum + a[pos], pos+1) || sum_of_sub(a, len, k, cur_sum, pos+1));
}

void sum_of_sub_new(int a[], int len, int max_sum, int cur_sum, int pos, bool temp[]) {

	// remember here cur_sum is of previous invokation
	// pos is advanced 
	// so we have to do this early than the base case.

	temp[cur_sum] = true;

	// base case
	if(cur_sum == max_sum) {
		return ;
	}
	if(pos == len) {
		return ;
	}
	//temp[cur_sum] = true;

	sum_of_sub_new(a, len, max_sum, cur_sum + a[pos], pos+1, temp); 
	sum_of_sub_new(a, len, max_sum, cur_sum, pos+1, temp);
	return;
}


int findsum(int a[], int len) {
	int sum = 0;
	for(int i=0; i<len; i++) {
		sum += a[i];
	}
	return sum;
}

void main() {

	//int a[] = {5, 1, 2};
	int a[] = 	
	{883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13};
		

//{94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1};
//{2, 1, 2, 7};

	int len = sizeof(a)/ sizeof(a[0]);
	

	int max_sum = findsum(a, len);

/*	for(int i=1; i<= max_sum; i++) {
		if(sum_of_sub(a, len, i, 0, 0) == false) {
			printf("The min sum can not be formed is %d", i);
			break;
		}
	}
*/



	bool temp[max_sum+1];
	for(int i=0; i<= max_sum; i++) {
		temp[i] = false;
	}
	
	sum_of_sub_new(a, len, max_sum, 0, 0, temp);

	for(int i=1; i<= max_sum; i++) {
		if(temp[i] == false) {
			printf(" %d", i);
			break;
		}
	}
}
