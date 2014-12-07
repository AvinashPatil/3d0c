/*
	Program to print next big number with same number on 1's

Learnings:
	1. Shift number by 31 places and not 32!!
*/

#include<stdio.h>
#include<stdbool.h>

int setbit(int i, bool value, int index) {
	if(value == true) {
		return  (i | 1<<index);
	} else {
		int mask = 0;
		mask = mask | (1<<index);
		return (i & ~mask);
	}
}

bool getbit(int i, int index) {
	return (i & (1<<index));
}


void printbits(int data) {
	for(int i=sizeof(int)*8 - 1; i >= 0; i--) {
		if((data) & (1<<i))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

int getnext(int i) {
	int index = 0;
	int count_ones = 0;

	while(!getbit(i, index))
		index++;

	while(getbit(i, index)) {
		count_ones++;
		index++;
	}
	// make this 0 as 1

	i = setbit(i, 1, index);

	// make  prev 1 as 0
	index--;
	i = setbit(i, 0, index);

	// put all 0's and then 1's
	index --;
	for(index=index-1; index>count_ones; index--) {
		i = setbit(i, 0, index);
	}

	for(index; index >=0; index--) {
		i = setbit(i, 1, index);
	}

	return i;
}

void main() {
	int i = 9; 
	printbits(i);
	i = getnext(i);

	printbits(i);
}
