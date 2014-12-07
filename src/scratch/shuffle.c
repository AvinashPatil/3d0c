/* Reshuffle array randomly.
This is called Fisher Yates Apgorithm
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void reshuffle(int a[], int len) {
	// seed the random number generator
	srand(time(NULL));
	
	for(int i=len-1; i>0; i--) {
		int j = rand()%i;
		swap(a, i, j);
	}	
	return;
}

void main() {
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int len = sizeof(a)/sizeof(a[0]);

	reshuffle(a, len);
	for(int i=0; i<len; i++) {
		printf("%d ", a[i]);
	}
}
