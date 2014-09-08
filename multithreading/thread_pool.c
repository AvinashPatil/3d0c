#include "thread_pool.h"


void  sleep_secs(int time) {
	printf("\n Doing some work for %d seconds!\n", time);
	sleep(time);	
	return;
}

void * thread_func(void *arg) {

	struct thread_pool *pool = (struct thread_pool *)arg;

	struct task_item item;
	struct task_q *queue = pool->queue;
	while(true) {

		pthread_mutex_lock(&(queue->lock));

		if(queue->cur_items == 0) {
			// no items in queue
			// sleep for some random time and then try again.
			pthread_mutex_unlock(&(queue->lock));
			if(pool->shutdown == true) {
				// If we are shutting down and no items to consume
				// then exit from here.
				pthread_exit(NULL);
			}
			sleep(rand() % MAX_SLEEP_TIME);
			continue;
		}
		
		item.fun = queue->item[queue->head].fun;
		item.args= queue->item[queue->head].args;

		queue->head = (queue->head+1) % (queue->capacity);
		queue->cur_items--;
	
		if(item.fun == NULL) {
			// something not good with function pointer
			pthread_mutex_unlock(&(queue->lock));
			pthread_exit(NULL);
		} 

		// Do the the work
		(*(item.fun))(item.args);

		pthread_mutex_unlock(&(queue->lock));
		sleep(rand()%10);
	}
	return (void *) pool;
}

struct task_q * init_queue(int size, int *err) {

	struct task_q *queue = (struct task_q *) malloc(sizeof(struct task_q));
	if(NULL == queue) {
		*err = MEM_ERROR; 
		return NULL;
	}
	queue->capacity = size;
	queue->cur_items = 0;
	queue->item = (struct task_item *)malloc(sizeof(struct task_item )*size);
	if(NULL == queue->item) {
		*err = MEM_ERROR; 
		return NULL;
	}
	queue->head = queue->tail = 0;
	pthread_mutex_init(&(queue->lock), NULL);
	return queue;
}

struct thread_pool * init_pool(int num_threads, int queue_size, int *err) {
	struct thread_pool *pool = (struct thread_pool *) malloc(sizeof (struct thread_pool));	
	int i;
	if(NULL == pool) {
		*err = MEM_ERROR; 
		return NULL;
	}
	pool->count = 0;
	pool->shutdown = false;
	pool->queue = init_queue(queue_size, err);
	if(NULL == pool->queue) {
		return NULL;
	}
	// start the worker threads
	for(i=0; i<num_threads; i++) {
		if(0 != pthread_create(&(pool->threads[i]), NULL, thread_func, (void *) pool))  {
			*err = ERROR; 
			return NULL;
		}
	}
	
	return pool;
}


/* This function will enqueue the items.
 * The queue is protected by mutex lock.	
 */
int enqueue(struct thread_pool *pool, void (*fun)(int), int args, int *err) {
	
	struct task_q *queue = pool->queue;
	pthread_mutex_lock(&(queue->lock));

	if(queue->capacity == queue->cur_items) {
		pthread_mutex_unlock(&(queue->lock));
		*err = ERROR;
		return *err;
	}

	queue->item[queue->tail].fun = fun;
	queue->item[queue->tail].args= args;
	
	queue->tail = (queue->tail +1) % (queue->capacity);
	queue->cur_items++;
	printf("\nIn Enqueue Items %d \n", queue->cur_items);

	pthread_mutex_unlock(&(queue->lock));
	
	return SUCCESS;
}

void shutdown(struct thread_pool * pool) {
	pool->shutdown = true;
}

void main() {

	int num_threads = NUM_THREADS;
	int queue_size = QUEUE_SIZE;
	int time = SLEEP_TIME, i, err;

	
	struct thread_pool * pool = init_pool(num_threads, queue_size , &err);

	if(NULL == pool) {
		fprintf(stderr, "\nError while thread creation. Error code %d\n", err);
	}

	for(i=0; i<NUM_JOBS; i++) {	

		if(ERROR == enqueue(pool, &sleep_secs, time, &err)) {
			fprintf(stderr, "\n It seems queue is full. Error code %d\n", err);
			break;
		}
		time++;
	}
	// let the threads not exit before items get queued.
	sleep(SLEEP_TIME);
	
	// Now threads can exit if queue becomes empty.
	shutdown(pool);
	for(i=0; i<num_threads; i++) {
		if(pthread_join(pool->threads[i], NULL) != 0) {
			fprintf(stderr, "\nError while joining thread\n");
		}
	}
}
