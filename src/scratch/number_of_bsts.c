/* Find the number of bsts formed given number of nodes */

#include<stdio.h>


int count_bsts(int nodes) {

	if(nodes <= 1) {
		return 1;
	}

	int sum = 0;
	int left, right;

	for(int i=1; i<=nodes; i++) {
		left = count_bsts(i-1);
		right = count_bsts(nodes-i);
		sum += (left * right);
	}
	return sum;
}

void main() {
	printf("Number of bsts are %d ", count_bsts(4));
	
}

