/*
http://community.topcoder.com/stat?c=problem_statement&pm=12436
*/

#include<stdio.h>



void playList(int n, int k) {

	while(n-k > 10) {
		k = k *10;
	}

	for(int i=0; i<10; i++) {
		printf("%d\n", k+i)
	}


}


void main() {
	int i = 116;
	playList(i, 1);
}






