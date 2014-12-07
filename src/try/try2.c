#include<stdio.h>


void fun(char a[]) {
	int res = sizeof(a)/sizeof(a[0]);
	printf("%d", res);
}

void main() {
	char a[] = "dsljfldfg";
	fun(a);

	int res = sizeof(a)/sizeof(a[0]);
	printf("%d", res);
}
