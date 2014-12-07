/*
http://community.topcoder.com/stat?c=problem_statement&pm=12730

CORRECT
*/

#include<stdio.h>
#include<string.h>

int index;
void dfs(char *str, int visited[], int cur, int len, char *temp ) {

	if(visited[cur] == 0) {
		temp[index++] = str[cur];
		visited[cur] = 1;

		for(int i=0; i<len; i++) {
			if(str[cur] == str[i] || cur == len - i -1) {
				dfs(str, visited, i, len, temp);
			}
		}

	}
	return;
}	


int eval(char *temp) {
	int len = strlen(temp);
	int hit[256] = {0};
	for(int i=0; i<len; i++) {
		hit[temp[i]]++;
	}
	int max = 0;
	for(int i=0; i<len; i++) {
		if(hit[temp[i]] > max)
			max = hit[temp[i]];
	}

	return len - max;
}
int getMin(char *str) {

	int len = strlen(str);

	int visited[len]; 
	memset(visited, 0, sizeof(visited));
	int max = 0;
	char temp[len];
	for(int i=0; i<len; i++) {
		if(visited[i] != 1) {
			index = 0;
			dfs(str, visited, i, len, temp);
			temp[index] = '\0';
			//printf("%s\n", temp);
			max += eval(temp);
		}
	}

	return max;
}

void main() {

	int res= getMin("xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag");
	printf(" Min secs required %d", res);
}	


