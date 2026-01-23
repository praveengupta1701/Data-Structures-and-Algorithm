#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define PRODUCE_COUNT 10

int buffer[BUFFER_SIZE];
int count = 0;          // number of items in buffer
int in = 0;             // producer index
int out = 0;            // consumer index

pthread_mutex_t mutex;
pthread_cond_t not_full;
pthread_cond_t not_empty;

/* Producer thread function */
void* producer(void* arg)
{
    for (int i = 1; i <= PRODUCE_COUNT; i++)
    {
        pthread_mutex_lock(&mutex);

        /* Wait if buffer is full */
        while (count == BUFFER_SIZE)
        {
            pthread_cond_wait(&not_full, &mutex);
        }

        buffer[in] = i;
        printf("Producer produced: %d\n", i);

        in = (in + 1) % BUFFER_SIZE;
        count++;

        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    pthread_exit(NULL);
}

/* Consumer thread function */
void* consumer(void* arg)
{
    for (int i = 1; i <= PRODUCE_COUNT; i++)
    {
        pthread_mutex_lock(&mutex);

        /* Wait if buffer is empty */
        while (count == 0)
        {
            pthread_cond_wait(&not_empty, &mutex);
        }

        int item = buffer[out];
        printf("Consumer consumed: %d\n", item);

        out = (out + 1) % BUFFER_SIZE;
        count--;

        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);

        sleep(2);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t prod_thread, cons_thread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);

    printf("Main thread exiting\n");
    return 0;
}
