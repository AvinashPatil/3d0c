/* Program to countg number of words in file.

Maitain 2 states while counting : WORD and BALNK

Learnings :
1. check all the file io functions 
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define SIZE 5
#define WORD 1
#define BLANK 0

void main(){

	int fd = open("input.txt", O_RDONLY);

	if(fd== -1) {
		printf("Error\n");
		return;
	}	

	char buf[SIZE];
	memset(buf, 0, SIZE);	
	int nread;
	int state = WORD;
	int wc = 0;

	while(1) {
		nread = read(fd, buf, SIZE);

		if(nread == 0) {
			printf("End of file reached\n");
			break;
		}
		
		for(int i = 0; i< nread; i++) {
			if(buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\n') {
				state = BLANK;
			} else {
				if (state == BLANK) {
					wc++;
				}
				state = WORD;
			}
		}
	}

	close(fd);

	printf("Word count is %d", wc);

	return;
}
