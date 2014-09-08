#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define MAX_THREADS 100
#define NUM_THREADS 5
#define QUEUE_SIZE 100
#define NUM_JOBS 10
#define SLEEP_TIME 5
#define MAX_SLEEP_TIME 10


#define SUCCESS 1
#define ERROR -1
#define MEM_ERROR -2


struct task_item {
	void (*fun)(int); 
	int args;
	
};

struct task_q {
	int capacity;
	int cur_items;
	int head;
	int tail;
	struct task_item *item;
	pthread_mutex_t lock;
};

struct thread_pool {
	pthread_t threads[MAX_THREADS];
	int count;
	struct task_q *queue;
	bool shutdown;
};
