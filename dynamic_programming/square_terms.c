#include<stdio.h>
#include<limits.h>
#define MAX 1000

int min_terms(int sum, int term, int table[]) {

	if(sum == 0) {
		return term;
	}
	if(sum<0) {
		return INT_MAX;
	}

	if(table[sum] > 0) {
		return table[sum];
	}

	int res = 0;
	int min = INT_MAX;
	for(int i=1; i<(sum); i++) {
		res = min_terms(sum - (i*i), term + 1, table);
		if(res < min) {
			min = res;
		}
	}

	table[sum] = min;
	return min;
}

void main() {
	int table[MAX] = {0};
	
	int res = min_terms(121, 0, table);
	printf("Min perfet square terms reqiured are %d", res);
}
