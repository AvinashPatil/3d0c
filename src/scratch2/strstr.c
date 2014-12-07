/*write a code to implement your own strstr */


/* Algorithm:

1. You are passed two strings haystack and needle
2. Start from first location of needle and try to match with haystack
3. If there is match move to next position of needle
4. save the first matched location of haystack
5. if there is a mismatch then start from first char of needle and next char of haystack
6. If there is a match return the first matched location.
7. If the haystack string ends then there exists not substring.


Improvement:
1. Keepa adv pointer so if there is not match and haystack has less characters than needle then we can skip the remaining comparisons.


*/

#include<stdio.h>
#include<stdlib.h>


char * strstr(char haystack[], char needle[]) {

	// validation
	if(haystack == NULL || needle == NULL) {
		return NULL;
	}

	char *adv = needle;
	int count = 0;
	while(*adv == '\0') {
		adv++;
		count++;
	};
	
	char *first = haystack;
	char *ph = haystack;
	char *pn = needle;

	adv = ph+count;

	//while(*ph != '\0') {
	while(*adv != '\0') {

		if(*ph == *pn) {
			ph++;
			pn++;
			adv++;
		} else {
			pn = needle;
			ph = first + 1;
			first = ph;
			adv = ph+count;
		}

		if(*pn == '\0') {
			return first;
		}
	}

	return NULL;
}

void main() {
	char haystack[] = "hi hello how are you";
	//char needle[] = "hello";
	//char needle[] = "helloa";
	char needle[] = "you";

	char *pos = strstr(haystack, needle);
	if (pos) {
		printf("There exists a substring\n");
	} else {
		printf("There is no substring\n");
	}
}


