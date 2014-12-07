#include<stdio.h>
#include<string.h>

void reverse(char str[], int start, int end) {
	while(start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = str[temp];			
		start++;
		end--;
	}
}

void encode(char str[], char out[], int len) {
	
	int cur_len = 1;
	int count = 0;	// out string index
	for(int i=1; i<len; i++) {
		if(str[i] == str[i-1]) {
			cur_len++;
		} else {
			if(cur_len > 1) {
				int start = 0;
				int end = 0;			
				while(cur_len > 0) {
					if(start == 0) {
						start = count+1;
					}
					out[count++] = (cur_len%10) + '0';
					cur_len /= 10;
				}
				end = count;
				reverse(out, start, end); // note that the digits would be in reverse order; get them straight
				out[count++] = 'x';
			}
			out[count++] = str[i-1];
			cur_len = 1;
		}
	}
	count++;	
	out[count] = '\0';
	printf("%s\n", out);
}

void main() {
	char str[] = "asbkkkkkkkk55vs";
	int len = strlen(str);
	char out[len];

	printf("%s\n", str);
	encode(str, out , len);
}

