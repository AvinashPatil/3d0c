#include<stdio.h>
#include<stdbool.h>

// General include-exclude logic
bool sos(int a[], int len, int k, int index) {

	if(k == 0) {
		return true;
	}	
	if(index < 0) {
		return false;
	}
	/* 1. exclude - sum is as it is and we move to next coin.
	   2. Include - both the sum chnages and we move to next item. This means we use each instance only once.
	*/		
	return (sos(a, len, k, index-1) || sos(a, len, k-a[index], index-1));
}

// This is second method using the bit logic.
// This is more efficient.
bool sos_bits(int a[], int len, int k) {
	int sum;
	for(int mask=0; mask<(1<<len); mask++) { // mask will have bit pattern
		sum = 0;
		for(int i=0; i<len; i++) {  // check for all bit posotions in one of the patterns

			if(mask & (1<<i)) { // check if there is 1 and we can include this element
				sum = sum + a[i];
			}

			if(sum == k) {
				return true;
			}
		}
	}
	return false;
}

void main() {
	int a[] = {2, 6, 0, 7, 1, -5, 2, 6, -4};
	
	int len = sizeof(a)/sizeof(a[0]);

	//bool res = sos(a, len, 100, len-1);
	bool res = sos_bits(a, len, 8);
	if(res) {
		printf( "SOS exists");
	} else {
		printf( "SOS does not exist");
	}
}
