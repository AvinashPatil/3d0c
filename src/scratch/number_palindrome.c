#include<stdio.h>
#include<stdbool.h>


bool palin(int a) {
	int temp = 0;
	int b = a;

	while(b>0) {
		temp = (temp*10) + (b%10);
		b = b/10;
	}

	return (temp == a);
}

void main() {

	if(palin(123454321))
		printf("Its palindrome");
	else
		printf("Its not palindrome");
}
