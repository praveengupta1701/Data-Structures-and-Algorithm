#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void * tid)
{
	sleep(1);
	long* id=(long*) tid;
	printf("This is Thread %ld \n",*id);
	return NULL;
}

int main()
{
	pthread_t thread_id;
	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, myThreadFun, (void *)&thread_id);
	// pthread_join(thread_id, NULL);
	pthread_exit(NULL);
	printf("After Thread\n");
	exit(0);
}
