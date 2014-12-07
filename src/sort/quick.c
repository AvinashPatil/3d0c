/*
	Standart quicksort.
	Stil buggy.
*/

#include<stdio.h>




void quick(int a[], int low, int high) {

	if(low < high) {
		int temp = a[low];
		
		int m = low; 
		for(int j=low+1; j<high; j++) {
			if(a[j] < temp) {
				int t = a[m];
				a[m] = a[j];
				a[j] = t;
				m++;
			}
		}
		a[m] = temp;
		quick(a, low, m-1);
		quick(a, m+1, high);
	}
}


int main() {

	int a[] = {3, 6, 1, 3, 7, 8, 9, 2, 5};

	int len = sizeof(a) / sizeof(a[0]);
	quick(a, 0, len);

	for(int i=0; i<len; i++)
		printf("%d", a[i]);
	return 0;
}
