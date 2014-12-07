/*
http://community.topcoder.com/stat?c=problem_statement&pm=12604
*/

#include<stdio.h>

int minimalFatigue(int mgStrength[], int enemyStrength[], int enemyCount[], int len) {
	
	sort(mgStrength, 0, len);
	sort(enemyStrength, enemyCount, 0, len);

	int fatigue[len];
	
	memset(fatigue, 0, len*sizeof(int));

	// calculate the average

	for(int i=0, i<len; i++) {
		if(enemyCount[i] > 0) {
			enemies += enemyCount[i]; 
			total++;
		}
	}

	int avg = enemies/total;

	// get every MG to kill upto avg enemies if they could	
	for(int i=0, i<len; i++) {

		if(enemyStrength[i] <= mgStrength[j] && fatigue[i] < avg) {
			if(enemyCount[i] <= avg) {
				fatigue[i] +=enemyCount[i];
				enemyCount[i] = 0;
			} else {
				fatigue[i] +=(enemyCount[i] - avg);
				enemyCount[i] -= avg;
			}
		}
	}

	// let some magic girls share their extra energy left with others
	for(int i=0, i<len; i++) {
		if(fatigue[i] < avg) {
			for(int j=i; j<len; j++) {
				if(enemyStrength[j] > mgStrength[i] || fatigue[i] > avg) {
					break;
				}	
				enemyStrength[j]--;
				fatigue[i]++;
			}
			for(int j=i; j>=0; j--) {
				if(enemyStrength[j] > mgStrength[i] || fatigue[i] > avg) {
					break;
				}	
				enemyStrength[j]--;
				fatigue[i]++;
			}
		}
	}

	// now share the extra load among all equally

	
}


void main() {

	int mgStrength[] = {2, 3, 5};
	int enemyStrength[] = {1, 3, 4};
	int enemyCount[] = {2, 9, 4};

	int len = sizeof(enemyStrength)/sizeof(enemyStrength[0]);

	int res = minimalFatigue(mgStrength, enemyStrength, enemyCount); 
}
