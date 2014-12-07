#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

bool toss(int x, int y) {
	int p = x+y;
	srand(time(0));
	if((rand()%p) < x) {
		return true;
	} else {
		return false;
	}
}

void box(int f_pills, int h_pills, int days) {
	// base case
	if(days == 0) {
		printf("%d %d\n", f_pills, h_pills);
		return;
	}

	if((f_pills >0 && toss(f_pills, h_pills)) || (h_pills > 0 && f_pills <=0)) {
		box(f_pills -1, h_pills+1, days-1);
	} else if(h_pills > 0) {
		box(f_pills, h_pills-1, days-1);
	}
}

void main() {
	
	box(12, 0, 5);

}
