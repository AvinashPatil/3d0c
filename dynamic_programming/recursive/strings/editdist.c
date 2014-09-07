/*
	Operatiosn: Insert, delete and Update
	Goal : In minimum operations convert str1 to str2.
*/

#include<stdio.h>
#include<string.h>

#define min(a,b) ((a<b)?a:b)

int minthree(int a, int b, int c) {
	return min(min(a,b),c);
}


int editdist_dp(char str1[], char str2[], int m, int n, int table [][n]) {

	// base cases

	if(m == 0) {
		return n;
	}
	if(n == 0) {
		return m;
	}	
	if(table[m][n] != 0) {
		return table[m][n];
	}
	int left = editdist_dp(str1, str2, m-1, n, table) + 1;  // deletion from first string
	int right = editdist_dp(str1, str2, m, n-1, table) + 1; // insert into fisrt string 
	int corner = editdist_dp(str1, str2, m-1, n-1, table) + (str1[m] == str2[n] ? 0 : 1); // no op or Update
	
	int res = minthree(left, right, corner);
	table[m][n] = res;
	return res;
} 


int editdist(char str1[], char str2[], int m, int n) {

	// base cases

	if(m == 0) {
		return n;
	}
	if(n == 0) {
		return m;
	}	
	int left = editdist(str1, str2, m-1, n) + 1;  // deletion from first string
	int right = editdist(str1, str2, m, n-1) + 1; // insert into fisrt string 
	int corner = editdist(str1, str2, m-1, n-1) + (str1[m] == str2[n] ? 0 : 1); // no op or Update
	
	return minthree(left, right, corner);
} 

void main() {
	char str1[] = "avinash";
	char str2[] = "ainash";

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int table[len1][len2];
	int res = editdist(str1, str2, len1-1, len2-1);
	//memset(table, 0, sizeof(table));
	//int res = editdist_dp(str1, str2, len1-1, len2-1, table);
	printf("Min edit dist is %d", res);

}
