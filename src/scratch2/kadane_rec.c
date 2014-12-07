#include<stdio.h>
#include<limits.h>

int kadane(int a[], int end, int pos, int sum) {
    static int max_sum = INT_MIN;
    if(pos == end) {
	    return max_sum;
    }
    if(sum+a[pos] < 0) {
	    sum = 0;
    } else {
	    sum += a[pos];

    }   
    if(sum > max_sum)  {
	    max_sum = sum;
    }    
    return kadane(a, end, pos+1, sum);
}


void main() {
    //int a[] = {-1, 2, 3, -3, 4};

int a[] = {-6,2,-3,-4,-1,-5,-5};	
    int len = sizeof(a)/sizeof(a[0]);
    int res = kadane(a, len, 0, 0);
	printf("%d", res);
}
