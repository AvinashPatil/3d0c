#include<stdio.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
/*
strategy
F (i, j) represents the max value user can get  from i to j
F(i, j) = Max {  Vi + Min( F(i+2, j), F(i+1, j-1)),
		  Vj + Min( F(i+1, j-1), F(i, j-2))	
		}	


*/

int optimal(int a[], int i, int j) {
	//base case
	if(i == j) {
		return a[i];
	}
	if(i+1 == j) {
		if(a[i] > a[j]) {
			return a[i];
		} else {
			return a[j];
		}
	}
	return max(a[i] + min(optimal(a, i+2, j), optimal(a, i+1, j-1)), 
		   a[j] + min(optimal(a, i+1, j-1), optimal(a, i, j-2)));
}	


void main() {

	int a[] = {8, 15, 3, 7};
	int len = sizeof(a)/sizeof(a[0]);
	int res = optimal(a, 0, len-1);
	printf(" Max value user can get by playing first %d  %d", res, len);
}
