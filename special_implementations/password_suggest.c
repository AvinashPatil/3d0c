/* Given a map of characters suggest all combinations of password */

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char replace(char c, char map[][2], int len) {
	for(int i=0; i<len; i++) {
		if(map[i][0] == c) {
			return map[i][1];
		}
	}
	return '\0';
}

bool contains(char c, char map[][2], int len) {
	for(int i=0; i<len; i++) {
		if(map[i][0] == c) {
			return true;
		}
	}
	return false;
}	

void suggest(char password[], char out[], int len, int pos, char map[][2], int map_len) {
	// base case
	if(len == pos) {
		out[len] = '\0';
		printf("%s \n", out);
		return;
	}
	out[pos] = password[pos];
	suggest(password, out, len, pos+1, map, map_len);

	if(contains(password[pos], map, map_len)) {
		out[pos] = replace(password[pos], map, map_len);
		suggest(password, out, len, pos+1, map, map_len);
	}
}

void main() {
	char password[] = "password";
	int len = strlen(password);
	char out[len];
	char map[3][2] = {{'a', '@'}, {'s', '$'}, {'o', '0'}};
	int map_len = sizeof(map)/sizeof(map[0]);
	suggest(password, out,  len, 0, map, map_len ); 
}

