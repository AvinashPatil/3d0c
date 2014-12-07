#include<stdio.h>


int ways(int coins[], int m , int sum) {

	if(sum == 0) {
		return 1;
	}

	if(m<=0 || sum < 0) {
		return 0;
	}
	
	/* 1. Exclude current coin. - note we only move to next coin here. Sum is unchanged.
	   2. Include current coin - note ony sum chnages, means we use the coin, but we do not move to next coin, as we want to use it again!!
	*/		 
	return ways(coins, m-1, sum) + ways(coins, m, sum - coins[m]);
}

void main() {
	int coins[] = {1, 5, 10, 25, 50};
	int m = sizeof(coins)/sizeof(coins[0]);
	int res = ways(coins, m, 4);
	printf("Number of ways are %d", res);
	
}


