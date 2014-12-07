/* Find the max subsquare matrix which contains all 1s */

#include<stdio.h>
#include<limits.h>
#define ROW 6
#define COL 5
#define min(a,b) ((a<b)?a:b)


void print_max_subsquare(int a[ROW][COL]) {
	int s[ROW][COL];
	
	for(int i=0; i<ROW; i++) {
		s[i][0] = a[i][0];
	}

	for(int j=0; j<COL; j++) {
		s[0][j] = a[0][j];
	}

	int max = INT_MIN;
	int temp_i, temp_j;
	for(int i=1; i<ROW; i++) {
		for(int j=1; j<COL; j++) {
			if(a[i][j] == 1) {
				s[i][j] = min(min(s[i-1][j], s[i][j-1]), s[i-1][j-1]) +1;
			} else {
				s[i][j] = 0;
			}
			if(s[i][j] > max) {
				max = s[i][j];
				temp_i = i;
				temp_j = j;
			}
		}
	}
	printf("Max is %d\n", max);

	for(int i= temp_i-max +1; i<=temp_i; i++) {
		for(int j=temp_j-max +1; j<=temp_j; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void main() {
	int a[ROW][COL] = {{0, 1, 1, 0, 1},
                   {1, 1, 0, 1, 0},
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
	
	print_max_subsquare(a);
}
