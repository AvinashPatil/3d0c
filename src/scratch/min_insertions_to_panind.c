#include<stdio.h>
#include<string.h>
#define min(a,b) ((a<b)?a:b)


int min_inserts(char str[], int l, int h) {
	// base case
	if(l == h) {
		return 0;
	}

	if(l+1 == h) {
		if(str[l] == str[h])
			return 0;
		else return 1;
	}
	return (str[l] == str[h] ?
			min_inserts(str, l+1, h-1)
			: 1 + min(min_inserts(str, l+1, h), min_inserts(str, l, h-1)));
}

void main() {
	char str[] = "race";
	int len = strlen(str);

	printf("Min inserts required to make palind = %d", min_inserts(str, 0, len-1));
}

