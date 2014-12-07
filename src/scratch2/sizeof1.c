#include<stdio.h>


median(int a[], int len) {
	printf("%d  %d", sizeof(a)/sizeof(a[0]), len);
}

main() {
    int a[] = {1, 2, 4, 6, 78, 8};
    //int b[] = {};
    int len = sizeof(a)/sizeof(a[0]);
    median(a, len);
}
