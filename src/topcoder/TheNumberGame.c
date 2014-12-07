/*
http://community.topcoder.com/stat?c=problem_statement&pm=12474
*/

#include<stdio.h>
#include<stdbool.h>

int reverse(int a) {
	int temp = 0;
	//printf("a = %d ", a);
	while(a > 0) {
		temp = temp *10 + (a%10);
		a = a/10;
	}
	//printf("a' = %d\n ", temp);
	return temp;
}

bool determineOutcome(int a, int b, int step, int player) {

	if(a ==0 || b==0)
		return false;
	if(a == b) {
		//printf("Came here %d", a);
		return true;
	}
	if(step > 1000) {
		return false;
	} 
	if(player == 0) {
		if(determineOutcome(a/10, b, step+1, 1))
			return true;
		if(determineOutcome(reverse(a), b, step+1, 1))
			return true;
	} else {
		if(determineOutcome(a, b/10, step+1, 0))
			return true;
		if(determineOutcome(a, reverse(b), step+1, 0))
			return true;
	} 
	return false;
}	
void main() {

	if(determineOutcome(99, 123, 0, 0)) {
		printf("Win");
	} else {
		printf("Loose");
	}	
}
