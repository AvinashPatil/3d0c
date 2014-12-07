/* Find the next big integer with same set bits */
#include<stdio.h>


int getbit(int n, int index) {
	return ( n & (1<<index)) ? 1 : 0;
}

int  setbit(int n, int index, int val) {

	if(val == 1) {
		n |=  1<<index;
		return n;
	} else if(val == 0) {
		int temp = 1<<index;
		temp = ~temp;
		n &= temp;
		return n;
	}
}

int next_big(int n) {

	int index = 0;
	int ones = 0;

	while(getbit(n, index) == 0) {
		index++;
	}

	while(getbit(n, index) == 1) {
		index++;
		ones++;
	}
	//printf("ones %d", ones);
	n = setbit(n, index, 1);
	ones--;
	index--;
	for(;index >= ones; index--) {
		n = setbit(n, index, 0);
	}
	for(;index >0; index--) {
		n = setbit(n, index, 1);
	}
	return n;
}

void main() {
	printf("Next big is %d", next_big(1));
}

