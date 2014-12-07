/*
http://community.topcoder.com/stat?c=problem_statement&pm=12860

CORRECT
*/

#include<stdio.h>
#include<limits.h>
#define min(a,b) a<b?a:b





int getacount(int apple[], int orange[], int len) {

	int min_c = INT_MAX;

	for(int i=0; i<len; i++) {
		min_c = min(min_c, apple[i]+orange[i]);
	}

	return min_c;
	
}

int get_max(int fruit[], int len, int X) {
	
	int sum = 0;

	for(int i=0; i<len;i++) {
		sum += min(fruit[i], X);
	}

	return sum;
}

int getNumber(int apple[], int orange[], int len) {

	// up to what number of fruits gifts are valid
	int X = getacount(apple, orange, len);

	int gifts = 0;

	for(int x=1; x<=X; x++) {

		// for this x
		// how many Max apples can be taken

		int mA =  0;
		for(int j=0; j<len; j++) {
		 	mA += min(apple[j], x);
		}

		// for this x
		// how many Max oranges can be taken
		int mO =  0;
		for(int j=0; j<len; j++) {
		 	mO += min(orange[j], x);
		}
		
		// NOw number of gifts for this X is all the apples range we can take
		// the oranges will come automatically
		// So its MaxApples - Min apples
		// Min apples means max oranges :-)

		gifts += mA - (len*x - mO) + 1; 
	}

	return gifts;
}

void main() {
	int apple[] = {7, 4, 5};
	int orange[] = {1, 10, 2};

	int len = sizeof(apple)/sizeof(apple[0]);

	int res = getNumber(apple, orange, len);
	printf("Max number of gifts = %d", res);

}
