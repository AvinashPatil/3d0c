/*
http://community.topcoder.com/stat?c=problem_statement&pm=12455
	
CORRECT
*/

#include<stdio.h>


int find(int n, int d, int first, int last) {
	for(int step = n-2; step>0;) {
		if(first < last) {
			first = first +d;
		} else {
			last = last +d;
		}
		step--;  
	}
	return (first>last?first:last);
}
void main() {
	int first = 2;
	int last = 4;
	int n = 3;
	int d =  5; 	

	int res = find(n, d, first, last);

	printf("Result is %d", res);
}

