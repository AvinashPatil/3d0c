#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void q_sort(int a[], int low, int high) {

	if (low<high) {
		int p =  low;
		int temp = a[low];
		
		for(int i=low; i<=high; i++) {
			if(a[i] < temp) {
				p++;
				swap(a, i, p);
			}
		}

		swap(a, low, p);
		q_sort(a, low, p-1);
		q_sort(a, p+1, high);
	}
} 


void main() {
	int a[] = {0, 2, 5, 7, 1, 8, 9};
	int len = sizeof(a)/sizeof(a[0]);

	q_sort(a, 0, len-1);

	for(int i=0; i<len; i++) {
		printf("%d ", a[i]);
	}	
}
