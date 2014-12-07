#include<stdio.h>

void fizzbuzz() {
	for(int i=1; i<=100; i++) {
		if(i%3 ==0  || i%5 == 0) {
			if(i%3 == 0) {
				printf("Fizz");
			}
			if(i%5 == 0) {
				printf("Buzz");
			}
		} else {
				printf("%d", i);
		}
		printf("\n");
	}
}

void main() {

	fizzbuzz();
}
