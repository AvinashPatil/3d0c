/*
http://community.topcoder.com/stat?c=problem_statement&pm=12588
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int count(char containers[], int j, int L) {
	int res = 0;

	while(j<strlen(containers) &&  L>0) {
		if(containers[j] == 'X') {
			res++;
		}
		L--;
		j++;
	}
	printf(" for %d containers are %d \n", j, res );
	return res;	
}		
char * getContainerInfo(char  containers[], int cams[], int len, int L) {
	
		int n_containers = strlen(containers);
		bool result[n_containers][len];

		for(int i=0; i<len; i++) {// for each cam
			for(int j=0; j<n_containers; j++) {// for each container
				result[j][i] = false;
				if(cams[i] == count(containers, j, L)) {
					result[j][i] = true;
				}
			}
		}
		for(int i=0; i<len; i++) {// for each cam
			for(int j=0; j<n_containers; j++) {// for each container
				printf("%d ", result[j][i]?1:0);
			}
			printf("\n");
		}
	
	return "hi";
}

void main() {
	char containers[] = "-X--XX";
	int cams[] = {1, 2};
	int len = sizeof(cams)/ sizeof(cams[0]);	
	int L = 3;

	printf("%s", getContainerInfo(containers, cams, len, L));
}
