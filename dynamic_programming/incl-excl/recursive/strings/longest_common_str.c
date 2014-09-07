#include<stdio.h>
#include<string.h>


#define max(a,b) a>b?a:b
#define MAX 100



int longest_common_subseq(char str1[], char str2[], int pos1, int pos2, int len1, int len2, int table[][MAX]) {
	
	if(pos1>=len1 || pos2>=len2) {
		return 0;
	}

	if(table[pos1][pos2 ] != -1) {
		return table[pos1][pos2];
	}

	if(str1[pos1] == str2[pos2]) {
		table[pos1][pos2] =  1 + longest_common_subseq(str1, str2, pos1+1, pos2+1, len1, len2, table);
	} else {
	 	table[pos1][pos2] = max(longest_common_subseq(str1, str2, pos1+1, pos2, len1, len2, table),
		longest_common_subseq(str1, str2, pos1, pos2+1, len1, len2, table));
	}
	return table[pos1][pos2];

}

int longest = 0;
int longest_common_substr(char str1[], char str2[], int pos1, int pos2, int len1, int len2, int table[][MAX]) {
	
	if(pos1>=len1 || pos2>=len2) {
		return 0;
	}

	if(table[pos1][pos2 ] != -1) {
		return table[pos1][pos2];
	}

	if(str1[pos1] == str2[pos2]) {
		table[pos1][pos2] =  1 + longest_common_substr(str1, str2, pos1+1, pos2+1, len1, len2, table);
	} else {
		table[pos1][pos2] = 0;
	 	longest_common_substr(str1, str2, pos1+1, pos2, len1, len2, table);
		longest_common_substr(str1, str2, pos1, pos2+1, len1, len2, table);
	}

	// calculate the max
	for(int i = 0; i<MAX; i++) {
		for(int j = 0; j<MAX; j++) {
			if(table[i][j] > longest) {
				longest = table[i][j];
			}	
		}
	}
	return longest;
}


void main() {

	char str1[] = "iavinashrameshpatil";
	char str2[] = "helloavinashrpatlmdncv";

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int table[MAX][MAX];
	for(int i = 0; i<MAX; i++) {
		for(int j = 0; j<MAX; j++) {
			table[i][j] =-1;
		}
	}

	printf("longest common subseq length is %d", longest_common_subseq(str1, str2, 0, 0, len1, len2, table));

	for(int i = 0; i<MAX; i++) {
		for(int j = 0; j<MAX; j++) {
			table[i][j] =-1;
		}
	}

	printf("longest common substr length is %d", longest_common_substr(str1, str2, 0, 0, len1, len2, table));
}
