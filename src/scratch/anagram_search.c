/* Find all occurances of anagram of a string in another string
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define CHARS 256

bool compare(int t_count[], int p_count[]) {
	for(int i=0; i<CHARS; i++) {
		if(t_count[i] != p_count[i])
			return false;
	}
	return true;
}

void search(char text[], char pat[]) {

	int t_len = strlen(text);
	int p_len = strlen(pat);

	int p_count[CHARS] = {0};
	int t_count[CHARS] = {0};

	for(int i=0; i<p_len; i++) {
		t_count[pat[i]]++;
		p_count[text[i]]++;
	}
	int i;
	for(i=p_len; i<t_len; i++) {
		if(compare(t_count, p_count)) {
			printf("pattern found at %d\n", i-p_len);
		}
		
		p_count[text[i]]++;
		p_count[text[i-p_len]]--;
	}

	if(compare(t_count, p_count)) {
		printf("pattern found at %d\n", i-p_len);
	}
	
}

void main() {
	char text[] = "BACDGABCDA"; 
	char pat[] = "ABCD";

	search(text, pat);
}
