#include<stdio.h>

int setbit(int n) {
	return ( n>0 ? 1+ setbit(n/2): 0);
}


void main(){
	int i = 16;

	printf("Set bit position in %d is %d", i, setbit(i));
}

	
