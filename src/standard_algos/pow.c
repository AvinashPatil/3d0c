#include<stdio.h>

int power(int a, int b, int cache[]) {
	if(b <=0) {
		return 1;
	}
	if(cache[b] != 0) {
		printf("HIT\n");
		return cache[b];
	}
	if(b%2 ==0 ) {//b is even
		cache[b] = power(a, b/2, cache) * power(a, b/2, cache);
	} else {
		cache[b] = power(a, b/2, cache) * power(a, b/2, cache) * a;
	}
	printf("MISS\n");
	return cache[b];
}

void main() {
	int cache[100] = {0};
	printf("power is %d", power(2, 10, cache));
}
