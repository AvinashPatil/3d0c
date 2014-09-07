#include<stdio.h>
#include<string.h>

#define max(a,b) a>b?a:b


int long_palind_subseq(char str[], int m, int n) {
	// base cases
	if(m == n) {
		return 1;
	}	
	if(m == n -1) {
		if(str[m] == str[n]) {
			return 2;
		} else {
			return 0;
		}
	}

	return (str[m] == str[n]) ? 2 + long_palind_subseq(str, m+1, n-1) : max(long_palind_subseq(str, m, n-1), long_palind_subseq(str, m+1, n));


}

int MAX = 0;
void long_palind_substr(char str[], int m, int n, int len) {
	// base cases
	if(m == n) {
		len++;
		if(MAX<len)
 			MAX = len;
		return ;
	}
	if(m == n -1) {
		if(str[m] == str[n]) {
			len = len +2;
			if(MAX<len)
 				MAX = len;
			
			return;
		} else {
			return;
		}
	}

	if(str[m] == str[n]) {
		len = len + 2;
		long_palind_substr(str, m+1, n-1, len);
	} else {
		long_palind_substr(str, m, n-1, 0); 
		long_palind_substr(str, m+1, n, 0);
	}
}



void main() {

	char str[] = "aqforgeeksxskeegforqa";
	char len = strlen(str);

	printf("Longest palindrom subsequence is : %d", long_palind_subseq(str, 0, len-1));
	//printf("Longest palindrom substr is : %d", long_palind_substr(str, 0, len-1));
	long_palind_substr(str, 0, len-1, 0);
	printf(" Longest palindrome substring is : %d", MAX);

}






