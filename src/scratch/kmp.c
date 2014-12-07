#include<stdio.h>
#include<string.h>


void build_array(char pat[], int a[], int len) {
	int count = 0;
	a[0] = 0;

	for(int i=1; i<len; i++) {
		if(pat[i] == pat[count]) {
			count++;
		} else {
			count = 0;
		}
		a[i] = count;
	}
	return;
}

void kmp(char text[], char pat[], int p_len, int a[]) {
	int t_len = strlen(text);

	int j = 0;
	for(int i=0; i<t_len;) {
		if(text[i] == pat[j]) {
			j++;
		} else if (j != 0) {
			j = a[j-1];
			continue;
		}
		i++;
		if(j == p_len) {
			printf("Pattern found\n");
			return;
		}
	}
	printf("Pattern not found");
}

void print(int a[], int len) {
	for(int i=0; i<len; i++) {

		printf("%d ", a[i]);
	}
}
void main() {
	char text[] = "hello atratreya";
	char pat[] = "atratr";
	//char pat[] = "atratrz";
	int p_len = strlen(pat);

	int a[p_len];
	build_array(pat, a, p_len);
	print(a, p_len);
	kmp(text, pat, p_len, a);
}



