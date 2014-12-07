/* Find an element in an rotated array */
#include<stdio.h>


int find(int a[], int l, int h, int k) {

	if(l<=h) {
		int mid = l + (h-l)/2;

		if(a[mid] == k) {
			return mid;
		}

		if(a[l] < a[mid]) {
			// left is normal
			if(k >= a[l] && k<a[mid]) {
				return find(a, l, mid-1, k);
			} else {
				return find(a, mid+1, h, k);
			}
		}

		if(a[l] > a[mid]) {
			// right is normal
			if(k > a[mid] && k<= a[h]) {
				return find(a, mid+1, h, k);
			} else {
				return find(a, l, mid-1, k);
			}
		}
	}
	 else 
		return -1;
}

void main() {
	int a[] = {7, 8, 1, 2, 3, 4, 5, 6};
	int b[] = {3, 4, 5, 6, 7, 8, 1, 2};
	int len = sizeof(a)/sizeof(a[0]);	
	int res = find(b, 0, len-1, 5);
	printf("Index is %d", res);
}
