// producer - consumer problem with semaphores
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t full, empty, mutex;

void Producer(void)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("Producer: Produced item %d\n", i);
        sem_post(&mutex);
        sem_post(&full);
    }
}

void Consumer(void)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        printf("Consumer: Consumed item %d\n", i);
        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main(int argc, char *argv[])
{
    pthread_t producer, consumer;
    sem_init(&full, 1, 1);
    sem_init(&empty, 1, 0);
    sem_init(&mutex, 1, 1);
    pthread_create(&producer, NULL, (void *)Producer, NULL);
    pthread_create(&consumer, NULL, (void *)Consumer, NULL);
    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
    sem_destroy(&full);
    sem_destroy(&empty);
    sem_destroy(&mutex);
    return 0;
}

