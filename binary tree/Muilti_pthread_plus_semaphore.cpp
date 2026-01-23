#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define PRODUCE_COUNT 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;     // empty slots
sem_t full;      // filled slots
pthread_mutex_t mutex;

/* Producer thread */
void* producer(void* arg)
{
    for (int i = 1; i <= PRODUCE_COUNT; i++)
    {
        sem_wait(&empty);               // wait for empty slot
        pthread_mutex_lock(&mutex);     // lock buffer

        buffer[in] = i;
        printf("Producer produced: %d\n", i);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);                // signal filled slot

        sleep(1);
    }
    pthread_exit(NULL);
}

/* Consumer thread */
void* consumer(void* arg)
{
    for (int i = 1; i <= PRODUCE_COUNT; i++)
    {
        sem_wait(&full);                // wait for data
        pthread_mutex_lock(&mutex);     // lock buffer

        int item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);               // signal empty slot

        sleep(2);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t prod, cons;

    pthread_mutex_init(&mutex, NULL);

    sem_init(&empty, 0, BUFFER_SIZE);   // BUFFER_SIZE empty slots
    sem_init(&full, 0, 0);               // no filled slots

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    printf("Main thread exiting\n");
    return 0;
}
