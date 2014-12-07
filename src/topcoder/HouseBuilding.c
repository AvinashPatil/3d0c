/*
CORRECT SOLUTION!!
http://community.topcoder.com/stat?c=problem_statement&pm=12396
*/

#include<stdio.h>
#include<string.h>
#define min(a, b) a<b?a:b


int getMinimum(char *str[], int row, int col) {

	int sum = 0;
	int count = 0;
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			//printf("%c", str[i][j]);
			sum = sum + str[i][j] - '0';
			count++;
		}
	}

	int avg = sum/count;
	
	printf("%d \n", avg);
	int cost1 = 0;
	int cost2 = 0;

	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			int height = str[i][j] - '0';
			int diff1 = (height > avg) ? (height - (avg +1)) : (avg - height); 
			int diff2 = (height > avg -1) ? (height - avg) : (avg - 1  - height); 
			
			cost1 = cost1 + diff1;
			cost2 = cost2 + diff2; 
		}
	}
	
	printf("%d %d\n", cost1, cost2);
	return min(cost2, cost1);
	//return cost1;	
}

void main() {
	char *str[] = 
/*{"5781252",
 "2471255",
 "0000291",
 "1212489"};

	

{"54454",
 "61551"};
*/

 	{"5115307784486194059621489738352249846", "6590437464919347013936831318719407272"};
	int row = sizeof(str) / sizeof(str[0]);
	int col = strlen(str[0]);

	//printf(" %d  %d" , count, len);

	int res = getMinimum(str, row, col);

	printf("Cost is %d", res);
	
}
