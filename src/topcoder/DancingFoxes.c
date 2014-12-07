/*
http://community.topcoder.com/stat?c=problem_statement&pm=12548
*/

#include<stdio.h>
#include<limits.h>

#define min(a,b) (a<b)?a:b


int minimalDays(char *frndship[], int len) {

	int dist[len][len];
	
	// initialize dis array

	for(int i=0; i<len; i++) {
		for(int j=0; j<len; j++) {
			if(frndship[i][j] == 'Y') {
				dist[i][j] = 1;
			} else {
				dist[i][j] = INT_MAX;
			}
		}
	}

	// floyd-warshall

	for(int k=0; k<len; k++) {
		for(int i=0; i<len; i++) {
			for(int j=0; j<len; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}

	if(dist[0][1]>=INT_MAX) {
		return -1;
	}

	// other pairs are also dancing to help you !!
	int f[len+1];
	f[2] = 1;
	for(int t=3; t<=len; t++) {
		f[t] = f[t-t/3]+1;
	}
	return f[dist[0][1]];
}	

void main() {
	char *frndship[] = 
/*{"NNY",
 "NNY",
 "YYN"};
*/

{"NNYYNN",
 "NNNNYY",
 "YNNNYN",
 "YNNNNY",
 "NYYNNN",
 "NYNYNN"};

	int len= sizeof(frndship)/sizeof(frndship[0]);
	
	int res = minimalDays(frndship, len);
	printf("Min days required = %d", res);
}
