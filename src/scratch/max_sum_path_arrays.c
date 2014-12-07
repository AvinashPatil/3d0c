#include<stdio.h>
#define MAX(a, b) ((a>b)?a:b)

int max_sum(int a[], int b[], int m, int n) {

	int i=0, j=0;
	int res_sum = 0, sum_a =0, sum_b = 0;
	
	
	while(i<m && j<n) {
		if(a[i] < b[j]) {
			sum_a += a[i];
			i++;
		} else if (a[i] > b[j]){
			sum_b += b[j];
			j++;
		} else if(a[i] == b[j]) {
			sum_a += a[i];
			sum_b += b[j];
			i++;
			j++; 	
			res_sum += MAX(sum_a, sum_b);
			sum_a = 0; sum_b = 0;
		}
	} 
	
	for(; i<m; i++) {
		sum_a += a[i];
	}

	for(; j<n; j++) {
		sum_b += b[j];
	}

	res_sum += MAX(sum_a, sum_b);
	return res_sum;
}


void main() {

	int a[]  = {2, 3, 7, 10, 12, 15, 30, 34};
	int b[] =  {1, 5, 7, 8, 10, 15, 16, 19};

	int len_a = sizeof(a)/sizeof(a[0]);
	int len_b = sizeof(b)/sizeof(b[0]);
	int res = max_sum(a, b, len_a, len_b);
	printf("Max sum is %d", res);
}
