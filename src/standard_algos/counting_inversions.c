#include<stdio.h>

int merge(int a[], int temp[], int p, int q, int r, int s) {
	
	int inv = 0;
	int i = p;
	while(p<=q && r<=s) {
		if(a[r] < a[p]) {
			inv++;
			temp[i++] = a[r++];
		} else {
			temp[i++] = a[p++];
		}
	}
	while(p<=q) {
		temp[i++] = a[p++];
	}

	while(r<=s) {
		temp[i++] = a[r++];
	}
	return inv;

}

// start and len inclusive
int count_invs(int a[], int temp[], int start, int end) {
	int invs = 0;
	
	if(start < end) {
		int mid = start + (end - start)/2;

		invs = count_invs(a, temp, start, mid);
		invs += count_invs(a, temp, mid+1, end);

		invs += merge(a, temp, start, mid, mid+1, end);
	}
	return invs;
}

void main() {
	int a[]= 
//{1, 4, 3, 5, 0, 9};
//{2, 4, 6, 1, 3, 5};
{3, 2, 1};	

	int len = sizeof(a)/sizeof(a[0]);
	int temp[len];

	//int res = count_invs(a, 0, len-1);

	printf("Number of inversions is %d", count_invs(a, temp, 0, len-1));

}
