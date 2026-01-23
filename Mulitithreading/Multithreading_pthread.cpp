#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void * tid)
{
	sleep(2);
	long* id=(long*) tid;
	printf("This is Thread %ld \n",*id);
	return NULL;
}

int main()
{
	pthread_t thread_id,thread_id1;
	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, myThreadFun, (void *)&thread_id);
	pthread_create(&thread_id1, NULL, myThreadFun, (void *)&thread_id1);
	pthread_join(thread_id, NULL);
	pthread_join(thread_id1, NULL);
	printf("After Thread\n");
	pthread_exit(NULL);
	//printf("After Thread\n");
	exit(0);
}
