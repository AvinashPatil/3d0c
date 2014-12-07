
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#define EMPLOYEES 14
#define MAX_NAME_LEN 100


struct emp_info {
        int emp_id;
        char name[MAX_NAME_LEN];
        int rating;
        long salary;
        int reports;
};

struct ListNode {
	int dest;
	struct ListNode *next;
};

struct AdjList {
	struct Listnode *head;	
	struct emp_info emp;
};

struct Graph {
	int V;
	struct  AdjList *list;  // This is used as pointer to array of struct AdjList
};


